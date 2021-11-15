// https://codeforces.com/blog/entry/69542
// problemlink 
// Well Known Coding problem finding the product with the max rating in a given price range
// Q queries given for price ranges O(q*long(n)) 
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int N  = 1e4;
int tree[N];
void build(vector<int> a,int n,int str,int en)
{
    if(str == en)
    {
        tree[n] = a[str];
        return;
    }
    int mid = (str + en)/2;
    build(a,2*n+1,str,mid);
    build(a,2*n+2,mid+1,en);   
    tree[n] = max(tree[2*n+1],tree[2*n+2]);cout << n << " " <<  tree[n] << endl;
}

int queries(int n,int str,int en,int l,int r)
{
    if(l <= str && r >= en) return tree[n];
    if(l > en || str > r) return -1;
    int mid = (str+en)/2;
    return max(queries(2*n+1,str,mid,l,r), queries(2*n+2,mid+1,en,l,r));
}


vector<int> nu(int n,vector<int> prices,vector<int> ratings,vector<vector<int>> query,int q)
{
    vector<int> ans(q);
    vector<pair<int,int>> v;
    for (int i=0;i<n;i++)
    {
        v.push_back({prices[i],ratings[i]});
    }
    sort(v.begin(),v.end());
    vector<int> vp,vr;
    for (auto i : v) 
    {
        vp.push_back(i.first),vr.push_back(i.second);
    }
    build(vr,0,0,n-1);
    int k=0;
    for (int i=0;i<q;i++)
    {
         int l = lower_bound(vp.begin(),vp.end(),query[i][0]) - vp.begin();
         int r = upper_bound(vp.begin(),vp.end(),query[i][1]) - vp.begin();
         if(l==r) ans[i] = vr[l];
         else ans[i] = queries(0,0,n-1,l,r-1);
    }
    return ans;
}



int main(){
    int n,q;
    cin >> n;
    vector<int> prices(n);
    vector<int> ratings(n);
    for (int i=0;i<n;i++)
    {
        cin >> prices[i] >> ratings[i];
    }
    cin >> q;
    vector<vector<int>> query(q,vector<int> (2));
    for (int i=0;i<q;i++)
    {
        cin >> query[i][0] >> query[i][1];
    }
    vector<int> ans1 = nu(n,prices,ratings,query,q);
    for (auto i : ans1) cout << i << " " << endl;
    cout << endl;
    return 0;
}