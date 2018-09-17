# 31
# 思路 :  從尾端開始找第一個不是遞增的數字(position a)，找到後跟剛好比它大的數字互換位置，reverse position a 以後的數字
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i + 1);  
    }
    void swap(vector<int>& nums, int i, int j) {
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }
    void reverse(vector<int>& nums, int start) {
        int i = start, j = nums.size() - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
};
