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
