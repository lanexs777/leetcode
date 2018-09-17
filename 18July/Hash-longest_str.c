// hash
// 利用兩個指針去表示最長的字串


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        int i=-1;
        unordered_map<char,int> Mymap;
        unordered_map<char,int>::iterator it;
        
        for(int j=0;j<s.length();j++) {
            it=Mymap.find(s[j]);
            
            // if found the duplicate
            if(it!=Mymap.end()) {
                // refresh i, choose the 
                i=max(it->second,i);    
            }
            // add the new char
            Mymap[s[j]]=j;
            len=max(len,(j-i));
                       
        }
        return len;
        
    }
};
