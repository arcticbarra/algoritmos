class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current != NULL) {
            while(current->next != NULL && current->val == current->next->val) {
                current->next = current->next->next;
            }
        current = current->next;
        }
        return head;
    }
};
