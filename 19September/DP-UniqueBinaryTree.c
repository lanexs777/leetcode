# 96
DP邏輯 : G[i] 是長度為i時的結果 我們利用for把每一個都當作頭去算左右是剩餘數量的結果相乘
class Solution {
public:
    int numTrees(int n) {
        int G[n+1]={0};
        
        G[0]=1;
        G[1]=1;
        
        for(int i=2;i<=n;i++) {
            for(int j=1;j<=i;j++) {
                G[i] += G[j-1]*G[i-j];
            }
        }
        
        return G[n];
    }
};
