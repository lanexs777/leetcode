#94
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //using stack can do inorder with iterative;
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> Stack;
        TreeNode* current=root;
        int done=0;
        
        while(!done) {
            if(current!=NULL) {
                Stack.push(current);
                current=current->left;
            }
            else {
                if(!Stack.empty()) {
                    current=Stack.top();
                    ans.push_back(current->val);
                    Stack.pop();
                    current=current->right;
                }
                else {
                    done=1;
                }
            }
        }
        return ans;
    }
};

