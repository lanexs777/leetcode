# 669
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return NULL;
        if(root->val < L) return trimBST(root->right, L, R);
        if(root->val > R) return trimBST(root->left, L, R);
        root->left = trimBST(root->left, L, R);
        root->right=trimBST(root->right, L, R);
        return root;
    }
};



class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return NULL;
        
        // first get the right root
        while(root->val < L || root->val > R) {
            root= (root->val < L) ? root->right:root->left;
        }
        TreeNode *cur=root;
        while(cur) {
            while(cur->left && cur->left->val < L) {
                cur->left = cur->left->right;
            }
            cur=cur->left;
        }
        cur=root;
        
        while(cur) {
            while(cur->right && cur->right->val > R) {
                cur->right = cur->right->left;
            }
            cur=cur->right;
        }
        return root;
    }
};
