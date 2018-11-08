# 398
class Solution {
public:
    Solution(vector<int> nums):v(nums) {
    
    }
    
    int pick(int target) {
        int cnt=0, res=-1;
        for(int i=0;i<v.size();++i) {
            if(target != v[i]) continue;
            ++cnt;
            if(rand()%cnt==0) res=i;
        }
        return res;
    }
    vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
