#467
// 已知 當有一個連續字元時的變化為1 有兩個連續字元的變化為3(1+2) 有三個連續字元的變化為6(1+2+3)
// 我們用一個cnt array去記錄數值
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int len=1;
        vector<int> cnt(26,0);
                
        for(int i=0;i<p.length();i++) {
            
            if( i>0 && (p[i]-p[i-1]==1 || p[i-1]-p[i]==25) ) {
                len++;                
            }
            else{
                len=1;
            }
            cnt[p[i]-'a']=max(cnt[p[i]-'a'], len);
        }
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};
