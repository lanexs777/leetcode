#376

//利用兩個array去記錄，如果遇到更大的 就利用down[i-1]去更新up[i] 
//想成前一個當作down的有連續幾個sequence


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        
        int up[nums.size()];
        int down[nums.size()];
        up[0]=1;
        down[0]=1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]>nums[i-1]) {
                up[i]=down[i-1]+1;
                down[i]=down[i-1];
            }
            else if(nums[i]<nums[i-1]) {
                up[i]=up[i-1];
                down[i]=up[i-1]+1;
            }
            else{
                up[i]=up[i-1];
                down[i]=down[i-1];
            }
        }
        return max(up[nums.size()-1], down[nums.size()-1]);
    }
};

//利用兩個值去記錄且比較 prediff, diff. 當一正一負時可以將count+1
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if(nums.size()<2) return nums.size();
        int prediff=nums[1]-nums[0];
        int count=prediff!=0? 2:1;
        
        for(int i=2;i<nums.size();i++) {
            int diff=nums[i]-nums[i-1];
            if( (diff>0 && prediff<=0) || (diff<0 && prediff>=0) ) {
                count++;
                prediff=diff;
            }
        }
        return count;
        
        
    }
};
