class Solution {
public:
    double get(double x,int n)
    {
        if(n==0) return 1;
       if(n==1) return x;
        if(n%2==0) 
        {
            double t = get(x,n/2);
            return t*t;
        }
        else 
        {
            double t = get(x,n/2);
            return t*t*x;
        }
    }
    double myPow(double x, int n) {
       if(x==0) return 0;
        double f,ans;
        if(n < 0)
        {   f = 1/x;
        return get(f,n);
        }
        else return get(x,n);
        
        
    }
};