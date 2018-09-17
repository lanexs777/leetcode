# 想成四個頂點的互換 然後慢慢向內縮

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
                
        int a=0;
        int i=0;
        int b=matrix[0].size()-1;
        while(b>a) {
            
            for(int i=0;i<(b-a);i++) {
                swap(matrix[a][a+i], matrix[a+i][b]);
                swap(matrix[a][a+i], matrix[b][b-i]);
                swap(matrix[a][a+i], matrix[b-i][a]);  
            }
            
            a++;
            b--;
        }
        
    }
};
