package 实验4;
import java.util.PriorityQueue;
import java.util.Comparator;

// 进程控制块 (PCB) 类
class PCB {
    private String name;
    private int requiredTime;
    private int priority;
    private String state;

    // 构造方法
    public PCB(String name, int requiredTime, int priority, String state) {
        this.name = name;
        this.requiredTime = requiredTime;
        this.priority = priority;
        this.state = state;
    }

    // Getter 方法
    public String getName() {
        return name;
    }

    public int getRequiredTime() {
        return requiredTime;
    }

    public int getPriority() {
        return priority;
    }

    public String getState() {
        return state;
    }

    // Setter 方法
    public void setState(String state) {
        this.state = state;
    }

    @Override
    public String toString() {
        return String.format("进程名: %s | 剩余时间: %d | 优先级: %d | 状态: %s", name, requiredTime, priority, state);
    }
}

// 进程调度的 Runnable 类
public class PCBRunnable implements Runnable {
    private PriorityQueue<PCB> queue;

    // 构造方法，传入优先级队列
    public PCBRunnable(PriorityQueue<PCB> queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        System.out.println("操作系统实验四 -- 进程调度");

        // 创建进程并将其加入队列
        PCB p1 = new PCB("P1", 2, 1, "Ready");
        PCB p2 = new PCB("P2", 3, 10, "Ready");
        PCB p3 = new PCB("P3", 1, 6, "Ready");
        PCB p4 = new PCB("P4", 2, 9, "Ready");
        PCB p5 = new PCB("P5", 4, 4, "Ready");

        queue.add(p1);
        System.out.println(p1.getName() + " 开始排队...");

        queue.add(p2);
        System.out.println(p2.getName() + " 开始排队...");

        queue.add(p3);
        System.out.println(p3.getName() + " 开始排队...");

        queue.add(p4);
        System.out.println(p4.getName() + " 开始排队...");

        queue.add(p5);
        System.out.println(p5.getName() + " 开始排队...");

        System.out.println("现在时间是: " + System.currentTimeMillis()); // 需要用实际的系统时间代替
        System.out.println("进程名 | 剩余时间 | 优先级 | 状态");

        // 模拟进程的运行（可以根据需要添加逻辑）
        while (!queue.isEmpty()) {
            PCB current = queue.poll(); // 从队列中取出优先级最高的进程
            System.out.println(current.toString());
            current.setState("Running"); // 将状态设置为 "运行中"
            try {
                Thread.sleep(1000); // 模拟运行时间
            } catch (InterruptedException e) {
                System.out.println("线程中断: " + e.getMessage());
            }
            current.setState("Finished");
            System.out.println(current.getName() + " 已完成！");
        }
    }

    // 主程序入口
    public static void main(String[] args) {
        // 定义进程队列，优先级从高到低排序（优先级数值小的优先）
        PriorityQueue<PCB> queue = new PriorityQueue<>(Comparator.comparingInt(PCB::getPriority));

        // 启动 PCBRunnable 线程
        PCBRunnable pcbRunnable = new PCBRunnable(queue);
        Thread thread = new Thread(pcbRunnable);
        thread.start();
    }
}
