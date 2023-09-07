class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = new ListNode(-1);
        temp -> next = head;
        ListNode* prev = temp;
        for(int i = 0; i < left - 1; i++){
            prev = prev -> next;
        }
        ListNode* curr = prev -> next;
        for(int i = 0; i < right - left; i++){
            ListNode* help = curr -> next;
            curr -> next = help -> next;
            help -> next = prev -> next;
            prev -> next = help;
        }
        return temp -> next;
    }
};