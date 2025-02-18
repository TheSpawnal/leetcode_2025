// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by 
// splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// ex1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: list1 = [], list2 = []
// Output: []

// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]

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
class Solution{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1->val<=list2->val){
            list1->next=mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
    }
};

//with dummy && priority queue
class compare {
    public:
    bool operator() (ListNode *a, ListNode *b){
        return a -> val > b -> val;
    }
};

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode dummy(0);
        ListNode *tail = &dummy;

        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        if(list1)
        minHeap.push(list1);
        if(list2)
        minHeap.push(list2);

        while(!minHeap.empty()){
            ListNode *temp = minHeap.top();
            minHeap.pop();
            tail->next = temp;
            tail = tail -> next;
            if(temp->next){
                minHeap.push(temp->next);
            }
        }
        return dummy.next;
    }
};