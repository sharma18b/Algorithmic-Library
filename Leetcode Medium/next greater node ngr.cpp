vector<int> nextLargerNodes(ListNode* head) {
        stack<int> s;
        vector<int> ori;
        ListNode* tmp = head;
        while(tmp)
        {
            ori.push_back(tmp->val);
            tmp = tmp->next;
        }
        int n = ori.size();
        vector<int> res(n,0);
        int i=0;
        while(i< n)
        {
            if(s.empty() || ori[s.top()] >= ori[i]) s.push(i++);
            else
            {
                int t = s.top();
                s.pop();
                res[t] = ori[i];
            }
        }
        return res;
    }
