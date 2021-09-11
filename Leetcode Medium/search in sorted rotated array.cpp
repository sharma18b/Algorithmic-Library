#define all(x) x.begin(),x.end()

class Solution {
public:
    int BS(vector<int>& a,int l,int h,int t)
    {
        if(l > h) return -1;
        int m = (l+h)/2;
        if(a[m]==t) return m;
        if(a[m] > t ) return BS(a,l,m-1,t);
        else return BS(a,m+1,h,t);

    }
    int findpivot(vector<int>& a,int l,int h)
    {
        if(l > h) return -1;
        if(l==h) return l;
        int m = (l+h)/2;
        if(m < h && a[m] > a[m +1]) return m;
        if(m > l && a[m-1] > a[m]) return m - 1;
        if(a[m] <= a[l] ) return findpivot(a,l,m-1);
        else return findpivot(a,m+1,h);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,h = n-1;
        int k = findpivot(nums,l,h);
        if(k ==-1)
        {
            return BS(nums,0,n-1,target);
        }
        else if (nums[k] == target) return k;
        else if (nums[0] <= target)
        {
            return BS(nums,0,k-1,target);
        }
        else {
            return BS(nums,k+1,n-1,target);
        }

    }
};
