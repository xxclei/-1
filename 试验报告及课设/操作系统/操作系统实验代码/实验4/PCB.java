package 实验4;

public class PCB { 
    // PCB 属性
    private String name;         // 进程名
    private int duringTime;      // 持续时间
    private int priority;        // 优先级
    private String state;        // 进程状态

    // 构造方法
    public PCB(String name, int duringTime, int priority, String state) {
        this.name = name;
        this.duringTime = duringTime;
        this.priority = priority;
        this.state = state;
    }

    // 重写 toString() 方法，显示 PCB 信息
    @Override
    public String toString() {
        return getName() + "\t\t" + getDuringTime() + "\t\t" + getState() + "\t\t" + getPriority();
    }

    // setter 和 getter 方法
    public void setDuringTime(int duringTime) {
        this.duringTime = duringTime;
    }

    public void setPriority(int priority) {
        this.priority = priority;
    }

    public void setState(String state) {
        this.state = state;
    }

    public String getName() {
        return name;
    }

    public int getDuringTime() {
        return duringTime;
    }

    public int getPriority() {
        return priority;
    }

    public String getState() {
        return state;
    }
}
