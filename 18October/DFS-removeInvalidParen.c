# 301

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        // check the input is valid or not
        int l=0;
        int r=0;
        // count how many left and right need to be remove
        for(const char ch : s){
            l += (ch=='(');
            if(l==0)
                r+=(ch==')');
            else
                l -= (ch==')');
        }
        vector<string> ans;
        dfs(s,0,l,r,ans);
        return ans;
         
    }
    bool isvalid(const string &s) {
        int count=0;
        for(const char ch:s) {
            if(ch=='(') ++count;
            if(ch==')') --count;
            if(count<0) return false;
        }
        return count==0;
    }
    
    void dfs(const string &s, int start, int l, int r, vector<string>&ans) {
        if(l==0 && r==0) {
            if(isvalid(s)) ans.push_back(s);
            return;
        }
        for(int i=start; i<s.length();i++) {gt
            
            //only remove the first duplicate one
            if(i!=start && s[i]==s[i-1]) continue;
                        
            if(s[i]=='(' || s[i]==')') {
                string curr=s;
                curr.erase(i,1);
                if(r>0 && s[i]==')') dfs(curr, i, l, r-1, ans);
                else if(l>0 && s[i]=='(') dfs(curr, i, l-1, r, ans);
            }
            
        }
    }   
    
};









