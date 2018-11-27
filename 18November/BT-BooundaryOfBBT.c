# 545
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        if(root->left || root->right) res.push_back(root->val);
        leftBoundary(root->left, res);
        leave(root, res);
        rightBoundary(root->right, res);
        return res;
    }
    void leftBoundary(TreeNode * node, vector<int> &res) {
        if(!node || (!node->left && !node->right) ) return;
        res.push_back(node->val);
        if(!node->left) leftBoundary(node->right, res);
        else leftBoundary(node->left, res);
    }
    void rightBoundary(TreeNode * node, vector<int> &res) {
        if(!node || (!node->left && !node->right)) return;
        if(!node->right) rightBoundary(node->left, res);
        else rightBoundary(node->right, res);
        res.push_back(node->val);
    }
    void leave(TreeNode* node, vector<int> &res) {
        if(!node) return;
        if(!node->left && !node->right) 
            res.push_back(node->val);
        leave(node->left, res);
        leave(node->right, res);
    }
    
};
