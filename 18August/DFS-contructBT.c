#105
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 重點流程:
  1.持續加入preorder的值進入stack裡面直到遇到與inorder相同者(一邊同時在node的左邊加上node)
  2.相同時，則開始pop stack裡面的值，直到與inorder 不同(併記錄flag=1)
  3.當flag=1時 與第1步做一樣的動作，唯獨node是加在node的右邊。 (併set flag=0)
  
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size()==0)
         return NULL;
        int i,j,f;
        i=j=f=0;
        TreeNode *root, *t;
        stack<TreeNode*> st;
        stack<int> s;
        
        root= new TreeNode(preorder[i]);
        st.push(root);
        s.push(preorder[i]);
        t=root;
        i++;
        
        while(i<preorder.size()) {
            if(!st.empty() && st.top()->val == inorder[j]) {
                t=st.top();
                st.pop();
                s.pop();
                f=1;
                j++;
            }
            else {
                if(f==0) {
                    s.push(preorder[i]);
                    t->left = new TreeNode(preorder[i]);
                    t=t->left;
                    st.push(t);
                    i++;
                }
                else {
                    f=0;
                    s.push(preorder[i]);
                    t->right=new TreeNode(preorder[i]);
                    t=t->right;
                    st.push(t);
                    i++;
                }
            }
        }
        return root;
    }
};
