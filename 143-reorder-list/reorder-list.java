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
    public void reorderList(ListNode head) {
        
        ListNode fast = head.next;
        ListNode slow = head;
        ListNode prev = null;
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode newH = slow.next;
        slow.next = null;
        newH = reverse(newH);
        slow = head;
        while(newH !=null)
        {
            ListNode n1 = slow.next;
            ListNode n2 = newH.next;
            slow.next = newH;
            newH.next = n1 ;
            slow = n1;
            newH = n2;
        }
    }
    private ListNode reverse(ListNode head){
        ListNode prev = null;
        ListNode current = head;
        while(current!=null){
            ListNode n = current.next;
            current.next = prev;
            prev = current;
            current = n;
        }
        return prev;
    }
}