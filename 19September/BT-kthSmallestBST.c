# 230
# using recursive way :
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
    int result;
    int count=0;
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return result;
    }
    void traverse(TreeNode* root, int k) {
        if(root==NULL) return;
        traverse(root->left, k);
        count++;
        if(count==k) result=root->val;
        traverse(root->right, k);
    }
};
