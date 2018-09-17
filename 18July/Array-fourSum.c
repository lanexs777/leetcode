//#18
//改寫3Sum 即可 (注意duplicate)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
            // sorted first
        if(nums.size()<4) return res;
        sort(nums.begin(), nums.end());
            
        for(int j=0;j<nums.size()-3;j++) {
            int target2=-nums[j];
            
            for(int i=j+1;i<nums.size()-2;i++) {
                int target3=-nums[i];
                int front=i+1;
                int back=nums.size()-1;
    
                while(front < back) {   
                    int sum=nums[front]+nums[back]-target2-target3;
                    if(sum > target) {
                        back--;
                    }
                    else if(sum < target) {
                        front++;
                    }
                    else {
                        vector<int> tmp;
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[front]);
                        tmp.push_back(nums[back]);
                        res.push_back(tmp);
                        
                        //reduce duplication
                        while(front<back && nums[front]==tmp[2]) front++;
                        //reduce duplication
                        while(front<back && nums[back]==tmp[3]) back--;                            
                    }
                    //reduce duplication
                    while(i<nums.size()-2 && nums[i]==nums[i+1]) i++;
                }   
            }
            while(j<nums.size()-3 && nums[j]==nums[j+1]) j++;
        }
        return res;
    }   
};
