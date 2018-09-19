# 209
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int ans= INT_MAX;
        int n=nums.size();
        
        if(n==0) return 0;
        vector<int> sums(n);j
        sums[0]=nums[0];
        
        for(int i=1;i<n;i++){
            sums[i]=sums[i-1]+nums[i];
        }
        
        for(int i=0;i<n;i++) {            
            for(int j=i;j<n;j++) {
                int sum = sums[j]-sums[i]+nums[i];
                if(sum>=s) {
                    ans=min(ans, (j-i+1));
                    break;
                }
            }
        }
        return (ans==INT_MAX)? 0:ans;
    }
    
};

# using binary Search 
# lower_bound
# static_cast 其實跟int 是一樣的
＿
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int n = nums.size();
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0); //size = n+1 for easier calculations
        //sums[0]=0 : Meaning that it is the sum of first 0 elements
        //sums[1]=A[0] : Sum of first 1 elements
        //ans so on...
        for (int i = 1; i <= n; i++)
            sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 1; i <= n; i++) {
            int to_find = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), to_find);
            if (bound != sums.end()) {
                ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
    
};

# using two pointers;


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        
        int ans=INT_MAX;
        int n=nums.size();
        int left=0;
        
        if(n==0) return 0;
        
        int sum=0;
        
        for(int i=0;i<n;i++) {
            sum += nums[i];
            while(sum >= s) {
                ans=min(ans, (i-left+1));
                sum -= nums[left++];
            }
        }
        
        return (ans==INT_MAX)?0:ans;
        
        
    }
    
};
