// /**
//  * @author Mr.乐
//  * @Description
//  */
// public class Demo01 {
//     public static void main(String[] args) {
//         //创建线程
//         MyThread t01 = new MyThread("线程01");
//         MyThread t02 = new MyThread("线程02");
//         MyThread t03 = new MyThread("线程03");

//         //开启线程
//        t01.run();
//        t02.run();
//        t03.run();
//         // 不会启动线程，不会分配新的分支栈。（这种方式就是单线程。）
//         // start()方法的作用是：启动一个分支线程，在JVM中开辟一个新的栈空间，这段代码任务完成之后，瞬间就结束了。
//         // 这段代码的任务只是为了开启一个新的栈空间，只要新的栈空间开出来，start()方法就结束了。线程就启动成功了。
//         // 启动成功的线程会自动调用run方法，并且run方法在分支栈的栈底部（压栈）。
//         // run方法在分支栈的栈底部，main方法在主栈的栈底部。run和main是平级的。
//         // t01.start();
//         // t02.start();
//         // t03.start();
//         //设置线程名（补救的设置线程名的方式）
//         // t01.setName("线程01");
//         // t02.setName("线程02");
//         //设置主线程名称
//         Thread.currentThread().setName("主线程");
//         for (int i = 0; i < 50; i++) {
//             //Thread.currentThread() 获取当前正在执行线程的对象
//             System.out.println(Thread.currentThread().getName() + ":" + i);
//         }
//     }
// }
// class MyThread extends Thread{
//     public MyThread() {
//     }

//     public MyThread(String name) {
//         super(name);
//     }

//     //run方法是每个线程运行过程中都必须执行的方法
//     @Override
//     public void run() {
//         for (int i = 0; i < 50; i++) {
//             System.out.println(this.getName() + ":" + i);
//         }
//     }
// }
// import java.util.concurrent.Callable;
// import java.util.concurrent.FutureTask;

// /**
//  * @author Mr.乐
//  * @Description 线程实现的第三种方式
//  */
// public class Demo01 {
//     public static void main(String[] args) throws Exception {

//         // 第一步：创建一个“未来任务类”对象。
//         // 参数非常重要，需要给一个Callable接口实现类对象。
//         FutureTask<Integer> task = new FutureTask<Integer>(new Callable<Integer>() {
//             @Override
//             public Integer call() throws Exception { // call()方法就相当于run方法。只不过这个有返回值
//                 // 线程执行一个任务，执行之后可能会有一个执行结果
//                 // 模拟执行
//                 System.out.println("call method begin");
//                 Thread.sleep(1000 * 3);
//                 System.out.println("call method end!");
//                 int a = 100;
//                 int b = 200;
//                 return a + b; // 自动装箱(300结果变成Integer)
//             }
//         });

//         // 创建线程对象
//         Thread t = new Thread(task);
//         t.setPriority(Thread.MIN_PRIORITY);
//         // 启动线程
//         t.start();

//         // 这里是main方法，这是在主线程中。
//         // 在主线程中，怎么获取t线程的返回结果？
//         // get()方法的执行会导致“当前线程阻塞”
//         Object obj = task.get();
//         System.out.println("线程执行结果:" + obj.toString());
//         // main方法这里的程序要想执行必须等待get()方法的结束
//         // 而get()方法可能需要很久。因为get()方法是为了拿另一个线程的执行结果
//         // 另一个线程执行是需要时间的。
//         System.out.println("hello world!");
//     }
// }

// public class Demo01 {
//     public static void main(String[] args) {
//         // 创建账户对象（只创建1个）
//         Account act = new Account("act-001", 10000);
//         // 创建两个线程
//         Thread t1 = new AccountThread(act);
//         Thread t2 = new AccountThread(act);
//         // 设置name
//         t1.setName("t1");
//         t2.setName("t2");
//         // 设置优先级
//         t1.setPriority(Thread.MAX_PRIORITY);
//         t2.setPriority(Thread.MIN_PRIORITY);
//         // 启动线程取款
//         t1.start();
//         t2.start();
//         System.out.println("t1优先级:" + t1.getPriority());
//         System.out.println("t2优先级:" + t2.getPriority());

//         // t1对act-001取款5000.0成功，余额5000.0
//         // t2对act-001取款5000.0成功，余额5000.0
//     }
// }

// // ----------------------------------------------------
// class AccountThread extends Thread {

//     // 两个线程必须共享同一个账户对象。
//     private Account act;

//     // 通过构造方法传递过来账户对象
//     public AccountThread(Account act) {
//         this.act = act;
//     }

//     public void run() {
//         // run方法的执行表示取款操作。
//         // 假设取款5000
//         double money = 5000;
//         // 取款
//         // 多线程并发执行这个方法。
//         act.withdraw(money);

//         System.out.println(
//                 Thread.currentThread().getName() + "对" + act.getActno() + "取款" + money + "成功，余额" + act.getBalance());
//     }
// }

// // ------------------------------------------------
// /**
//  * @author Mr.乐
//  * @Description
//  */
// class Account {
//     // 账号
//     private String actno;
//     // 余额
//     private double balance;

//     public Account() {
//     }

//     public Account(String actno, double balance) {
//         this.actno = actno;
//         this.balance = balance;
//     }

//     public String getActno() {
//         return actno;
//     }

//     public void setActno(String actno) {
//         this.actno = actno;
//     }

//     public double getBalance() {
//         return balance;
//     }

//     public void setBalance(double balance) {
//         this.balance = balance;
//     }
//     // //取款的方法
//     // public void withdraw(double money){
//     // // t1和t2并发这个方法。。。。（t1和t2是两个栈。两个栈操作堆中同一个对象。）
//     // // 取款之前的余额
//     // double before = this.getBalance(); // 10000
//     // // 取款之后的余额
//     // double after = before - money;
//     // // 在这里模拟一下网络延迟，100%会出现问题
//     // try {
//     // Thread.sleep(1000*2);
//     // } catch (InterruptedException e) {
//     // e.printStackTrace();
//     // }

//     // // 更新余额
//     // // 思考：t1执行到这里了，但还没有来得及执行这行代码，t2线程进来withdraw方法了。此时一定出问题。
//     // this.setBalance(after);
//     // }
//     // 1.同步语句块
//     public void withdraw(double money) {
//         synchronized (this) {
//             double before = this.getBalance();
//             double after = before - money;
//             try {
//                 Thread.sleep(1000);
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//             this.setBalance(after);
//         }
//     }

//     // 2.普通同步方法
//     // public synchronized void withdraw(double money) {
//     // double before = this.getBalance(); // 10000
//     // // 取款之后的余额
//     // double after = before - money;
//     // try {
//     // Thread.sleep(1000);
//     // } catch (InterruptedException e) {
//     // e.printStackTrace();
//     // }

//     // // 更新余额
//     // this.setBalance(after);
//     // }
//     // 3.静态同步方法
//     // public static synchronized void withdraw(double money) {
//     // double before = this.getBalance(); // 10000
//     // // 取款之后的余额
//     // double after = before - money;
//     // try {
//     // Thread.sleep(1000);
//     // } catch (InterruptedException e) {
//     // e.printStackTrace();
//     // }

//     // // 更新余额
//     // this.setBalance(after);
//     // }
// }
import java.util.Timer;
import java.util.TimerTask;
 
/**
 * @author Mr.乐
 * @Description 线程与定时器的执行轨迹不同
 */
public class Demo01 {
    public static void main(String[] args) {
        boolean bool = "sfds" instanceof String;
        System.out.println(bool);
        new Thread(new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 20; i++) {
                    System.out.println(Thread.currentThread().getName() + "<--->" + i);
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }).start();
 
        //定时器实现
        new Timer().schedule(new TimerTask() {
            @Override
            public void run() {
                for (int i = 0; i < 10; i++) {
                    System.out.println(Thread.currentThread().getName() + "---" + i);
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                System.gc();//将编程垃圾的定时器进行回收
            }
        },5000);
    }
}

