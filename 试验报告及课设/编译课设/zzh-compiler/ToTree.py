import matplotlib.pyplot as plt
from graphviz import Digraph
import os


# 定义一个空字典，后续可能用于存储某种数据结构（从代码整体看可能和构建树结构相关的数据）
d1 = {}
# 初始化一个字符串变量，用于在构建树结构等操作中作为节点的标识等用途，初始值为"0"
root = "0"


def run():
    def plot_model(tree, name):
        """
        函数功能：根据给定的树结构数据和名称，构建并展示一个可视化的图形（可能是语法树之类的树状结构图形）。

        参数：
        - tree：表示树结构的数据，通常是嵌套的字典形式，用于描述节点和节点之间的关系等信息。
        - name：指定生成图形的文件名（不含后缀），后续用于保存和展示图形时的命名。

        返回值：无，但会生成相应的图形并保存到指定路径（通过调用g.render()）。
        """
        g = Digraph("G", filename=name, format='png', strict=False)
        try:
            # 尝试获取树结构中根节点（字典的第一个键对应的节点，这里假设树结构以字典形式表示）的标签
            first_label = list(tree.keys())[0]
        except:
            # 如果出现异常（比如树为空等情况），则直接返回，不进行后续图形构建操作
            return
        g.node("0", first_label)
        _sub_plot(g, tree, "0")
        g.render(engine='dot', view=False, cleanup=True, outfile=os.path.join('./output/', name + '.png'))

    def _sub_plot(g, tree, inc):
        """
        函数功能：递归地构建图形的子节点和边，用于完善整个树状图形的结构。

        参数：
        - g：Digraph对象，代表正在构建的图形。
        - tree：表示树结构的数据，和plot_model函数中的tree类似，用于描述节点关系等信息。
        - inc：代表当前节点的标识（字符串形式），用于构建边时确定起始节点。

        返回值：无，但会在递归调用过程中不断向图形对象g中添加节点和边，完善图形结构。
        """
        global root
        # 获取树结构中当前节点（由传入的tree参数决定）对应的第一个子节点的标签
        first_label = list(tree.keys())[0]
        ts = tree[first_label]
        for i in ts.keys():
            if isinstance(tree[first_label][i], dict):
                root = str(int(root) + 1)
                sub_node_label = list(tree[first_label][i].keys())[0]
                # 处理子节点标签为空串（用'_EMPTY_'标记）或者是'ε'表示空串的情况，统一设置显示为'ε'（可根据实际需求调整显示样式）
                if sub_node_label == '_EMPTY_' or sub_node_label == 'ε':
                    sub_node_label = 'ε'
                g.node(root, sub_node_label)
                g.edge(inc, root, str(i))
                _sub_plot(g, tree[first_label][i], root)
            else:
                root = str(int(root) + 1)
                leaf_label = tree[first_label][i]
                # 同样处理叶节点标签为空串或'ε'的情况
                if leaf_label == '_EMPTY_' or leaf_label == 'ε':
                    leaf_label = 'ε'
                g.node(root, leaf_label)
                g.edge(inc, root, str(i))

    with open('./output/tree.txt', 'r', encoding='utf-8') as f:
        info = f.read().splitlines()

        while True:
            try:
                info.remove('')
            except:
                break

        n = len(info) - 1

        try:
            parts = info[n].split(' --> ')
            if len(parts) == 2:
                x, b = parts
            else:
                # 如果分割后不是两部分（可能有空串情况），做相应处理，这里假设用特殊符号'_EMPTY_'表示空串情况
                x = parts[0] if parts else '000'
                b = '_EMPTY_'
        except:
            x = '000'
            b = '_EMPTY_'

        def have(idx, node):
            """
            函数功能：判断在给定索引范围（从idx - 1往前到0）内，是否存在节点与传入的node相等，用于查找节点是否存在于前面的信息中。

            参数：
            - idx：起始索引，从这个索引往前查找。
            - node：要查找的节点名称（字符串形式）。

            返回值：如果找到匹配的节点则返回True，否则返回False。
            """
            for i in range(idx - 1, -1, -1):
                tt = info[i]
                try:
                    a, b = tt.split(' --> ')
                except:
                    continue
                if a == node:
                    return True
            return False

        vis = [0 for i in range(len(info))]

        def dfs(idx, node):
            """
            函数功能：深度优先搜索函数，用于从给定索引和节点开始，递归地构建树结构相关的数据（以字典形式表示）。

            参数：
            - idx：当前搜索的索引位置，用于在info列表中定位信息。
            - node：当前搜索的节点名称（字符串形式）。

            返回值：根据搜索情况返回构建好的树结构部分数据（字典形式），或者继续递归调用返回其他相关结果。
            """
            if idx == -1:
                return node
            if vis[idx]:
                return dfs(idx - 1, node)
            try:
                a, b = info[idx].split(' --> ')
            except:
                return dfs(idx - 1, node)
            di = {}
            if a == node:
                vis[idx] = 1
                bb = b.split()
                for i in range(len(bb) - 1, -1, -1):
                    di[i] = dfs(idx - 1, bb[i])
                di = dict(
                    sorted(di.items(), key=lambda d: d[0], reverse=False))
                return {node: di}
            else:
                return dfs(idx - 1, node)

        d1 = dfs(n, x)

    # 调用plot_model函数，传入构建好的树结构数据d1和名称'grammar_tree'，用于生成并保存对应的图形
    plot_model(d1, 'grammar_tree')


if __name__ == '__main__':
    run()
    print("successfully save grammar_tree.png")