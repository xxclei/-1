package producer_consumer;

public class ProducerConsumerTest {
    public static void main(String[] args) {
        Buffer product = new Buffer();
        Producer p = new Producer(product);
        Consumer c = new Consumer(product);
        p.start(); // 启动生产者线程
        c.start(); // 启动消费者线程
    }
}
