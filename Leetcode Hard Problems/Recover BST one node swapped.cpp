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
    TreeNode* first, *last,*prev;
    void inorder(TreeNode* root)
    {
        if(!root) return;
        TreeNode* curr = root;
        while(curr!=NULL)
        {
            if(!(curr->left))
            {
                if(prev!=NULL && prev->val > curr->val)
                {
                    if(first==NULL)
                    {
                        first = prev;
                        last = curr;
                    }
                    else last = curr;
                }
                prev = curr;
                curr = curr->right;
            }
            else
            {
                TreeNode* pred = curr->left;
                while(pred->right!=NULL && pred->right!=curr)
                {
                    pred = pred->right;
                }
                if(pred->right==NULL)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    if(prev!=NULL && first==NULL && prev->val > curr->val)
                    {
                        first = prev;
                        last = curr;
                    }
                    else if(prev!=NULL && first!=NULL && prev->val > curr->val)
                    {
                        last = curr;
                    }
                    prev = curr;
                    pred->right = NULL;
                    curr = curr->right;
                }
            }
        }
        //inorder(root->left);
        // if(prev!=NULL)
        // {
        //     if(prev->val > root->val)
        //     {
        //         if(first==NULL) first = prev,last = root;
        //         else last = root;
        //     }
        // }
        // prev = root;
        // // some operation
        // inorder(root->right);
        int x = first->val;
        first->val = last->val;
        last->val = x;
        return;
    }
    void recoverTree(TreeNode* root) {
        first = NULL,last =NULL,prev = NULL;
        inorder(root);
        // int x = first->val;
        // first->val = last->val;
        // last->val = x;
        return;
    }
};
