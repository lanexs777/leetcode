// Array [medium] #11
#include<iostream>
#include<vector>
#include<algorithm>
// main idea. 
// 由兩邊開始，選擇較短的一邊往內移動(因為水池的大小是由短邊的決定)，一直到完成運算(left>=right)
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int maxarea=0;
            for(int i=0;i<height.size();i++) {
                for(int j=i+1;j<height.size();j++) {
                    maxarea= max(maxarea, min(height[i], height[j])*(j-i) );

                }
            }
            cout<<maxarea<<endl;
        }
        int maxArea2(vector<int>& height) {
            int left=0;
            int right= (height.size()-1);
            int maxarea=0;
            while(1){
                maxarea=max(maxarea, min(height[left], height[right])*(right-left) );         

                if(height[left]<height[right]) {
                    left++;
                }
                else {
                    right--;
                }
                if(left>=right) {
                    break;
                }
            }
            cout<<maxarea<<endl;

        }
};

int main() {

    Solution S1;
    vector<int> height{1,8,6,2,5,4,8,3,7};
    S1.maxArea(height);
    S1.maxArea2(height);

}
