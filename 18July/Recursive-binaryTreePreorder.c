#144
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
    vector<int> ans;
    void traverse(TreeNode* node) {
        if(node==NULL) return;
        ans.push_back(node->val);
        traverse(node->left);
        traverse(node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return ans;
    }
    
};
