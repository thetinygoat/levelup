public class client {
    public static void main(String[] args) {
        queue q = new queue();
        try {
            q.push(2);
            q.push(3);
            q.push(4);
            q.push(5);
            q.push(6);
            q.push(7);
            q.push(8);
            q.push(9);
            q.push(10);
            q.push(11);
            q.pop();
            q.pop();
            q.pop();
            q.pop();
            q.push(12);
            q.push(13);
            q.push(14);
            q.push(15);
            q.display();
        } catch (Exception e) {
            System.out.println(e);
        }

    }
}