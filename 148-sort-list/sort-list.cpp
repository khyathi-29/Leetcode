/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /*
     * Function: sortList
     * Purpose: Sorts a linked list using Merge Sort (Divide and Conquer).
     * Time: O(n log n)
     * Space: O(log n) for recursion stack (no extra memory for arrays).
     */
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;  // Base case: empty or single node

        // Step 1: Split list into two halves
        ListNode* slow = head;
        ListNode* fast = head->next; // Important: fast starts at head->next

        /*
         * WHY fast = head->next?
         * It ensures that for even-length lists:
         * - slow stops at the 2nd node when list has 4 nodes (1,2,3,4)
         * - slow stops at the 3rd node when list has 5 nodes (1,2,3,4,5)
         * This makes splitting perfectly balanced and avoids infinite loops.
         */
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Cut the list at mid and recurse
        ListNode* mid = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(head);   // Sort first half
        ListNode* right = sortList(mid);   // Sort second half

        // Step 2: Merge two sorted halves
        return merge(left, right);
    }

    /*
     * Function: merge
     * Purpose: Merge two sorted linked lists
     */
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (left && right) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        // Append remaining nodes
        tail->next = left ? left : right;

        return dummy.next;
    }
};