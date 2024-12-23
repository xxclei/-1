package 实验6;

import java.util.Scanner;

public class BankerClass {
    // 系统总进程数
    int pro_num;
    // 系统临界资源种数
    int os_num;
    // 定义可利用的资源量
    int[] Available;
    // 进程P的最大资源需求
    int[][] Max;
    // 进程P已分配的资源量
    int[][] Allocation;
    // 进程P尚需的资源量
    int[][] Need;
    // 进程P的资源请求
    int[][] Request;
    // 工作向量，记录当前可用资源
    int[] Work;

    // 设置已分配资源
    public void setAllocation() {
        Scanner in = new Scanner(System.in);
        System.out.println("请输入已分配的资源量：");
        for (int i = 0; i < pro_num; i++) {
            System.out.println("请输入进程P" + i + "的已分配资源量：");
            Allocation[i] = input(os_num);
        }
        // 重新计算当前资源余量和需求矩阵
        for (int j = 0; j < os_num; j++) {
            Available[j] = Available[j];
            for (int i = 0; i < pro_num; i++) {
                Available[j] -= Allocation[i][j];
            }
        }
        for (int i = 0; i < pro_num; i++) {
            for (int j = 0; j < os_num; j++) {
                Need[i][j] = Max[i][j] - Allocation[i][j];
            }
        }
    }

    // 设置最大资源需求
    public void setMax() {
        Scanner in = new Scanner(System.in);
        System.out.println("请输入各进程的最大资源需求：");
        for (int i = 0; i < pro_num; i++) {
            System.out.println("请输入进程P" + i + "的最大资源需求量：");
            Max[i] = input(os_num);
        }
    }

    // 输入资源的数量
    public int[] input(int n) {
        Scanner in = new Scanner(System.in);
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            result[i] = in.nextInt();
        }
        return result;
    }

    // 输出当前系统的资源状态
    public void printSystemVariables() {
        System.out.println("当前系统资源状态：");
        System.out.println("进程\tMax\tAllocation\tNeed\tAvailable");
        for (int i = 0; i < pro_num; i++) {
            System.out.print("P" + i + "\t");
            for (int j = 0; j < os_num; j++) {
                System.out.print(Max[i][j] + " ");
            }
            System.out.print("\t");
            for (int j = 0; j < os_num; j++) {
                System.out.print(Allocation[i][j] + " ");
            }
            System.out.print("\t");
            for (int j = 0; j < os_num; j++) {
                System.out.print(Need[i][j] + " ");
            }
            System.out.print("\t");
            if (i == 0) {
                for (int j = 0; j < os_num; j++) {
                    System.out.print(Available[j] + " ");
                }
            }
            System.out.println();
        }
    }

    // 设置资源请求
    public void setRequest() {
        Scanner in = new Scanner(System.in);
        System.out.println("请输入请求资源的进程编号：");
        int num = in.nextInt();
        if (num >= pro_num) {
            System.out.println("无此进程！");
        } else {
            System.out.println("请输入进程P" + num + "请求的各资源量：");
            Request[num] = input(os_num);
            BankerAlgorithm();
        }
    }

    // 执行银行家算法
    public void BankerAlgorithm() {
        if (isSafe()) {
            System.out.println("请求资源已分配，系统处于安全状态！");
        } else {
            System.out.println("请求资源失败，系统处于不安全状态！");
        }
    }

    // 安全性检查算法
    public boolean isSafe() {
        boolean[] Finish = new boolean[pro_num];
        int[] safe = new int[pro_num];
        int count = 0;

        // 复制Available到Work
        System.arraycopy(Available, 0, Work, 0, os_num);

        while (count < pro_num) {
            boolean progressMade = false;
            for (int i = 0; i < pro_num; i++) {
                if (!Finish[i] && canAllocate(i)) {
                    for (int j = 0; j < os_num; j++) {
                        Work[j] += Allocation[i][j];
                    }
                    Finish[i] = true;
                    safe[count] = i;
                    count++;
                    progressMade = true;
                }
            }

            if (!progressMade) {
                System.out.println("系统没有安全序列，当前无法满足请求。");
                return false;
            }
        }

        System.out.println("系统处于安全状态，安全序列为：");
        for (int i = 0; i < count; i++) {
            System.out.print("P" + safe[i] + " ");
        }
        System.out.println();
        return true;
    }

    // 判断是否可以分配资源
    public boolean canAllocate(int i) {
        for (int j = 0; j < os_num; j++) {
            if (Need[i][j] > Work[j]) {
                return false;
            }
        }
        return true;
    }

    // 主程序入口
    public static void main(String[] args) {
        BankerClass banker = new BankerClass();
        Scanner in = new Scanner(System.in);
        System.out.println("请输入进程数：");
        banker.pro_num = in.nextInt();
        System.out.println("请输入资源种类数：");
        banker.os_num = in.nextInt();

        banker.Available = new int[banker.os_num];
        banker.Max = new int[banker.pro_num][banker.os_num];
        banker.Allocation = new int[banker.pro_num][banker.os_num];
        banker.Need = new int[banker.pro_num][banker.os_num];
        banker.Request = new int[banker.pro_num][banker.os_num];
        banker.Work = new int[banker.os_num];

        // 输入初始资源和最大资源需求
        banker.setMax();
        banker.setAllocation();
        banker.printSystemVariables();
        banker.setRequest();
    }
}

