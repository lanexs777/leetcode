# 187 
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> Set;
        vector<string> res;
        if(s.length()<10) return res;
        int start=0;
        while(start+10<=s.length()) {
            string tmp=s.substr(start, 10);
            if(Set.count(tmp)==0) {
                Set.insert(tmp);
            }
            else{
                auto it = find(res.begin(), res.end(), tmp);
                if(it == res.end()) {
                    res.push_back(tmp);
                }
                
            }
            start++;
        }
        return res;
    }
};
