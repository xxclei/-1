package producer_consumer;

public class Producer extends Thread {
    private Buffer product;

    public Producer(Buffer product) {
        this.product = product;
    }

    public void run() {
        for (int count = 1; count <= 10; count++) {
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) { }
            product.setProduct(count);
            System.out.println("生产: " + count);
        }
    }
}
