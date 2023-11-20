public class Demo02 {
    public static void main(String[] args) {
        // Thread t1 = new Thread("线程01");
        MyThread t1 = new MyThread("子线程1");
        // t1.run();
        t1.start();
        Thread.currentThread().setName("主线程");
        for (int i = 1; i <= 100; i++) {
            if ((i & 1) == 0) {
                System.out.println(Thread.currentThread().getName() + " " + i);
            }
        }
    }
}

class MyThread extends Thread{
    public MyThread() {
    }
 
    public MyThread(String name) {
        super(name);
    }
    //run方法是每个线程运行过程中都必须执行的方法
    @Override
    public void run() {
        for (int i = 1; i <= 100; i++) {
            if ((i & 1) == 1) {
            System.out.println(this.getName()+" "+ i);
           }
        }
    }
}
