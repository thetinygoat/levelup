public class client {

    public static void main(String args[]) {
        dstack st = new dstack();

        for (int i = 0; i < 100; i++) {
            st.push(i);
        }

        while (!st.isEmpty()) {
            System.out.println(st.pop());
        }
    }
}