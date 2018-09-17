#6
// 將結果一列一列存起來，再把存起來的結果印出來
//A   G   M  --> a[0]
//B  FH  LN  --> a[1]
//C E I K O  --> a[2] 
//D   J   P  --> a[3]
//
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int n=2*numRows-2;
        string a[n];
        string ans;
                
        for(int i=0;i<s.length();i++) {
            int idx=i%n;
            if(idx<numRows) {
                a[idx].push_back(s[i]);
            }
            else{
                a[n-idx].push_back(s[i]);
            }
        }
        
        for(int i=0;i<n;i++) {
            ans=ans+a[i];
        }
    
        return ans;
    }        
};
