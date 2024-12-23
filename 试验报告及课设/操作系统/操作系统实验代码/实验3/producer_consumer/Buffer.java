package producer_consumer;

public class Buffer {
    private int product = 0;
    private boolean enable = true;

    public synchronized void setProduct(int value) {
        while (!enable) {
            try {
                wait();
            } catch (InterruptedException e) { }
        }
        product = value;
        enable = false;
        notify();
    }

    public synchronized int getProduct() {
        while (enable) {
            try {
                wait();
            } catch (InterruptedException e) { }
        }
        enable = true;
        notify();
        return product;
    }
}
