# 13
class Solution {
public:
    int romanToInt(string s) {
        map<char, int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        stack<int> st;
        for(int i=0;i<s.size();i++) {
            if(st.empty()) st.push(mp[s[i]]);
            else {
                if(mp[s[i]]>st.top()) {
                    
                    int sum=0;
                    
                    while(!st.empty() && st.top()<mp[s[i]]) {
                        
                        int tmp=st.top();
                        
                        sum += tmp;
                        
                        st.pop();
                        
                    }
                    
                    st.push(mp[s[i]]-sum);
                }
                else {
                    st.push(mp[s[i]]);
                }
            }
        }
        int res=0;
        while(!st.empty()) {
            
            int tmp=st.top();
            res+=tmp;
            st.pop();
        }
        return res;
    }
};
