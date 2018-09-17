#240
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        
        int col=matrix[0].size()-1;
        int row=0;
            
        while(1){
            
            //每次都跟最右邊的進行比較 如果target比較大 表示target不會再那個row了
            if(target>matrix[row][col]) {
                row++;
            }
            //如果target比較小，表示target不會再那個col了
            else if(target<matrix[row][col]) {
                col--;
            }
            else{
                return true;
            }
            
            if(row<0 || row > matrix.size()-1) break;
            if(col<0 || col > matrix[0].size()-1) break;
        }
        
        return false;
        
    }
};
