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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode temp1 = head;
        if(left==right) return head;
        ListNode dummy= new ListNode(0);// node before left starts
        dummy.next = head;
        ListNode prev1 = dummy;
        for(int i=1;i<left;i++){
            prev1 = temp1;
            temp1=temp1.next;
        }
        ListNode prev = null;
        ListNode tail = temp1;
        ListNode n = null;
        //temp1 is the node where reversal starts its current node

        for(int i=0 ;i<=right-left;i++)
        {
             n = temp1.next;
             temp1.next = prev;
             prev = temp1;
             temp1 = n;
        }
        prev1.next = prev;
        System.out.println(tail.val);
        tail.next = n;
        // we can't return head because if left==1 then head would also change
        return dummy.next;
    }
}