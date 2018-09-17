# 54
# 想成各個4邊分別做 順序 : 上 右 下 左 利用 r1, r2, c1 ,c2 進行辦別
# 左上的座標是 (c1,r1) 右下的座標是(c2,r2)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        int r1=0, c1=0;
        
        int r2=matrix.size()-1;
        if(r2<0) return res;
        int c2=matrix[0].size()-1;
        if(c2<0) return res;
              
        while(r2>=r1 && c2>=c1) {
            
            for(int c=c1;c<=c2;c++) res.push_back(matrix[r1][c]);
            for(int r=r1+1;r<=r2;r++) res.push_back(matrix[r][c2]);
            if(r1<r2 && c1<c2) {
                for(int c=c2-1;c>c1;c--) res.push_back(matrix[r2][c]);
                for(int r=r2;r>r1;r--) res.push_back(matrix[r][c1]);
            }
            
            r1++;
            c1++;
            r2--;
            c2--;            
        }
        return res;
    }
};
