/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int mps(TreeNode* root ,int &ans)
    {
        if(!root) return 0;
        int l=0,r=0;
        if(root->left)
        {
            l = mps(root->left,ans);
        }
        if(root->right)
        {
            r = mps(root->right,ans);
        }
        if(l < 0) l = 0;
        if(r < 0) r = 0;
        ans = max(ans,max(root->val,l + r + root->val));
        return max(root->val , root->val + max(l,r));
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int a = mps(root,ans);
        return max(ans,a);
    }
};
