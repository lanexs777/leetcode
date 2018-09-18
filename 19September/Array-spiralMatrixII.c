# 59
# 跟第一部分相同，利用一個j去調控儲存位置
# 也是一樣 從四個邊開始存
# 注意的地方是 動點是一開始就先建立好 vector<vector<int>> res 這個的空間(先分配好)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int k=1,i=0;
        while(k<=n*n) {
            int j=i;
            // top to down
            while(j<n-i) res[i][j++]=k++;
            j=i+1;
            //上到下
            while(j<n-i) res[j++][n-i-1]=k++;
            j=n-i-2;
            //左到右
            while(j>i) res[n-i-1][j--]=k++;
            j=n-i-1;
            //下到上
            while(j>i) res[j--][i]=k++;
            
            i++;
        }
        return res;
    }
    
};
