# 557
class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string res;
        string tmp;
        while(is>>tmp) {
            reverse(tmp.begin(), tmp.end());
            res=res+tmp+" ";
        }
        res=res.substr(0, res.size()-1);
        return res;
    }
};
