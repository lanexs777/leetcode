#1
#include<iostream>
#include<vector>
using namespace std;

// two loop
class Solution {
public:
	Solution(){}
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans;
		for(vector<int>::iterator it=nums.begin(); it!=nums.end();it++) {
			for(vector<int>::iterator it2=it+1; it2!=nums.end();it2++) {
				if((*it) + (*it2) == target) {
					int dis1 = distance(nums.begin(), it);
					int dis2 = distance(nums.begin(), it2);
					ans.push_back(dis1);
					ans.push_back(dis2);
				}
			}
		}
		return ans;
	}

};

//--------------------------------------------------------------------------------------

// hash map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> Map;
        int res;
        
        for(int i=0;i<nums.size();i++) {
            res=target-nums[i];
            
            unordered_map<int,int>::iterator it;
            it=Map.find(res);
            
            if(it!=Map.end()) {
                return vector<int>({it->second,i});
            }
            Map[nums[i]]=i;
            
        }
    }
};
