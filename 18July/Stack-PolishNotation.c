#150
class Solution {
public:
    stack<int> st;
    int evalRPN(vector<string>& tokens) {
        
        for(int i=0;i<tokens.size();i++) {
            if(tokens[i]=="+") {
                int tmp1=st.top();
                st.pop();
                int tmp2=st.top();
                st.pop();
                int result=tmp2+tmp1;
                st.push(result);
            }
            else if(tokens[i]=="-") {
                int tmp1=st.top();
                st.pop();
                int tmp2=st.top();
                st.pop();
                int result=tmp2-tmp1;
                st.push(result);
            }
            else if(tokens[i]=="*") {
                int tmp1=st.top();
                st.pop();
                int tmp2=st.top();
                st.pop();
                int result=tmp2*tmp1;
                st.push(result);
            }
            else if(tokens[i]=="/") {
                int tmp1=st.top();
                st.pop();
                int tmp2=st.top();
                st.pop();
                int result=tmp2/tmp1;
                st.push(result);
            }
            else {
                int result=stoi(tokens[i]);
                st.push(result);
            }
        }
        return st.top();
    }
};
