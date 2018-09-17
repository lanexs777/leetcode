//Array [medium] #15
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> res;
            // sorted first
            sort(nums.begin(), nums.end());
            
            for(int i=0;i<nums.size();i++) {
                int target=-nums[i];
                int front=i+1;
                int back=nums.size()-1;
    
                while(front < back) {   
                    int sum=nums[front]+nums[back];
                    if(sum > target) {
                        back--;
                    }
                    else if(sum < target) {
                        front++;
                    }
                    else {
                        vector<int> tmp;
                        tmp.push_back(-target);
                        tmp.push_back(nums[front]);
                        tmp.push_back(nums[back]);
                        res.push_back(tmp);
                        
                        //reduce duplication
                        while(front<back && nums[front]==tmp[1]) front++;
                        //reduce duplication
                        while(front<back && nums[back]==nums[2]) back--;
                            
                    }
                    //reduce duplication
                    while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
                }   
            
            
            }

            return res;
        
        }
        
        

    };
