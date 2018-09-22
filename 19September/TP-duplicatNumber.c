# 287
# brute force way :
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n, j!=i;j++) {
                if(nums[i]==nums[j]) return nums[i];
            }
        }
    }
};

# find  circle way

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n>0) {
            int slow=nums[0];
            int fast=nums[nums[0]];
            
            while(slow!=fast) {
                slow=nums[slow];
                fast=nums[nums[fast]];
            }
            int find=0;
            while(find!=slow) {
                find=nums[find];
                slow=nums[slow];
            }
            return find;
        }
    }
};
