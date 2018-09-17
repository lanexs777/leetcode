#392
//my first solution
class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t found=-1;
        
        for(int i=0;i<s.size();i++) {
            found=t.find(s[i],found+1);
            if(found!=string::npos) continue;
            else return false;
        }
        return true;
    }
};

//other solution
bool isSubsequence(string s, string t) {
        int si= 0;
        for(int ti = 0; ti < t.size() && si < s.size(); ti++) {
            if(t[ti] == s[si]) si++;
        }
        return si == s.size();
    }
