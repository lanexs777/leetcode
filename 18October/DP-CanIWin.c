# 464
class Solution {
public:
    bool canIWin(int M, int T) {
        if(M>=T) return true;
        int S=M*(M+1)/2;
        if(T>S) return false;
        if(S==T) return M%2;
        unordered_map<int, bool> m;
        return dfs(M, T, 0, m);
    }
    bool dfs(int M, int T, int k, unordered_map<int, bool>& m) {
        if(T<=0) return false;
        if(m.count(k)) return m[k];
        for(int i=0;i<M;++i) {
            if( !(k&1<<i) && !dfs(M, T-i-1, k|1<<i, m) ) return m[k]=true;
        }
        return m[k]=false;
    }
};
