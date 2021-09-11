class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        // int n = nums1.size();
        // int m = nums2.size();
        // if(n>m) return findMedianSortedArrays(nums2,nums1);
        // int lo =0,hi = n,mid1,mid2,l1,l2,r1,r2;
        // int total = n+m;
        // while(lo<=hi)
        // {
        //     int mid1 = (lo + hi)/2;
        //     int mid2 = (total+1)/2 - mid1;
        //     l1 = mid1==0 ? INT_MIN : nums1[mid1-1];
        //     l2 = mid2==0 ? INT_MIN : nums2[mid2-1];
        //     r1 = mid1==n ? INT_MAX : nums1[mid1];
        //     r2 = mid2==m ? INT_MAX : nums2[mid2];
        //     if(l1 <= r2 && l2 <= r1)
        //     {
        //         return total%2==0 ? (max(l1,l2) + min(r1,r2))/2.0 : max(l1,l2);
        //     }
        //     else if (l1 > r2)
        //     {
        //         hi = mid1-1;
        //     }
        //     else
        //     {
        //         lo = mid1 + 1;
        //     }
        // }
        // return 0.0;
        int n = A.size();
        int m = B.size();
        if(n > m) return findMedianSortedArrays(B,A);
        int l,h,l1,l2,r1,r2,mid1,mid2,tot = n+m;
        l = 0;
        h = n;

        while(l <= h)
        {
            mid1 = (l + h)/2;
            mid2 = (tot+1)/2 - mid1;
            l1 = (mid1 == 0) ? INT_MIN : A[mid1-1];
            l2 = (mid2 == 0) ? INT_MIN : B[mid2-1];
            r1 = (mid1 == n) ? INT_MAX : A[mid1];
            r2 = (mid2 == m) ? INT_MAX : B[mid2];
            //return 1.0;
            if(l1 <= r2 && r1 >= l2)
            {
                //return 1.0;
                return (tot%2==0) ? (max(l1,l2) + min(r1,r2))/2.0 : max(l1,l2);
            }
            else if(l1 > r2 )
            {
                ///return 2.0;
                h = mid1 - 1;
            }
            else
            {
                //return 3.0;
                l = mid1+1;
            }
        }
        return 0.0;

    }

};
