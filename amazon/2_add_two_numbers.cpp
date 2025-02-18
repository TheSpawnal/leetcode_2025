
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
//two pointers approach linked list manipulation
class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        while(tmp1 && tmp2){
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        ListNode* result = tmp1 ? l1:l2;
        ListNode* o = result;
        int tmp = 0;
        int o1 = 0;
        int o2 = 0;
        while(l1 && l2){
            o1 = l1->val;
            o2 = l2->val;
            o->val = (o1 + o2 + tmp) % 10;
            tmp = (o1 + o2 + tmp)/10;
            o = o->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            o1=l1->val;
            o->val = (o1 + tmp)%10;
            tmp =(o1 + tmp)/10;
            o = o->next;
            l1 = l1->next;
        }
        while(l2){
            o2=l2->val;
            o->val = (o2 + tmp)%10;
            tmp =(o2 + tmp)/10;
            o = o->next;
            l2 = l2->next;
        }
        if(tmp > 0){
            ListNode* f = result;
            while(f->next) f = f-> next;
            f ->next = new ListNode(tmp);
        }
        return result;
    }
};

//dummy node with a single pointer
class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr){
            int sum = carry;
            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next; 
            }
            if(l2 != nullptr){
                sum+=l2->val;
                l2 = l2->next;
            }
            carry = sum /10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        if(carry > 0){
            current->next = new ListNode(carry);
        }
        return dummy->next;
    }
};