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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head || head->next == NULL) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        int value = slow->val;
        fast = fast->next;
        while (fast) {
            if (fast->val == value) {
                if (fast->next != NULL) {
                    fast = fast->next;
                    slow->next = fast;
                }
                else {
                    slow->next = NULL;
                    break;
                }
            }
            else {
                fast = fast->next;
                slow = slow->next;
                value = slow->val;
            }
        }
        return head;
    }
};