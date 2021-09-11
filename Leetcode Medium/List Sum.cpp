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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1,*t2 = l2;
        ListNode* ans = new ListNode(-1);
        int z = 0,c =0;
        ListNode *temp = ans;
        while(t1 && t2)
        {
            z =( t1->val + t2->val + c ) %10;
            c = ( t1->val + t2->val + c ) /10;
            ListNode *node = new ListNode(z);
            temp->next = node;
            temp = temp -> next;
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1)
        {
            z =( t1->val + c )%10;
            c = ( t1->val + c )/10;
            ListNode *node = new ListNode(z);
            temp->next = node;
            temp = temp -> next;
            t1 = t1->next;
        }
        while(t2)
        {
            z =( t2->val + c )%10;
            c = ( t2->val + c )/10;
            ListNode *node = new ListNode(z);
            temp->next = node;
            temp = temp -> next;
            t2 = t2->next;
        }
        if(c!=0)
        {
            ListNode *node = new ListNode(c);
            temp->next = node;
        }
        return ans->next;


    }
};
