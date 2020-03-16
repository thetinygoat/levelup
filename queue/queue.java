public class queue {
    protected int size;
    protected int head;
    protected int tail;
    protected int maxsize;
    protected int[] queue;

    queue() {
        this.size = 0;
        this.head = 0;
        this.tail = 0;
        this.maxsize = 10;
        this.queue = new int[10];
    }

    queue(int maxsize) {
        this.size = 0;
        this.head = 0;
        this.tail = 0;
        this.maxsize = maxsize;
        this.queue = new int[maxsize];
    }

    public boolean isempty() {
        return this.size == 0;
    }

    private void push_(int data) {
        this.queue[this.tail % this.maxsize] = data;
        if (this.tail < this.maxsize) {
            this.tail++;
        } else {
            this.tail = this.tail % this.maxsize;
        }
        this.size++;
    }

    public void push(int data) throws Exception {
        if (this.size >= this.maxsize) {
            throw new Exception("queue is full");
        }
        push_(data);
    }

    private int pop_() {
        this.head++;
        this.size--;
        return this.head;
    }

    public int pop() throws Exception {
        if (this.size <= 0) {
            throw new Exception("queue is empty");
        }
        return pop_();
    }

    public int size() {
        return this.size;
    }

    public void display() {
        for (int i = 0; i != this.tail; i = (i + 1) % this.maxsize) {
            System.out.println(this.queue[i]);
        }
    }

    private int top_() {
        return this.head;
    }

    public int top() throws Exception {
        if (this.size < 0) {
            throw new Exception("queue is empty");
        }
        return top_();
    }
}