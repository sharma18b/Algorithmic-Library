vector<int> nearest_in_right(vector<int> a)
{
  int n = a.size();
  stack<int> s;
  vector<int> l(n,0);
  for (int i=n-1;i>=0;i--)
  {
    while(!s.empty() && a[s.top()] < a[i])
    {
      s.pop();
    }
    if(s.empty())
    {
      l[i] = 0;
      s.push(i);
    }
    else
    {
      l[i] = a[s.top()];
      s.push(i);
    }
  }
  return l;
}


vector<int> ngr(vector<int> a,int n)
{
  vector<int> res(n,n);
  stack<int> s;
  int i = 0;
  while(i < n)
  {
    if(s.empty() || a[s.top()] >= a[i]) s.push(i);
    else 
    {
      int t = s.top();
      s.pop();
      res[t] = i;
    }
  }
  return res;



  for (int i=0;i<n;i++)
}
