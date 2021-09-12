class Solution {
public:
//     int removeBoxes(vector<int>& boxes) {
//         int n = boxes.size();
//         int dp[100][100][100] = {};
//         return helper(boxes, 0, n - 1, 0, dp);
//     }
//     int helper(vector<int>& boxes, int i, int j, int k, int dp[100][100][100]) {
//         if (j < i) return 0;
//         if (dp[i][j][k] > 0) return dp[i][j][k];
//         int res = (1 + k) * (1 + k) + helper(boxes, i + 1, j, 0, dp);
//         for (int m = i + 1; m <= j; ++m) 
//             if (boxes[m] == boxes[i]) 
//                 res = max(res, helper(boxes, i + 1, m - 1, 0, dp) + helper(boxes, m, j, k + 1, dp));
            
//         return dp[i][j][k] = res;
//     }
    int removeBoxes(vector<int>& boxes) {
        int dp[100][100][100] = {};
        int n = boxes.size();
        return helper(0,0,n-1,boxes,dp);
    }
    int helper(int k,int i,int j,vector<int>& boxes,int dp[100][100][100])
    {
        if(j < i) return 0;
        if(dp[i][j][k] > 0) return dp[i][j][k]; 
        int res = (k+1)*(k+1) + helper(0,i+1,j,boxes,dp);
        for (int m = i+1;m <= j;m++)
        {
            if(boxes[i]==boxes[m])
            {
                res = max(res,helper(0,i+1,m-1,boxes,dp) + helper(k+1,m,j,boxes,dp));
            }
        }
        dp[i][j][k] = res;
        return res;
    }
};