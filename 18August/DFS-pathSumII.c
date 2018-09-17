#113
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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return res;
        vector<int> current;
        sum = sum - root->val;
        current.push_back(root->val);
        
        //確認不是root
        if(sum==0 && !(root->right) && !(root->left) ) {
            res.push_back(current);
            return res;
        }
        
        find(root->right, current, sum);
        find(root->left, current, sum);
        return res;
    }
    void find(TreeNode* root, vector<int> current, int sum) {
        if(root) {
            sum =sum - root->val;
            current.push_back(root->val);
            if(!(root->left) && !(root->right) && sum==0) {
                res.push_back(current);
                return;
            }
            else {
                find(root->right, current, sum);
                find(root->left, current, sum);
            }
        }
        
    }
};
