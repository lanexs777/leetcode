# 299
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> hash(10,0);
        int A=0;
        int B=0;
        
        for(int i=0;i<secret.length();i++) {
            int k=secret[i]-48;
            hash[k]++;
        }
        
        for(int i=0;i<secret.length();i++) {
            if(secret[i]==guess[i]) {
                A++;
                int b=secret[i]-48;
                hash[b]--;
                if(hash[b]<0) B--;
            }
            else{
                int b=guess[i]-48;
                if(hash[b]>=1) {
                    B++;
                    hash[b]--;
                }
                
            }
        }
        string strA=to_string(A);
        string strB=to_string(B);
        string res=strA+"A"+strB+"B";
        return res;
        
    }
};
