

class MinStack {
	public class node {
        int val;
        int min;
        node next;
        public node(int val, int min, node next) {
            this.val = val;
            this.min = min;
            this.next = next;
        }
    }

    public node head;

    public void push(int val) {
        if (head == null){
            head = new node(val, val, head);
        }
        else {
            head = new node(val, Math.min(head.min, val), head);
        }
    }
    
    public void pop() {
        head = head.next;
    }
    
    public int top() {
        return head.val;
    }
    
    public int getMin() {
        return head.min;
    }
}