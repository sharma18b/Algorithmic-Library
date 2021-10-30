#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+ 7;
int dp[105];

int choose(int n,int r)
{
    int res = 1,k = 1;
    while(r--)
    {
        res = ((res*(n--))/(k++))%mod;
    }
    return res;
}


int log2(int n)
{
    int i=0,j = 1;
    while(j <= n)
    {
        i++;
        j *= 2;
    }
    return i-1;
}
int left(int n)
{
    // //if(n==1) return 0;
    // int h = log2(n);
    // int k = pow(2,h-1);
    // cout << k << " k  & n " << n << endl;
    // int l = k - 1 + min(k , n - k*2 + 1); 
    // return l;
    if (n == 1)
        return 0;
 
    int h = log2(n);
 
    // max number of elements that can be present in the
    // hth level of any heap
    int numh = (1 << h); //(2 ^ h)
 
    // number of elements that are actually present in
    // last level(hth level)
    // (2^h - 1)
    int last = n - ((1 << h) - 1);
 
    // if more than half-filled
    if (last >= (numh / 2))
        return (1 << h) - 1; // (2^h) - 1
    else
        return (1 << h) - 1 - ((numh / 2) - last);
}

int get_ways_to_form_max_heap(int n)
{
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];
    int l = left(n);
    //cout << n  << " n & l " << l <<  endl;;
    int ans = choose(n-1,l)%mod;
    //cout << ans << endl;
    ans = (choose(n-1,l)*(get_ways_to_form_max_heap(l)*get_ways_to_form_max_heap(n-l-1)))%mod;
    dp[n] = ans;
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    cout << get_ways_to_form_max_heap(n) << endl;
    //cout << left(5) << " " << left(4) << endl;
}