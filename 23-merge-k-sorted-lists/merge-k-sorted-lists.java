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
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a,b)->{return a.val-b.val;});
        for(ListNode temp : lists)
        {
            if(temp!=null) pq.add(temp);
        }
        ListNode dummy = new ListNode(0);
        ListNode ans = dummy;
        while(!pq.isEmpty())
        {
             ListNode t = pq.poll();
             ans.next = t;
             ans = ans.next;
             if(t.next!=null) pq.add(t.next);
        }
        return dummy.next;
        
    }
}