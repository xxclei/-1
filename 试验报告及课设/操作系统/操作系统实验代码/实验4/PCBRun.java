package 实验4;
import java.util.PriorityQueue;


public class PCBRun implements Runnable { 

    // PCB具体的操作，执行进程，修改进程优先级之类的
    private PriorityQueue<PCB> queue;

    public PCBRun(PriorityQueue<PCB> queue) {
        this.queue = queue;
    }

    @Override
    public void run() { 
        for (PCB e : queue) {
            System.out.println(e.toString());
        }
        while (!queue.isEmpty()) { 
            System.out.println("现在时间是:" + ProcessSchedulingTest.nowtime);
            System.out.println("进程名          剩余时间        状态            优先级");

            PCB take = queue.poll();

            if (take.getState().equals("Ready")) {
                take.setState("Writing");
                System.out.println(take.toString());

                try {
                    for (PCB e : queue) {
                        System.out.println(e.toString());
                    }
                    Thread.sleep(1000); 
                    ProcessSchedulingTest.nowtime++;

                    // 修改进程仍需时间
                    take.setDuringTime(take.getDuringTime() - 1);

                    // 修改进程优先级
                    if (take.getPriority() > 1)
                        take.setPriority(take.getPriority() / 2);
                    else if (take.getPriority() == 1)
                        take.setPriority(1);

                    // 修改进程状态
                    if (take.getDuringTime() > 0)
                        take.setState("Ready");
                    else {
                        take.setState("Final");
                        take.setPriority(0);
                    }

                    // 进程进入队列
                    queue.add(take);

                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            } else {
                queue.add(take);
                for (PCB e : queue) {
                    System.out.println(e.toString());
                }
                break;
            }
        }
    }
}


