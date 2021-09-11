vector<int> nsr(long long arr[],int n)
    {
        stack<int> s;
        vector<int> res(n,n);
        int i=0;
        while(i < n)
        {
            if(s.empty() || arr[s.top()] <= arr[i]) s.push(i++);
            else
            {
                int t = s.top();
                s.pop();
                res[t] = i;
            }
        }
        return res;
    }
    vector<int> nsl(long long arr[],int n)
    {
        stack<int> s;
        vector<int> res(n,-1);
        int i = n-1;
        while(i >= 0)
        {
            if(s.empty() || arr[s.top()] <= arr[i]) s.push(i--);
            else
            {
                int t = s.top();
                s.pop();
                res[t] = i;
            }
        }
        return res;
    }
    long long getMaxArea(long long arr[], int n)
    {
        long long maxarea  = 0,curr;
        //for (int i=0;i<n;i++)
        vector<int> right = nsr(arr,n);
        vector<int> left =  nsl(arr,n);
       // printArray(right);
        //printArray(left);
        for (int i=0;i<n;i++)
        {
            curr = arr[i]*(right[i] - left[i] - 1);
            maxarea = max(maxarea,curr);
        }
        //maxarea = max(maxarea,k*temp);
        return maxarea;
        // Your code here
    }
