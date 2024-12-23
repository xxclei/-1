    package 实验5;

    import java.util.List;

    public class MF implements Root {
        @Override
        public List<Mode> request(List<Mode> inputList, List<Mode> freeList, int requestSize) {
            Mode minFreeMode = new Mode(0, 1000, 0);
            boolean sign = false;

            // 查找空闲分区队列，满足条件最小的内存
            for (Mode freeMode : freeList) {
                if (freeMode.getSize() > requestSize && freeMode.getSize() < minFreeMode.getSize()) {
                    minFreeMode = freeMode;
                    sign = true;
                }
            }

            if (!sign) {
                System.out.println("未找到合适的空闲分区, 无法分配!");
                return null;
            }

            // 更新空闲分区队列
            Mode tempMode1 = new Mode(
                minFreeMode.getNum(),
                minFreeMode.getSize() - requestSize,
                minFreeMode.getStartId() + requestSize
            );
            freeList.remove(minFreeMode);
            freeList.add(tempMode1);

            // 更新分配情况
            Mode tempMode2 = new Mode(inputList.size() + 1, requestSize, minFreeMode.getStartId());
            inputList.add(tempMode2);

            // 更新主函数里的静态变量
            Main.freeList = freeList;
            Main.testList = inputList;

            return null;
        }

        @Override
        public List<Mode> release(List<Mode> inputList, List<Mode> freeList, int releaseSize) {
            // 两次释放算法一样，直接调用另一个即可
            FF test = new FF();
            test.release(inputList, freeList, releaseSize);
            return null;
        }
    }
