package 实验5;
public class Mode {
    private int num;
    private int size; // 区号大小
    private int startId; // 起始

    public Mode() {
        // 默认构造函数，您可以在此处初始化成员变量，或者保持空构造函数
    }

    public Mode(int num, int size, int startId) {
        this.num = num;
        this.size = size;
        this.startId = startId;
    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }

    public int getSize() { 
        return size;
    }

    public void setSize(int size) { 
        this.size = size;
    }

    public int getStartId() { 
        return startId;
    }

    public void setStartId(int startId) {
        this.startId = startId;
    }
}
