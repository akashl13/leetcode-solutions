class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == nullptr || k == 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {

            ListNode* kth = groupPrev;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                if (kth == nullptr)
                    return dummy.next;
            }

            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* current = groupPrev->next;

            while (current != groupNext) {
                ListNode* next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            ListNode* oldFirst = groupPrev->next;
            groupPrev->next = kth;

            groupPrev = oldFirst;
        }
    }
};