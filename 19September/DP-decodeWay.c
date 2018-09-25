# 91
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n==0) return 0;
        int dp[n+1]={0};
        dp[n]=1;
        dp[n-1]=s[n-1]!='0'?1:0;
        for(int i=n-2;i>=0;i--) {
            if( (s[i]=='2'&&s[i+1]<='6') || s[i]=='1' ) {
                dp[i]+=dp[i+2];
            }
            if(s[i]>='1' && s[i]<='9') {
                dp[i]+=dp[i+1];
            }
        }
        return dp[0];
    }
};
