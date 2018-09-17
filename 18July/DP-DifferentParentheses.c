#241

// the recursive way.
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int size=input.size();
        vector<int> result;
        for(int i=0;i<size;i++) {
            char curr=input[i];
            if(curr=='+' || curr=='-' || curr=='*') {
                vector<int> result1=diffWaysToCompute(input.substr(0,i));
                vector<int> result2=diffWaysToCompute(input.substr(i+1));
                
                for(int n1:result1) {
                    for(int n2:result2) {
                        if(curr=='+')
                            result.push_back(n1+n2);
                        else if(curr=='-')
                            result.push_back(n1-n2);
                        else
                            result.push_back(n1*n2);
                    }
                }
            }            
        }
        if(result.empty()){
            result.push_back(stoi(input));
        }
        return result;
    }
};
// 上面這個recursive的寫法 會有蠻多重複的運算，可以改成下面的DP解法

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> dpMap;
        return compute(input, dpMap);
    }
    
    vector<int> compute(string input, unordered_map<string, vector<int>> &dpMap) {
        int size=input.size();
        vector<int> result;
        for(int i=0;i<size;i++) {
            char curr=input[i];
            if(curr=='+' || curr=='-' || curr=='*') {
                vector<int> result1,result2;               
                
                if(dpMap.find(input.substr(0,i)) != dpMap.end())               
                    result1=dpMap[input.substr(0,i)];               
                else 
                    result1=compute(input.substr(0,i), dpMap);
                                
                if(dpMap.find(input.substr(i+1)) != dpMap.end()) 
                    result2=dpMap[input.substr(i+1)];
                else
                    result2=compute(input.substr(i+1), dpMap);
                   
                for(int n1:result1) {
                    for(int n2:result2) {
                        if(curr=='+')
                            result.push_back(n1+n2);
                        else if(curr=='-')
                            result.push_back(n1-n2);
                        else
                            result.push_back(n1*n2);
                    }
                }
            }            
        }
        if(result.empty()){
            result.push_back(stoi(input));
        }
        dpMap[input]=result;
        return result;
    }    
    
};
