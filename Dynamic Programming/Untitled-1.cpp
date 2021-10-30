#include<bits/stdc++.h>
using namespace std;

typedef  long long ll;
typedef  long double ld;
typedef  pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define F_OR(i, a, b, s) for (ll i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(_VA_ARGS_, F_OR4, F_OR3, F_OR2, F_OR1)
#define forz(...) F_ORC(_VA_ARGS_)(_VA_ARGS_)
#define each(x, a) for (auto& x: a)
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define onBits(x) __builtin_popcount(x)

#define INF LLONG_MAX
#define F first
#define S second
#define pb push_back
#define pq priority_queue
#define vt vector
#define ar array
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define mid (l+r)/2
#define mod ll(1e9+7)
#define nod ll(998244353)
#define all(lf) lf.begin(),lf.end()
#define kira ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

ll power(ll x, ll y, ll m = mod)
{
    x = x%m;
    if(y==0) return 1LL;
    if(y%2) return (x*power((x*x)%m,y/2,m))%m;
    return power((x*x)%m,y/2,m);
}
ll modInv(ll x, ll m = mod)
{
    return power(x,m-2,m);
}

//ll u, v, w;
//vt<vt<ll>> adj[mxN];
//void init()
//{
//    forz(i,n) vis[i]=0, adj[i].clear();
//}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const ll mxN = 5000000;

ll n, m, k, ans;
vt<ll> adj[mxN];
vt<ll> f[mxN];
ll p[mxN][21], d[mxN], a[mxN];

void dfsP(ll x, ll pr=-1, ll dep = 0){
    // cout<<"4 "<<x<<endl;
    if(pr==-1){
        p[x][0]=x;
    }
    else 
        p[x][0]=pr;
    // cout<<"4 "<<x<<endl;
    d[x]=dep;
    // cout<<"4 "<<x<<endl;
    // cout<<dep<<endl;
    dep++;
    // cout<<adj[x].size()<<endl;
    for(ll y : adj[x]){
        // cout<<'g'<<endl;
        if(y!=pr)
            dfsP(y,x,dep);
    }
    // cout<<"4 "<<x<<endl;
}

ll LCA(ll x, ll y){
    if(d[x]<d[y])
        swap(x,y);
    
    ll dif = d[x]-d[y];
    forz(i,21)
        if((1<<i)&dif)
            x = p[x][i];
        
    
    if(x==y)
        return x;
    
    else{
        while(p[x][0]!=p[y][0]){
            ll i = 0;
            while(p[x][i+1]!=p[y][i+1]) i++;
            x=p[x][i];
            y=p[y][i];
        }
        return p[x][0];
    }
}

ll dfs(ll x, ll pr = -1){
    
    ll t = a[x];
    // cout<<2<<' '<<x<<endl;
    forz(i,adj[x].size()){
        ll y = adj[x][i];
        if(y!=pr){
            ll tm = dfs(y,x);
            if(tm>=0){
                ans++;
            }
            t+=tm;
        }
    }
    // cout<<"2 "<<x<<endl;
    return t;
}

void solve() 
{
    //Look at the limits dummy 😕 O
    // build(0,n-1,1);
    cin>>n;
    ll x, y;
    forz(n){
        adj[i].clear();
        f[i].clear();
        a[i]=0;
    }
    ans = 0;
    forz(n-1){
        cin>>x>>y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    forz(n){
        cin>>x;
        f[x-1].pb(i);
    }
    dfsP(0);
    forz(i,1,21){
        forz(j,n){
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }

    forz(i,n){
        ll l = -1;
        for(ll el:f[i]){
            if(l==-1){
                l=el;
            }
            else{
                l = LCA(l,el);
            }
            a[el]--;
        }
        a[l]+=f[i].size();
    }
    // cout<<"14"<<endl;
    dfs(0);

    cout<<ans<<'\n';

}

int32_t main()
{
    rlimit R;
	getrlimit(RLIMIT_STACK, &R);
	R.rlim_cur = R.rlim_max;
	setrlimit(RLIMIT_STACK, &R);
    kira;
    ll T=1;
    cin>>T;

    forz(i,1,T+1)
    {
        cout<<"Case #"<<i<<": ";
        // cout<<endl;
        solve();
        // cout<<endl;
    }
}