# 621
# 先把最常出現的分散到各組
# example AAAACCEEBBGGG n=3
# A---A---A---A

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> pool(26,0);
        for(int i=0;i<tasks.size();i++) {
            pool[tasks[i]-'A']++;
        }
        sort(pool.begin(), pool.end());
        int mx=pool[25];
        int flag=25;
        int len=tasks.size();
        while(pool[flag]==mx) flag--;
        return max(len, (n+1)*(mx-1)+25-flag);
        
    }
};
