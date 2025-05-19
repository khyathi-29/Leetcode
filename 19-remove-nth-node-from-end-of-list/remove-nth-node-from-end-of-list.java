/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null) return head;
        ListNode t1 = head;
        while(n>0)
        {
            t1 = t1.next;
            n--;
        }
        if(t1==null) return head.next;
        ListNode t2 = head;
        ListNode prev = null;
        while(t1!=null){
            prev = t2;
            t1 = t1.next;
            t2 = t2.next;
        }
        if(t2.next!=null) {
            prev.next = t2.next;
        }
        else prev.next = null;

        return head;

        
    }
}