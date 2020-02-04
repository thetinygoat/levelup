import java.util.LinkedList;
import java.util.ArrayList;

public class gtree {
    public static void main(String[] args) {
        solve();
    }

    public static class Node {
        int data;
        ArrayList<Node> children = new ArrayList<>();
    }

    public static void solve() {
        int[] preorder = { 10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1,
                -1, -1 };
        Node root = create(preorder);
        // traverse(root);
        // System.out.println(find(root, 110));
        // findMax(root);
        // findMin(root);
        // findSize(root);
        // System.out.println(size);
        findFloor(root, 55);
        System.out.println(floor);

    }

    public static Node create(int[] arr) {
        LinkedList<Node> stack = new LinkedList<>();
        Node root = new Node();
        root.data = arr[0];
        stack.addLast(root);
        int i = 1;
        while (!stack.isEmpty()) {
            if (arr[i] == -1) {
                stack.removeLast();
                i++;
                continue;
            }
            Node top = stack.getLast();
            Node child = new Node();
            child.data = arr[i];
            top.children.add(child);
            stack.addLast(child);
            i++;
        }
        return root;
    }

    public static void traverse(Node root) {
        System.out.println(root.data);
        for (int i = 0; i < root.children.size(); i++) {
            traverse(root.children.get(i));
        }
    }

    public static boolean find(Node root, int data) {
        if (root.data == data)
            return true;
        boolean res = false;
        for (Node c : root.children) {
            res = res || find(c, data);
        }
        return res;
    }

    static int max = (int) -1e8;

    public static void findMax(Node root) {
        if (root.data > max)
            max = root.data;
        for (Node c : root.children) {
            findMax(c);
        }
    }

    static int min = (int) 1e8;

    public static void findMin(Node root) {
        if (root.data < min)
            min = root.data;
        for (Node c : root.children) {
            findMin(c);
        }
    }

    static int size = 0;

    public static void findSize(Node root) {
        size++;
        for (Node c : root.children) {
            findSize(c);
        }
    }

    public static int findHeight(Node root) {
        if (root.children.size() == 0) {
            return 0;
        }
        ArrayList<Integer> childHeights = new ArrayList<>();
        for (Node c : root.children) {
            childHeights.add(findHeight(c));
        }
        int maxChildHeight = 0;
        for (int h : childHeights) {
            maxChildHeight = Math.max(maxChildHeight, h);
        }
        return maxChildHeight + 1;
    }

    static int ceil = (int) 1e8;

    public static void findCeil(Node root, int data) {
        for (Node c : root.children) {
            if (c.data > data && c.data < ceil)
                ceil = c.data;
            findCeil(c, data);
        }
    }

    static int floor = (int) -1e8;

    public static void findFloor(Node root, int data) {
        for (Node c : root.children) {
            if (c.data < data && c.data > floor)
                floor = c.data;
            findFloor(c, data);
        }
    }

}