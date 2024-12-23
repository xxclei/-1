package 实验6;

import java.util.Scanner;

public class TestBankerClass {
    public static int pro; // Number of processes
    public static int os;  // Number of system resources
    
    public static void main(String[] args) {
        Scanner main_in = new Scanner(System.in);
        
        // Initialize system resources
        System.out.print("配置系统资源种类数: ");
        os = main_in.nextInt();
        
        System.out.print("配置系统进程数: ");
        pro = main_in.nextInt();
        
        BankerClass T = new BankerClass(); // Assuming BankerClass exists and has a constructor
        
        // Loop to keep running until user exits
        while (true) {
            T.setRequest(); // Assuming setRequest() is a method in BankerClass
            
            System.out.println("您是否还要进行请求: y/n?");
            boolean flag = true;
            
            while (flag) {
                String s = main_in.next(); // Take input
                if (s.equals("n")) {
                    System.out.println("感谢使用!");
                    System.exit(0); // Exit the program
                } else if (s.equals("y")) {
                    flag = false; // Stop the loop if user selects 'y'
                } else {
                    System.out.println("输入不规范!"); // Handle invalid input
                }
            }
        }
    }
    
    // Assuming this is the method for input processing, fixing some issues
    public static int[] Ginput(int num) {
        int[] putnum = new int[num]; // Final array to output
        Scanner main_in = new Scanner(System.in);
        
        String s = main_in.nextLine(); // Read the full line as input
        char[] after = s.toCharArray(); // Convert to character array
        
        int[] cache = { 0, 0 }; // For tracking positions
        for (int i = 0; i < s.length(); i++) {
            if (cache[1] > num) { // Check if input is long enough
                break;
            }
            if (after[i] >= '0' && after[i] <= '9') { // ASCII check for digits
                cache[1]++;
                putnum[cache[0]] = (int) (after[i] - '0'); // Convert char to int
            }
        }
        return putnum; // Return the valid extracted array
    }
}
