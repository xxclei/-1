import java.util.*;

public class FIFO {
    private static final int PRO_MEMORY = 5; // 系统分配的内存块数
    private static Page[] pages = new Page[PRO_MEMORY];
    private static int countOldPoint = 0; // 记录最久的页面下标
    private static int count = 0; // 记录当前在使用的总页面数
    private static int lackTime = 0; // 缺页次数
    private List<Integer> usePageNumList = new ArrayList<>(); // 页面使用列表

    public static void main(String[] args) {
        System.out.println("--------先进先出算法------------");
        FIFO fifo = new FIFO();
        fifo.init();
        fifo.input();
        fifo.running();
    }

    // 初始化内存页
    public void init() {
        for (int i = 0; i < pages.length; i++) {
            pages[i] = new Page();
        }
    }

    // 接收用户输入列表
    public void input() {
        System.out.print("请输入页面使用列表，以空格分开: ");
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        String[] inputList = input.split("\\s+");
        try {
            for (String in : inputList) {
                usePageNumList.add(Integer.valueOf(in));
            }
        } catch (Exception e) {
            System.out.println("输入的必须是数字，请重新开始!!!");
            System.exit(0);
        }
    }

    // 系统运行
    public void running() {
        Iterator<Integer> it = usePageNumList.iterator();
        while (it.hasNext()) {
            countOldPoint = countOldPoint % PRO_MEMORY;
            int inPageId = it.next();

            // 查找内存中是否有该页面
            if (search(inPageId)) {
                System.out.println("内存中有ID为 " + inPageId + " 的页面，不进行替换");
            } else if (count < PRO_MEMORY) {
                // 有空闲内存页
                pages[count].setId(inPageId);
                System.out.println("页号ID: " + pages[count].getId() + " 正在放入内存");
                count++;
            } else {
                // 替换页面
                replace(inPageId);
                lackTime++;
                countOldPoint++;
            }
            display();
        }
        System.out.println("缺页次数为: " + lackTime + ", 缺页率是: " + (float) lackTime / usePageNumList.size());
    }

    // 查找内存中是否有该页面
    public boolean search(int pageId) {
        for (Page page : pages) {
            if (page.getId() == pageId) {
                return true;
            }
        }
        return false;
    }

    // 替换算法
    public void replace(int pageId) {
        int outPageId = pages[countOldPoint].getId();
        pages[countOldPoint].setId(pageId);
        System.out.println("页号ID: " + pageId + " 正在放入内存，页号ID: " + outPageId + " 被替换出去");
    }

    // 显示当前内存页
    public void display() {
        System.out.print("当前内存保留的页数是: ");
        for (Page page : pages) {
            System.out.print(page.getId() + " ");
        }
        System.out.println();
    }
}

class Page {
    private int id = -1;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
}
