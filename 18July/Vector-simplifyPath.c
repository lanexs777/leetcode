#71
class Solution {
public:
    string simplifyPath(string path) {
        stringstream s(path);
        vector<string> v;
        string str,res;
        while(getline(s,str,'/')) {
            if(str=="" || str==".") continue;
            else if(str==".." && !v.empty()) v.pop_back();
            else if(str!="..")v.push_back(str);
        }
        
        for(int i=0;i<v.size();i++) {
            res=res+"/"+v[i];
        }
        
        return v.empty()?"/":res;
        
    }
};
