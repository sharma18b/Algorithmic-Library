#include <bits/stdc++.h>
using namespace std;


void printvvi(vector<vector<int>> v,int n)
{
  for (int i=0;i<n;i++)
  {
    for (int j=0;j<n;j++)
    {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

bool check(vector<vector<int>> &v,int r,int c,int n)
{
   for (int i=0;i<=r;i++)
  {
    if(v[i][c]==1) return false;
  }
  for (int i=0;i<=c;i++)
 {
   if(v[r][i]==1) return false;
 }
  int x,y;
  x = r,y = c;
  while(x>=0 && y<n)
  {
    if(v[x][y]==1) return false;
    x--;y++;
  }
  x =r,y = c;
  while(x>=0 && y>=0)
  {
    if(v[x][y]==1) return false;
    x--;y--;
  }
 return true;
}


void nqueens(vector<vector<int>> &ans,vector<vector<int> > v,int i,int j,int n,int curr){
if (i>=n && curr<n) return;
else if(i==n && curr==n)
  {
    ans = v;
    return;
  }
  int ni = i;int nj=j;
  if(j==n-1)
  {
    ni = i+1;
    nj =0;
  }
  else ni = i,nj = j+1;
  if(check(v,i,j,n))
  {
    v[i][j] = 1;
    nqueens(ans,v,ni,nj,n,curr+1);
    v[i][j] = 0;
  }
    nqueens(ans,v,ni,nj,n,curr);
}

int main(){
   int n = 5;
  // cout << "Enter the number of queens you want to arrange in an N X N chessboard : ";
  // cin >> n;
  for(int i=0;i<=8;i+=2)
  {
    n = i;
    vector<vector<int>> ans(n,vector<int> (n,0));
    vector<vector<int>> a(n,vector<int> (n,0));
    nqueens(ans,a,0,0,n,0);
    printvvi(ans,n);
    cout << endl;
  }

}
