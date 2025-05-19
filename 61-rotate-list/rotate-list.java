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
    public ListNode rotateRight(ListNode head, int k) {
       int length =0;
       ListNode temp = head;
       if(temp==null) return temp;
       while(temp!=null){
        temp=temp.next;
        length++;
       } 
       k = k%length;
       if(k==0) return head;
       temp = head;
       int i = k;
       while(i>0)
       {
         temp=temp.next;
         i--;
       }
       ListNode first = head;
       while(temp.next!=null)
       {
        first=first.next;
        temp=temp.next;
       }
        ListNode newHead = first.next;
        first.next = null;
        temp.next = head;

        return newHead;
    }
}