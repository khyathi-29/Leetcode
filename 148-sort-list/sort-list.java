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
    //important to stop at 2nd pos in case of 4 elements and 3 incase of 5 elements
    // its the reason why fast is made head.next initially
    public ListNode sortList(ListNode head) {
      if(head==null || head.next==null) return head;
      ListNode slow = head;
      ListNode fast = head.next;
      while(fast!=null && fast.next!=null)
      {
        slow = slow.next;
        fast = fast.next.next;
      }
      ListNode mid = slow.next;
      slow.next = null;
      ListNode left = sortList(mid);
      ListNode right = sortList(head);
      ListNode ans = merge(left,right);
      return ans;
    }
    public ListNode merge(ListNode left, ListNode right){
        ListNode temp = new ListNode();
        ListNode dummy = temp;
        while(left!=null && right!=null)
        {
                if(left.val<=right.val)
                {
                  dummy.next = left;
                  left = left.next;
                }
                else{
                  dummy.next = right;
                  right = right.next;
                }
                dummy = dummy.next;
        }
        if(left!=null) dummy.next = left;
        else dummy.next = right;
        return temp.next;
    }
}