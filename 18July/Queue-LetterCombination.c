#17
// 利用queue 去存下一個要使用的字串 very clever !
// [a,b,c] --> [b,c,ad,ae,af] --> [c,ad,ae,af,bd,be,bf]

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> Map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        queue<string> q;
        vector<string> ans;
                
        if(digits.size()==0) return ans;
        q.push("");
        
        for(int i=0;i<digits.size();i++) {
            int d = digits[i]-'0';
            while(q.front().size()==i) {
                
                string qs=q.front();
                q.pop();
                for(int j=0;j<Map[d].size();j++) {
                    string add=qs+Map[d][j];
                    q.push(add);
                }
                
            }
            
        }
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
        
    }
};
