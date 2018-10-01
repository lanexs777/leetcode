# 10
class Solution {
public:
    bool isMatch(string s, string p) {
        // case 1 empty        
        if(p.empty()) return s.empty();
        //case 2 :only have one char
        if(p.size()==1) return (s.size()==1 && (s[0]==p[0] || p[0]=='.'));
        //case 3: have multi char but second != '!'
        if(p[1]!='*') {
            if(s.empty()) return false;
            return (s[0]==p[0] || p[0]=='.') && isMatch(s.substr(1), p.substr(1));
        }
        //case 4 : have multi char and second = '!'
        while(!s.empty() && (s[0]==p[0] || p[0]=='.') ) {
            if(isMatch(s,p.substr(2))) return true;
            s=s.substr(1);
        }
        return isMatch(s, p.substr(2));
        
    }
};
