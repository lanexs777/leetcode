#74
// 先作row的Binary Search 再做col的b

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        
        int lo=0;
        int hi=matrix.size()-1;
        int row;
                      
        while(lo<=hi) {
            
            if(matrix.size()==1) {
                row=0;
                break;
            }
            
            int mid=(lo+hi)/2;
            if(target>matrix[mid][matrix[mid].size()-1]) {
                lo=mid+1;
            }
            else if(target<matrix[mid][0]) {
                hi=mid-1;
            }
            else{
                row=mid;
                break;
            }            
        }
        
        int l=0;
        int r=matrix[row].size()-1;
        while(l<=r) {
            int mid2=(r+l)/2;
            if(target==matrix[row][mid2]) return true;
            if(target > matrix[row][mid2] && mid2+1<=r) {
                l=mid2+1;
            }
            else if(target < matrix[row][mid2] && mid2-1>=l){
                r=mid2-1;
            }            
            else {
                return false;
            }
        }
         return false; 
        
        
    }
};
