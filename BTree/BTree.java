import java.util.LinkedList;
import java.util.HashMap;
import java.util.ArrayList;

public class BTree {
	public static void main(String[] args) {
		int[] arr = { 10, 20, 30, -1, -1, 40, -1, -1, 50, 60, 80, -1, -1, -1, 70, 90, -1, 100, -1, -1, -1 };
		Node root = create(arr);
		// display(root);

		solve(root);
	}

	// solve function to call from main
	public static void solve(Node root) {
		// preorder(root);
		// postorder(root);
		// inorder(root);
		// levelorder(root);
		// kfar_01(root, 2, 50);
		// System.out.println(maxPathSum(root));
		int sortedArr[] = { 10, 20, 30, 40, 50, 60, 70, 80 };

		root = arrayToBst(sortedArr, 0, sortedArr.length - 1);

		// root = addDataToBST(root, 32);
		// root = addDataToBST(root, 29);
		// display(root);
		// System.out.println(bstLca(root, 29, 32).data);
		// findInRange(root, 5, 20);
		// verticalOrder(root, 0);
		// System.out.println(hmap);
		int leftwidth = width(root, true);
		// int rightwidth = width(root, false);
		int arr[];
		arr = new int[leftwidth + 1];
		// vericalOrderSum(root, arr, leftwidth);
		diagonalSum(root, arr, leftwidth);
		for (int i = 0; i < arr.length; i++) {
			System.out.println(arr[i]);
		}
	}

	// Node class for tree implementation
	public static class Node {
		int data = 0;
		Node left = null;
		Node right = null;

		Node(int data, Node left, Node right) {
			this.data = data;
			this.left = left;
			this.right = right;
		}
	}

	static int idx = 0;

	public static Node create(int[] arr) {
		if (idx == arr.length || arr[idx] == -1) {
			idx++;
			return null;
		}
		Node nnode = new Node(arr[idx], null, null);
		idx++;
		nnode.left = create(arr);
		nnode.right = create(arr);
		return nnode;
	}

	public static void display(Node node) {
		if (node == null)
			return;
		String str = "";

		str += node.left == null ? "." : node.left.data;
		str += " -> " + node.data + " <- ";
		str += node.right == null ? "." : node.right.data;
		System.out.println(str);

		display(node.left);
		display(node.right);
	}

	// pre order traversal
	public static void preorder(Node root) {
		if (root == null) {
			return;
		}
		System.out.println(root.data);
		preorder(root.left);
		preorder(root.right);
	}

	// post order traversal
	public static void postorder(Node root) {
		if (root == null) {
			return;
		}

		preorder(root.left);
		preorder(root.right);
		System.out.println(root.data);
	}

	// inorder traversal
	public static void inorder(Node root) {
		if (root == null) {
			return;
		}

		preorder(root.left);
		System.out.println(root.data);
		preorder(root.right);

	}

	// level order traversal
	public static void levelorder(Node root) {
		LinkedList<Node> que = new LinkedList<>();
		int level = 0;
		que.addLast(root);
		que.addLast(null);
		System.out.print("Level: " + level + " -> ");
		while (que.size() != 1) {
			Node rnode = que.removeFirst();
			System.out.println(rnode.data + " ");
			if (rnode.left != null)
				que.addLast(rnode.left);
			if (rnode.right != null)
				que.addLast(rnode.right);
			if (que.getFirst() == null) {
				que.addLast(null);
				que.removeFirst();
				level++;
				System.out.println();
				System.out.print("Level: " + level + " -> ");
			}

		}
	}

	public static ArrayList<Node> rootToNodePath(Node root, int data) {
		if (root == null)
			return null;
		if (root.data == data) {
			ArrayList<Node> base = new ArrayList<>();
			base.add(root);
			return base;
		}
		ArrayList<Node> left = rootToNodePath(root.left, data);
		if (left != null) {
			left.add(root);
			return left;
		}
		ArrayList<Node> right = rootToNodePath(root.right, data);
		if (right != null) {
			right.add(root);
			return right;
		}

		return null;
	}

	public static void kaway(Node node, int k, Node rnode) {
		if (node == null)
			return;
		if (node == rnode)
			return;
		if (k == 0) {
			System.out.println(node.data + " ");
			return;
		}
		kaway(node.left, k - 1, rnode);
		kaway(node.right, k - 1, rnode);
	}

	public static void kfar_01(Node root, int k, int data) {
		ArrayList<Node> path = rootToNodePath(root, data);
		Node rnode = null;
		for (int i = 0; i < path.size(); i++) {
			kaway(path.get(i), k - i, rnode);
			rnode = path.get(i);
		}
	}

	public static class BSTPair {
		boolean isbst = true;
		int count = 0;
		int size = 0;
		Node rootNode = null;

		int max = (int) -1e8;
		int min = (int) 1e8;
	}

	public static BSTPair bstsol(Node root) {
		BSTPair mypair = new BSTPair();
		if (root == null)
			return mypair;
		BSTPair lp = bstsol(root.left);
		BSTPair rp = bstsol(root.right);
		mypair.count = lp.count + rp.count;
		if (lp.isbst && rp.isbst && lp.max < root.data && rp.min > root.data) {
			mypair.count++;
			mypair.rootNode = root;
			mypair.size = mypair.count;
		} else {
			mypair.isbst = false;
			if (lp.size > rp.size) {
				mypair.size = lp.size;
				mypair.rootNode = lp.rootNode;
			} else {
				mypair.size = rp.size;
				mypair.rootNode = rp.rootNode;
			}
		}

		mypair.min = Math.min(Math.min(lp.min, rp.min), root.data);
		mypair.max = Math.max(Math.max(lp.max, rp.max), root.data);
		return mypair;
	}

	public static Node linear(Node root) {
		if (root == null)
			return null;
		if (root.left == null && root.right == null)
			return root;

		Node lefttail = linear(root.left);
		Node righttail = linear(root.right);

		if (lefttail == null)
			root.left = root.right;
		else
			lefttail.left = root.right;

		root.right = null;

		return righttail != null ? righttail : lefttail;

	}

	public static int maxPathSum(Node node) {
		if (node == null)
			return 0;
		if (node.left == null && node.right == null) {
			return node.data;
		}
		int ls = maxPathSum(node.left);
		int rs = maxPathSum(node.right);
		return Math.max(Math.max(Math.max(ls, node.data), Math.max(rs, node.data)), ls + rs + node.data);
	}

	public static Node arrayToBst(int[] arr, int start, int end) {

		if (start > end) {
			return null;
		}
		int mid = (start + end) >> 1;
		Node root = new Node(arr[mid], null, null);
		root.left = arrayToBst(arr, start, mid - 1);
		root.right = arrayToBst(arr, mid + 1, end);
		return root;
	}

	public static Node addDataToBST(Node node, int data) {
		if (node == null) {
			Node newNode = new Node(data, null, null);
			return newNode;
		}
		if (data < node.data) {
			node.left = addDataToBST(node.left, data);
		}
		if (data > node.data) {
			node.right = addDataToBST(node.right, data);
		}
		return node;

	}

	public static int findMaxinBST(Node node) {
		Node rnode = node;
		while (rnode.right != null) {
			rnode = rnode.right;
		}
		return rnode.data;
	}

	public static Node deleteDataFromBST(Node node, int data) {
		// if (node == null)
		// return null;
		// if (node.right == null && node.left == null) {
		// return null;
		// }
		// if (node.right != null && node.left == null) {
		// return node.right;
		// }
		// if (node.right == null && node.left != null) {
		// return node.left;
		// }

		if (data < node.data) {
			node.left = deleteDataFromBST(node.left, data);
		}
		if (data > node.data) {
			node.right = deleteDataFromBST(node.right, data);
		} else {
			if (node.left == null || node.right == null) {
				return node.left == null ? node.right : node.left;
			}

			int rdata = findMaxinBST(node.left);
			node.data = rdata;
			node.left = deleteDataFromBST(node.left, rdata);
		}

		return node;
	}

	public static void swapped_array() {
		int arr[] = { 1, 3, 0, 0, 2 };
		System.out.println();
	}

	public static boolean findInBst(Node root, int data) {
		if (root == null)
			return false;
		if (root.data == data)
			return true;
		boolean left = findInBst(root.left, data);
		boolean right = findInBst(root.right, data);
		return left || right;
	}

	public static Node bstLca(Node root, int a, int b) {
		if (root == null)
			return null;
		if (root.data < a)
			return bstLca(root.right, a, b);
		if (root.data > b)
			return bstLca(root.left, a, b);
		else {
			if (findInBst(root, a) && findInBst(root, b)) {
				return root;
			}
			return null;
		}
	}

	public static Node findInRange(Node root, int a, int b) {
		if (root == null)
			return null;
		if (root.data < a)
			return bstLca(root.right, a, b);
		if (root.data > b)
			return bstLca(root.left, a, b);
		else {
			System.out.println(root.data);
			if (root.data < a)
				return bstLca(root.right, a, b);
			if (root.data > b)
				return bstLca(root.left, a, b);
			// if (findInBst(root, a) && findInBst(root, b)) {
			// return root;
			// }
			return null;
		}
	}

	static HashMap<Integer, ArrayList<Integer>> hmap = new HashMap<>();

	public static void verticalOrder(Node root, int order) {
		if (root == null)
			return;

		verticalOrder(root.left, order - 1);
		verticalOrder(root.right, order + 1);
		if (!hmap.containsKey(order)) {
			ArrayList<Integer> list = new ArrayList<>();
			list.add(root.data);
			hmap.put(order, list);
		} else {
			ArrayList<Integer> list = hmap.get(order);
			list.add(root.data);
			hmap.put(order, list);
		}
	}

	public static int width(Node node, boolean isLeftWidth) {
		if (node == null)
			return -1;
		int left = width(node.left, isLeftWidth) + (isLeftWidth ? 1 : -1);
		int right = width(node.right, isLeftWidth) + (isLeftWidth ? -1 : 1);
		return Math.max(left, right);
	}

	public static void vericalOrderSum(Node node, int[] arr, int idx) {
		if (node == null)
			return;
		vericalOrderSum(node.left, arr, idx - 1);
		arr[idx] += node.data;
		vericalOrderSum(node.right, arr, idx + 1);
	}

	public static void diagonalSum(Node node, int[] arr, int idx) {
		if (node == null)
			return;
		diagonalSum(node.left, arr, idx - 1);
		arr[idx] += node.data;
		diagonalSum(node.right, arr, idx);
	}

}