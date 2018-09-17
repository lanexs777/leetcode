#103
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        deque<TreeNode*> cur,next;
        cur.push_back(root);
        vector<int> v;
        int level=0;
        
        while(!cur.empty()){
            auto tmp=cur.front();
            v.push_back(tmp->val);
            cur.pop_front();
            if(tmp->left) next.push_back(tmp->left);
            if(tmp->right) next.push_back(tmp->right);
            
            if(cur.empty()){
                if(level++ % 2) reverse(v.begin(), v.end());
                ans.push_back(v);
                v.clear();
                swap(cur, next);
            }
        }
        
        return ans;
    }
};

