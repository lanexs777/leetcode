# 62
# 為了怕太大，可以邊成邊除
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;// how much steps we need to do
            int k = m - 1; // number of steps that need to go down
            double res = 1;
            
            for (int i = 1; i <= k; i++)
                res = res * (N - k + i) / i;
            return (int)res;
    }
};
