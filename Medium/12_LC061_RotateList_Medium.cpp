class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        ListNode* current = head;
        int length = 1;

        while (current->next != nullptr) {
            current = current->next;
            length++;
        }

        k = k % length;

        if (k == 0) {
            return head;
        }

        current->next = head;

        int steps = length - k;
        ListNode* newTail = current;

        while (steps--) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};