# 85
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res=0;
        vector<int> height;
        for(int i=0;i<matrix.size();i++) {
            height.resize(matrix[i].size());
            for(int j=0;j<matrix[i].size();j++) {
                height[j] = matrix[i][j] == '0'? 0:(1+height[j]);
            }
            res=max(res, largestRecArea(height));
        }
        return res;
    }
    
    int largestRecArea(vector<int> &height) {
        int res=0;
        for(int i=0;i<height.size();i++) {
            if(i+1 < height.size() && height[i] <= height[i+1]) 
                continue;
            int minH=height[i];
            for(int j=i;j>=0;j--) {
                minH=min(minH, height[j]);
                int area=minH * (i-j+1);
                res=max(res, area);
            }
        }
        return res;
    }
};
