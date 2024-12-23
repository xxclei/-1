import java.awt.GridLayout;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.MenuItem; // 修正import语句
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

class Monitor {
    public int philStates[] = new int[5];
    public boolean chopsticks[] = new boolean[5];
    public deadlock dp;

    public Monitor(deadlock dp) {
        this.dp = dp; // 修正赋值语句
        for (int i = 0; i < 5; i++) {
            philStates[i] = 0; // 修正变量名
            chopsticks[i] = false;
        }
    }

    public synchronized void pickupL(int i) {
        while (chopsticks[i]) {
            try {
                wait();
            } catch (InterruptedException e) {}
        }
        chopsticks[i] = true;
        philStates[i] = 1; // 修正变量名
        dp.jl[i].setIcon(dp.pic[philStates[i]]);
        dp.jl[i].setText("hungry..");
    }

    public synchronized void pickupR(int i) {
        while (chopsticks[(i + 1) % 5]) {
            try {
                wait();
            } catch (InterruptedException e) {}
        }
        chopsticks[(i + 1) % 5] = true; // 修正变量名
        philStates[i] = 2; // 修正变量名
        dp.jl[i].setIcon(dp.pic[philStates[i]]);
        dp.jl[i].setText("eating..");
    }

    public synchronized void putdown(int i) {
        chopsticks[i] = false;
        chopsticks[(i + 1) % 5] = false;
        philStates[i] = 0; // 修正变量名
        dp.jl[i].setIcon(dp.pic[philStates[i]]);
        dp.jl[i].setText("thinking..");
        notify();
    }
}

public class deadlock extends JFrame {
    public JLabel jl[] = new JLabel[5];
    public String name[] = {"philosopher_1", "philosopher_2", "philosopher_3", "philosopher_4", "philosopher_5"}; // 修正字符串数组的初始化
    public ImageIcon pic[] = new ImageIcon[3];
    public Monitor m;
    public philosopher phil[];

    public deadlock() {
        super("Diner Philosopher Fengfan");
        pic[0] = new ImageIcon(getClass().getResource("pic/sikao.jpg"));
        pic[1] = new ImageIcon(getClass().getResource("pic/jie.jpg"));
        pic[2] = new ImageIcon(getClass().getResource("pic/chifan.jpg"));

        for (int i = 0; i < 5; i++) {
            jl[i] = new JLabel(name[i], pic[0], JLabel.CENTER);
            jl[i].setVerticalTextPosition(JLabel.BOTTOM);
            jl[i].setHorizontalTextPosition(JLabel.CENTER);
        }

        setSize(600, 500); // 修正 setSize 的语法
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        m = new Monitor(this);
        phil = new philosopher[5];

        for (int i = 0; i < 5; i++) {
            phil[i] = new philosopher(i, m);
        }

        MenuBar mb = new MenuBar();
        Menu menul = new Menu("ON/OFF");
        MenuItem mi1 = new MenuItem("ON");
        mi1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                for (int i = 0; i < 5; i++) {
                    deadlock.this.phil[i].start();
                }
            }
        });

        MenuItem mi2 = new MenuItem("OFF");
        mi2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                for (int i = 0; i < 5; i++) {
                    deadlock.this.phil[i].interrupt();
                }
            }
        });

        MenuItem mi3 = new MenuItem("EXIT");
        mi3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        menul.add(mi1);
        menul.add(mi2);
        menul.add(mi3);

        Menu menu2 = new Menu("NOTE");
        MenuItem mi4 = new MenuItem("Readme");
        mi4.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(null, "It is not my original, Sorry!", "Readme", JOptionPane.INFORMATION_MESSAGE);
            }
        });

        menu2.add(mi4);
        mb.add(menul);
        mb.add(menu2);
        setMenuBar(mb);

        GridLayout gl = new GridLayout(3, 5);
        setLayout(gl);
        add(new JLabel());
        add(jl[0]);
        add(new JLabel());
        add(jl[1]);
        add(new JLabel());
        add(jl[4]);
        add(new JLabel());
        add(new JLabel(new ImageIcon("pic/zhuozi.jpg")));
        add(new JLabel());
        add(jl[2]);
        add(new JLabel());
        add(new JLabel());
        add(jl[3]);
        add(new JLabel());
        add(new JLabel());

        setVisible(true);
    }

    public static void main(String[] args) {
        new deadlock();
    }
}

class philosopher extends Thread {
    private int pid;
    private Monitor m;
    public boolean status;

    public philosopher(int i, Monitor m) {
        this.pid = i; // 修正变量名
        this.m = m;
        status = true;
    }

    public void run() {
        while (status) {
            m.pickupL(pid);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                status = false;
            }
            m.pickupR(pid);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                status = false;
            }
            m.putdown(pid);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                status = false;
            }
        }
    }
}
