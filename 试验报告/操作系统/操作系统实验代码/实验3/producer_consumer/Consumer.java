package producer_consumer;

public class Consumer extends Thread {
    private Buffer product;

    public Consumer(Buffer product) {
        this.product = product;
    }

    public void run() {
        int value;
        do {
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) { }
            value = product.getProduct();
            System.out.println("消费: " + value);
        } while (value != 10);
    }
}
