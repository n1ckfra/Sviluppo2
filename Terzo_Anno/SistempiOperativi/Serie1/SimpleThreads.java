import java.lang.Runnable;

public class SimpleThreads {
    static void threadMessage(String message){
        String threadName =
            Thread.currentThread().getName();
        System.out.format("%s: %s\n",
                          threadName,
                          message);
    }
private static class MessageLoop implements Runnable {
    public void run() {
            String importantInfo[] = {
                "Mares eat oats",
                "Does eat oats",
                "Little lambs eat ivy",
                "A kid will eat ivy too"};
            try {
                for (int i = 0; i < importantInfo.length; i++)
                {
                    Thread.sleep(4000);
                    threadMessage(importantInfo[i]);
                }
            }
            catch (InterruptedException e)
            {
                threadMessage("I wasn't done!");
            }
        }
        int getResult()
        {
            return 42;
        }
    } public static void main(String args[])
        throws InterruptedException
    {
        long patience = 0;
        if (args.length > 0)
        {
            try
            {
                patience = Long.parseLong(args[0]) * 1000;
            }
            catch (NumberFormatException e)
            {
                System.err.println("Argument must be an integer.");
                System.exit(1);
            }
        }
        else
        {
            System.err.println("Missing argument.");
            System.exit(2);
        }
        threadMessage("Starting MessageLoop thread");
        MessageLoop r = new MessageLoop();
        Thread t = new Thread(r);
        t.start();
        threadMessage("Waiting for MessageLoop thread to finish");
        Thread.sleep(patience);
        if (t.isAlive())
        {
            threadMessage("Tired of waiting!");
            t.interrupt();
        }
        t.join();
        threadMessage("Finally!");
        System.exit(r.getResult());
    }
}