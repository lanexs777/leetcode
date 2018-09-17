#22
// 本題利用遞迴
// 注意，一定要先有"(" 才可能有 ")" ，call 完recursive時 記得將原本string 變回來 (參照line 22, line 28)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr="";
        helper(curr, ans, n, 0, 0);
        return ans;
    }
    void helper(string curr, vector<string>& ans, int n, int left, int right) {
        string tmp;
        if(right==n) {
            ans.push_back(curr);
            return;
        }
        if(left<n) {
            tmp=curr;
            curr=curr+"(";
            helper(curr, ans, n, left+1, right);
            curr=tmp;
        }
        if(left>right) {
            tmp=curr;
            curr=curr+")";
            helper(curr, ans, n, left, right+1);
            curr=tmp;
        }
    }
};
