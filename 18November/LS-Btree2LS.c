# 426
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    void inorder(Node* n, Node*& pre, Node*& head) {
        if(!head && n->left==NULL) {
            // means this is head
            head=n;
            pre=n;
        }
        Node* left=n->left;
        Node* right=n->right;
        
        //process left
        if(left) inorder(left, pre, head);
        //process current
        pre->right=n;
        n->left=pre;
        pre=n;
        //process right
        if(right) inorder(right, pre, head);
        
    }
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        Node* pre=NULL;
        Node* head=NULL;
        inorder(root, pre, head);
        head->left=pre;
        pre->right=head;
        return head;
    }
};
