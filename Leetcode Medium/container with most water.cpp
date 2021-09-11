class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i =0,j=n-1,ans = 0;
        while(i<j)
        {
            int h = min(height[i],height[j]);
            ans = max(ans,h*(j-i));
            if(h >= height[i] && i<j) i++;
            if(h >= height[j] && i<j) j--;
        }
        return ans;

    }
};
