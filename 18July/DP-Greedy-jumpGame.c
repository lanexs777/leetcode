#55
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last_pos = nums.size() - 1;
        for(int j=nums.size()-1;j>=0;j--) {
            if(j+nums[j]>=last_pos) {
                last_pos = j;
            }
        }
        return last_pos == 0;
    }
};
