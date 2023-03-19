class Solution {
    public ListNode reverseList(ListNode head) {
        // // rewrite of C++
        // if (head == null) { return head; }
        // ListNode next;
        // ListNode prev = null; 
        // while (head != null) {
        //     next = head.next;
        //     head.next = prev;
        //     prev = head;
        //     head = next;
        // }
        // return prev;

        // recursive 
        if (head == null || head.next == null) { return head; }
        ListNode tmp = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return tmp;
    }
}
