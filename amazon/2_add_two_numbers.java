

class Solution{
    public ListNode addTwoNumbers(ListNode l1, ListNode l2){
        ListNode dummy  = new ListNode(0, null);
        ListNode tail = dummy;
        int sum = 0;
        int carry = 0;
        while(l1 != null || l2 != null || carry != 0){
            sum = carry;
            if(l1 != null){
                sum += l1.val;
                l1 = l1.next;
            }
            if(l2 != null ){
                sum += l2.val;
                l2 = l2.next;
            }
            ListNode newNode = new ListNode(sum%10, null);
            carry = sum / 10;
            tail.next = newNode;
            tail = tail.next;
        }
        return(dummy.next);
    }
}