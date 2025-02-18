/*
Definition of singly_linked list.
struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
    };
*/

class Solution{
    class compare{
        public:
            bool operator()(ListNode* a, ListNode* b){
                return a->val > b->val;
            }
        };
        void insertAtTail(ListNode* node, ListNode* &tail){
            tail->next = node;
            tail = tail->next; 
        }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.size()==0){
            return NULL;
        }
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        int k = lists.size();
        for(int i = 0; i < k; i++){
            if(lists.at(i)){
                minHeap.push(lists.at(i));
            }
        }
        ListNode* ans = new ListNode(0);
        ListNode* tail = ans;

        while(minHeap.size()>0){
            insertAtTail(minHeap.top(),tail);
            minHeap.pop();
            if(tail->next){
                minHeap.push(tail->next);
            }
        }
            return ans->next;
    }
};


//memory efficiency
class Solution{
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists){
        if(lists.empty()){
            return nullptr;
        }
        return mergeLists(lists, 0,lists.size()-1);
    }
private:
    ListNode* mergeLists(std::vector<ListNode*>& lists, int start, int end){
        if(start == end){
            return lists[start];
        }
        int mid = start + (end - start)/2;
        ListNode* left = mergeLists(lists, start, mid);
        ListNode* right = mergeLists(lists, mid + 1, end);
        return mergeTwoLists(left, right);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(!l1)return l2;
        if(!l2)return l1;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = (l1 ? l1 : l2);
        return dummy.next;
    }
};