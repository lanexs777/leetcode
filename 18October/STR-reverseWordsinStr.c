# 151
class Solution {
public:
    void reverseWords(string &s) {
        istringstream ss(s);
        string tmp;
        ss>>tmp;
        s=tmp;
        while(ss>>tmp) s = tmp+" "+s;
        
    }
};
