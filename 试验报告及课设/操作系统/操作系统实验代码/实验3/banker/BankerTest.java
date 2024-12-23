package banker;


import java.util.Scanner;

public class BankerTest {
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
