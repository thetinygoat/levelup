public class stack {
    private int size;
    private int capacity;
    private int stack[];

    public stack() {
        this.size = -1;
        this.capacity = 20;
        this.stack = new int[this.capacity];
    }

    public stack(int capacity) {
        this.size = -1;
        this.capacity = capacity;
        this.stack = new int[this.capacity];
    }

    public void push(int data) {
        if (size <= capacity) {
            this.stack[++this.size] = data;
        } else {
            System.out.println("stack overflow!!");
        }
    }

    public int top() {
        if (size > 0) {
            return this.stack[size - 1];
        }
        System.out.println("stack underflow!!");
        return (int) -1e8;
    }

    public int pop() {
        if (size > 0) {
            return this.stack[size--];
        }
        System.out.println("stack underflow!!");
        return (int) -1e8;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0 ? true : false;
    }

    protected void setSize(int size) {
        this.size = size;
    }

    protected int getSize() {
        return this.size;
    }

    protected void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    protected int getCapacity() {
        return this.capacity;
    }

    protected int[] getStack() {
        return this.stack;
    }

    protected void setStack(int[] stack) {
        this.stack = stack;
    }
}
