#34
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int l=0;
        int r=nums.size()-1;
        while(l<=r) {
            int mid=(l+r)/2;
            //當找到時，開始
            if(target==nums[mid]) {
                
                int ls=mid;
                while(nums[ls-1]==target && ls!=0 ) ls--;
                int rs=mid;
                while(nums[rs+1]==target && rs!=nums.size()-1) rs++;
                ans.push_back(ls);
                ans.push_back(rs);
                return ans;
                
            }
            //非常一般的binary search 
            if(target>nums[mid]) {
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
            
    }
};
