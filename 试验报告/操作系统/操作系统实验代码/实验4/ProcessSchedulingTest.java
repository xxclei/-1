package 实验4;

import java.util.Comparator;
import java.util.PriorityQueue;

public class ProcessSchedulingTest { // 这是一个测试类

    public static int nowtime = 0; // 初始化当前时间

    // 定义 PCB 比较器，按照优先级从高到低进行排序
    public static Comparator<PCB> pcbs = new Comparator<PCB>() {
        @Override
        public int compare(PCB o1, PCB o2) {
            return o2.getPriority() - o1.getPriority(); // 按优先级从高到低排序
        }
    };

    public static void main(String[] args) throws InterruptedException {
        // 创建一个容量为 5 的优先队列，并使用上面定义的比较器
        PriorityQueue<PCB> queue = new PriorityQueue<PCB>(5, pcbs);

        // 启动生产和消费进程
        Thread thread = new Thread(new PCBRunnable(queue));
        thread.start();
        thread.join();
        
        new Thread(new PCBRun(queue)).start();
    }
}
