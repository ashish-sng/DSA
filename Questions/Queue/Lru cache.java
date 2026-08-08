// https://leetcode.com/problems/lru-cache/
import java.utils.*;

class LRUCache {

    class Node {
        int key;
        int value;
        Node prev;
        Node next;

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    HashMap<Integer, Node> map;

    Node head;
    Node tail;
    int capacity;

    public LRUCache(int capacity) {
        this.capacity = capacity;

        map = new HashMap<>();

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        if (!map.containsKey(key))
            return -1;

        Node currNode = map.get(key);

        removeNode(currNode);
        addToFront(currNode);

        return currNode.value;
    }

    public void put(int key, int value) {
        if(map.containsKey(key)){
            Node node = map.get(key);

            node.value = value;

            removeNode(node);
            addToFront(node);

            return;
        }

        Node node = new Node(key, value);

        map.put(key, node);

        addToFront(node);

        if(map.size() > capacity){
            Node lru = tail.prev;

            removeNode(lru);

            map.remove(lru.key);
        }
    }

    private void removeNode(Node node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    private void addToFront(Node node) {
        node.next = head.next;
        node.prev = head;

        head.next.prev = node;
        head.next = node;
    }
}
