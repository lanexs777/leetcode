#173
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> s;
    void initialized(TreeNode* root) {
        TreeNode *node=root;
        while(node) {
            s.push(node);
            node=node->left;
        }
    }
    
public:
    
    BSTIterator(TreeNode *root) {
        initialized(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return(!s.empty());
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node=s.top();
        s.pop();
        initialized(node->right);
        return node->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
