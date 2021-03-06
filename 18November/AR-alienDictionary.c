# 269
class Solution {
public:
    string alienOrder(vector<string>& words) {
        set<pair<char, char>> pair;
        unordered_set<char> ch;
        vector<int> in(256,0);
        queue<char> q;
        string res="";
        
        // store every appeare char
        for(auto a:words) ch.insert(a.begin(), a.end());
        
        for(int i=0;i<words.size()-1;i++) {
            int mn=min(words[i].size(), words[i+1].size()), j=0;
            
            for(;j<min(words[i].size(), words[i+1].size());j++) {
                if(words[i][j] != words[i+1][j]) {
                    pair.insert(make_pair(words[i][j], words[i+1][j]));
                    break;
                }    
            }
            if(j==mn && words[i].size()>words[i+1].size()) return ""; // when "wten", "wtenr" happened.
        }
        for(auto a:pair) ++in[a.second];
        for(auto a:ch) {
            if(in[a]==0) {
                q.push(a);
                res+=a;
            }
        }
        
        while(!q.empty()) {
            char c=q.front(); q.pop();
            for(auto a:pair) {
                if(a.first==c) {
                    --in[a.second];
                    if(in[a.second]==0) {
                        q.push(a.second);
                        res += a.second;
                    }
                }
            }
        }
        return res.size()==ch.size()? res:"";
    }
};
