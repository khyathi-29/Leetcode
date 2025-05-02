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
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode ans = head;
        ListNode ne;
        while(ans!= null){
            ne = ans.next;
            ans.next = prev;
            prev = ans;
            ans = ne;
        }
        return prev;
    }
}