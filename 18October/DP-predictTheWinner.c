# 486
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int dp[n][n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                dp[i][j]=0;
            }
        }
        
        for(int e=n;e>=0;e--) {
            for(int s=e+1;s<n;s++) {
                int a=nums[e]-dp[e+1][s];
                int b=nums[s]-dp[e][s-1];
                dp[e][s]=max(a,b);
            }
        }
        
        return dp[0][n-1]>=0;
        
    }
};
