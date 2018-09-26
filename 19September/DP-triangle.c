# 120
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int dp[n][n]={0};
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++) {
            dp[0][i] = dp[0][i-1]+triangle[i][i];
        }
        
        for(int i=1;i<n;i++) {
            dp[i][0] = dp[i-1][0]+triangle[i][0];
        }
              
        for(int i=1;i<n-1;i++) {
            for(int j=1;j<n-i;j++) {
                dp[i][j] = triangle[i+j][j]+min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        int Min=INT_MAX;
        
        for(int i=0;i<n;i++) {
            Min = min(Min, dp[i][n-i-1]);
        }
        
        return Min;
    }
};
