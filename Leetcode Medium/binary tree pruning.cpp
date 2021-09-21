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
    int summ(TreeNode* root)
    {
        if(!root) return 0;
        int l=0,r=0;
        if(!root->left && !root->right)
        {
            return root->val;
        }
        if (root->left)
        {
            l = summ(root->left);
            if(l==0) root->left = NULL;
        }
        if (root->right)
        {
            r = summ(root->right);
            if(r==0) root->right = NULL;
        }
        return l + r + root->val;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return root;
        int k = summ(root);
        if(k==0) return NULL;
        return root;
    }
};