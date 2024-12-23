
package banker;
import java.util.Scanner;
public class Banker {
    int available[] = new int[]{3, 3, 2}; // 可得到的资源
    int max[][] = new int[][]{
            {7, 5, 3}, 
            {3, 2, 2}, 
            {9, 0, 2}, 
            {2, 2, 2}, 
            {4, 3, 3}
    }; // 每个进程最大资源数
    int allocation[][] = new int[][]{
            {0, 1, 0}, 
            {2, 0, 0}, 
            {3, 0, 2}, 
            {2, 1, 1}, 
            {0, 0, 2}
    }; // 每个进程目前拥有的资源数
    int need[][] = new int[][]{
            {7, 4, 3}, 
            {1, 2, 2}, 
            {6, 0, 0}, 
            {0, 1, 1}, 
            {4, 3, 1}
    }; // 每个进程需要的资源数

    void showData() { // 展示数据输出每个进程的相关数据
        System.out.println("进程号\tMax\t\tAllocation\t\tNeed");
        System.out.println("A B C\tA B C\tA B C");
        for (int i = 0; i < 5; i++) {
            System.out.print(i + "\t");
            for (int m = 0; m < 3; m++) 
                System.out.print(max[i][m] + " ");
            System.out.print("\t");
            for (int m = 0; m < 3; m++) 
                System.out.print(allocation[i][m] + " ");
            System.out.print("\t");
            for (int m = 0; m < 3; m++) 
                System.out.print(need[i][m] + " ");
            System.out.println();
        }
    }

    boolean change(int requestNum, int request[]) { 
        if (!(request[0] <= need[requestNum][0] && request[1] <= need[requestNum][1] && request[2] <= need[requestNum][2])) {
            System.out.println("请求的资源数超过了所需要的最大值，分配错误");
            return false;
        }
        if (!(request[0] <= available[0] && request[1] <= available[1] && request[2] <= available[2])) {
            System.out.println("尚无足够资源分配，必须等待");
            return false;
        }
        for (int i = 0; i < 3; i++) { 
            available[i] -= request[i];
            allocation[requestNum][i] += request[i];
            need[requestNum][i] -= request[i];
        }
        boolean flag = checkSafe(available[0], available[1], available[2]); 
        if (flag) {
            System.out.println("能够安全分配");
            return true;
        } else {
            System.out.println("不能够安全分配");
            for (int i = 0; i < 3; i++) {
                available[i] += request[i];
                allocation[requestNum][i] -= request[i];
                need[requestNum][i] += request[i];
            }
            return false;
        }
    }

    boolean checkSafe(int a, int b, int c) { // 安全算法检查
        int work[] = new int[3];
        work[0] = a;
        work[1] = b;
        work[2] = c;
        boolean finish[] = new boolean[5];
        int i = 0;
        while (i < 5) { 
            if (!finish[i] && need[i][0] <= work[0] && need[i][1] <= work[1] && need[i][2] <= work[2]) {
                for (int m = 0; m < 3; m++) 
                    work[m] += allocation[i][m];
                finish[i] = true;
                i = 0;
            } else {
                i++;
            }
        }
        for (i = 0; i < 5; i++) 
            if (!finish[i]) 
                return false;
        return true;
    }

    public static void main(String[] args) {
        Banker bank = new Banker();
        bank.showData();
        int request[] = new int[3];
        int requestNum;
        String source[] = new String[]{"A", "B", "C"};
        Scanner s = new Scanner(System.in);
        String choice;
        while (true) {
            System.out.println("请输入要请求的进程号(0--4):");
            requestNum = s.nextInt();
            System.out.println("请输入请求的资源数目");
            for (int i = 0; i < 3; i++) {
                System.out.print(source[i] + "资源的数目: ");
                request[i] = s.nextInt();
            }
            bank.change(requestNum, request);
            System.out.println("是否再请求分配(y/n)");
            choice = s.next();
            if (choice.equals("n")) break;
        }
        s.close();
    }
}
