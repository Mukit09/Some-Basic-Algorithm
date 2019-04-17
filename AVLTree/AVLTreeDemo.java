package AVLTree;

class Node {
    Node left, right;
    int key, height;

    Node(int key) {
        this.height = 1;
        this.key = key;
    }
}

public class AVLTreeDemo {

    private int getHeight(Node node) {
        if(node == null)
            return 0;
        return node.height;
    }

    int getBalance(Node node) {
        if(node == null)
            return 0;
        return getHeight(node.left) - getHeight(node.right);
    }

    private void setHeight(Node node) {
        node.height = 1 + Math.max(getHeight(node.left), getHeight(node.right));
    }

    Node doLLRotation(Node node) {
        Node tempNode1 = node.left.right;
        Node tempNode2 = node.left;
        node.left = tempNode1;
        tempNode2.right = node;
        setHeight(node);
        setHeight(tempNode2);
        return tempNode2;
    }

    Node doRRRotation(Node node) {
        Node tempNode1 = node.right.left;
        Node tempNode2 = node.right;
        node.right = tempNode1;
        tempNode2.left = node;
        setHeight(node);
        setHeight(tempNode2);
        return tempNode2;
    }

    Node insert(Node node, int key) {
        if(node == null)
            return new Node(key);
        if(key < node.key )
            node.left = insert(node.left, key);
        else if(key > node.key)
            node.right = insert(node.right, key);
        else
            return node;

        setHeight(node);
        int balance = getBalance(node);

        // balancing if not balanced
        // Inserted in Left Left
        if(balance > 1 && key < node.left.key)
            node = doLLRotation(node);
        else if(balance > 1 && key > node.left.key) {// Inserted in right child of left child of the node
            node.left = doRRRotation(node.left);
            node = doLLRotation(node);
        }
        else if(balance < -1 && key >  node.right.key)
            node = doRRRotation(node);
        else if(balance < -1 && key < node.right.key) {
            node.right = doLLRotation(node.right);
            node = doRRRotation(node);
        }
        return node;
    }

    void preOrderPrint(Node node) {
        if(node == null)
            return;
        System.out.print(" " + node.key);
        preOrderPrint(node.left);
        preOrderPrint(node.right);
    }

    public static void main(String[] args) {
        AVLTreeDemo demo = new AVLTreeDemo();
        Node root = new Node(10);
        root = demo.insert(root, 20);
        root = demo.insert(root, 30);
        root = demo.insert(root, 40);
        root = demo.insert(root, 50);
    //    root = demo.insert(root, 25);
        root = demo.insert(root, 60);
        root = demo.insert(root, 70);
        root = demo.insert(root, 80);
        root = demo.insert(root, 90);

        demo.preOrderPrint(root);
        System.out.println();
    }
}
