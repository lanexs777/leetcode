#5
// 建立一個dp去記錄 dp[j][i] 表示從 sj --> si 是否為一個回文
// dp[j][i]=1 是當 j==i 或是 si==sj &&  ( i-j<2 || dp[j+1][i-1]==1 // 也就是縮一格時也是回文 )
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int dp[n][n]= { {0} };
        int start=0;
        int right=0;
        int len=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                dp[j][i]=( s[j]==s[i] && ( i-j<2 || dp[j+1][i-1]==1 ) );
                if(dp[j][i] && len<i-j+1) {
                    len=i-j+1;
                    start=j;
                    right=i;
                }
            }
            dp[i][i]=1;
        }
        return s.substr(start,right-start+1);
    }
};
