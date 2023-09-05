/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Construct a copy of every node and point next to it // 1  ->  2 -> 3 then
        //                                                        \   /
        //                                                          1
        Node *curr = head;
        Node *front = head;
        while(curr != NULL){
            front = curr -> next; //storing next element as it will be used later

            Node *inNode = new Node(curr -> val);

            inNode -> next = front;
            curr -> next = inNode;
            curr = front;
        }
        curr = head;
        //now fetch actual random pointer and create a new random pointer points to inNode. (if 1->random = 3 then inNode(1) -> randowm = (inNode)3)
        while(curr != NULL){
            if(curr -> random != NULL) curr -> next -> random = curr -> random -> next;
            curr = curr -> next -> next;
        }
        curr = head;
        //now remove link and make it free
        Node *anshead = new Node(0);
        Node *copy = anshead;
        while(curr != NULL){
            front = curr -> next -> next;
            //sending the copy pointer to the copied node
            copy -> next = curr -> next;
            //restoring old original node
            curr -> next = front;
            copy = copy -> next;
            curr = front;
        }
        return anshead -> next;
    }
};