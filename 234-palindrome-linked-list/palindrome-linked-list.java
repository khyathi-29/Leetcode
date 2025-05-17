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
    public boolean isPalindrome(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = head;
        while(fast!=null && fast.next!=null){
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode n2 = reverse(slow);
        slow = head;
        while(n2!=null){
            if(n2.val!=slow.val) return false;
            n2 = n2.next;
            slow = slow.next;
        }
        return true;
    }
    public ListNode reverse(ListNode head)
    {
        ListNode prev = null;
        ListNode current = head;
        ListNode Next;
        while(current!=null){
            Next = current.next;
            current.next = prev;
            prev = current;
            current = Next;
        }
        return prev;
    }
}
