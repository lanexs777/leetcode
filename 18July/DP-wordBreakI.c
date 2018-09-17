#139
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        //dp[i]==true 表示s[0...i] 可以被字典組合成
        bool dp[s.size()]={false};
        
        for(int i=0;i<s.size();i++) {
            for(int j=0;j<=i;j++) {
                
                string tmp=s.substr(j,i+1-j);
                
                vector<string>::iterator it=find(wordDict.begin(), wordDict.end(), tmp);
                //當找到且是開頭或是前面可以被字典組合成
                if(it!=wordDict.end() && (j==0 || dp[j-1])) {
                    dp[i]=true;
                    break;
                }
            }
        }
        
        return dp[s.size()-1];
                
    }
};
