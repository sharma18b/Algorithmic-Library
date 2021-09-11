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
    vector<TreeNode*> helper(int s,int e)
    {
        if(s>e) return {NULL};
        vector<TreeNode*> ans;
        for (int i=s;i<=e;i++)
        {
            vector<TreeNode*> left1;
            vector<TreeNode*> right1;
            left1 = helper(s,i-1);
            right1 = helper(i+1,e);
            for (auto x : left1)
            {
                for (auto y : right1)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = x;
                    root->right = y;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode*> ();
        return helper(1,n);

    }
};
