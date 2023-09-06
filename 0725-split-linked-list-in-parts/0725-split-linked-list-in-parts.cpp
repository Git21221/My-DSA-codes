class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode *temp = head;
        int n = 0;
        while(temp){
            n++;
            temp = temp -> next;
        }
        int q = n / k, rem = n % k;
        int firstpart = rem, firstpartEle = q + 1, secondpart = k - rem, secondpartEle = q;
        temp = head;
        //first part (greater part)
        while(firstpart--){
            ListNode *curr = new ListNode();
            ListNode *tra = curr;
            while(firstpartEle-- && temp){
                tra -> next = new ListNode(temp -> val);
                tra = tra -> next;
                temp = temp -> next;
            }
            ans.push_back(curr -> next);
            firstpartEle = q + 1;
        }
        //2nd part
        while(secondpart--){
            ListNode *curr = new ListNode();
            ListNode *tra = curr;
            while(secondpartEle-- && temp){
                tra -> next = new ListNode(temp -> val);
                tra = tra -> next;
                temp = temp -> next;
            }
            ans.push_back(curr -> next);
            secondpartEle = q;
        }
        return ans;
    }
};