package 实验5;

import java.util.ArrayList;
import java.util.List;


public class Main {
    public static int SUMSIZE = 512; // 内存总大小
    public static List<Mode> testList = new ArrayList<Mode>(); // 内存分配情况
    public static List<Mode> freeList = new ArrayList<Mode>(); // 空闲分区

    static int[] arrayNeed = {1300, 1100, 300, 1150, 1030, 1040, 1060, 30};

    public static void main(String[] args) {
        // 初始化空闲分区列
        Mode mode = new Mode(1, SUMSIZE, 0);
        freeList.add(mode);

        Root test = new FF();
        test = new MF();

        // 初始状态
        System.out.println("================ 初始化状态 ================");
        myPrint();

        for (int i = 0; i < arrayNeed.length; i++) {
            // 申请内存
            if (arrayNeed[i] > 1000) {
                System.out.println("================ 分配 " + (arrayNeed[i] - 1000) + " ==================");
                test.request(testList, freeList, arrayNeed[i] - 1000);
            } else { 
                // 释放内存
                System.out.println("================ 释放 " + arrayNeed[i] + " ==================");
                test.release(testList, freeList, arrayNeed[i]);
            }
            myPrint();
        }
    }

    public static void myPrint() {
        System.out.println();
        System.out.println("********* 空闲分区 *********");
        System.out.println();
        System.out.println("| 起始地址 | 大小 |");
        for (Mode tempMode : freeList) {
            System.out.printf("|%5d%5d|\n", tempMode.getStartId(), tempMode.getSize());
        }
        System.out.println();

        System.out.println("********** 已分配分区 *********");
        System.out.println();
        System.out.println("| 起始地址 | 大小 |");
        for (Mode tempMode : testList) {
            System.out.printf("|%5d%5d|\n", tempMode.getStartId(), tempMode.getSize());
        }
        System.out.println();
    }
}
