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
    ListNode* merge2lists(ListNode* a,ListNode* b)
    {
        if(a==nullptr) return b;
        if(b==nullptr) return a;
        if(a->val <= b->val)
            {
                a->next = merge2lists(a->next,b);
            return a;
            }
        else
        {
            b->next = merge2lists(a,b->next);
            return b;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       if(lists.size()==0) return NULL;
       else
       {
           while(lists.size() > 1)
           {
               lists.push_back(merge2lists(lists[0],lists[1]));
               lists.erase(lists.begin());
               lists.erase(lists.begin());
           }
           return lists[0];
       }
    }
};
