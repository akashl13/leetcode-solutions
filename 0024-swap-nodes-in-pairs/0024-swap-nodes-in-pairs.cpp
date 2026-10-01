class Solution
{
    public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode dummy(0);
        dummy.next= head;

        ListNode* current= &dummy;
        while(current -> next != nullptr && current -> next -> next != nullptr)
        {
            ListNode* first = current-> next;
            ListNode* second= first-> next;

            //swap the numbers
            first-> next = second-> next;
            second-> next=  first;
            current-> next= second;

            current= first;
        }
        return dummy.next;
    }
} ;