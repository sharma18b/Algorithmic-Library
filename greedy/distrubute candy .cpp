#include <bits/stdc++.h>
int Solution::candy(vector<int> &A) {
    vector<int> c(A.size(), 1);
    for(int i=1;i <A.size() ;i++)if(A[i]>A[i-1])c[i] = 1+c[i-1];
    for(int i =A.size() -2; i>=0; i--)if(A[i]>A[i+1])c[i] = max(c[i], 1+c[i+1]);
    return accumulate(c.begin(), c.end(), 0);

}
