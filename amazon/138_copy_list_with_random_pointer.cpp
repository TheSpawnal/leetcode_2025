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

//with map
class Solution{
public:
    Node* copyRandomList(Node* head){
        map<Node*, Node*> m;
        int i = 0;
        Node* ptr = head;
        while(ptr){
            m[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while(ptr){
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        return m[head];
    }
};


//pointer only
class Solution{
public:
    Node* copyRandomList(Node* head){
        Node* newHead = NULL;
        Node* curr = head;

        while(curr){
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = curr->next->next;
        }
        curr = head;
        while(curr){
            Node* copy = curr->next;
            copy->random = curr->random ? curr->random->next: NULL;
            curr = copy->next;
        }
        curr = head;
        Node* lastNew = NULL;
        while(curr){
            Node* copy = curr->next;
            if(!newHead){
                newHead = copy;
            }
            Node* next = copy->next;
            curr->next = next;
            if(next != NULL){
                copy->next = next->next;
            }
            curr = next;
        }
        return newHead;
    }
};