# 20
class Solution {
public:
    bool isValid(string s) {
        stack<char> ST;
        for(char c:s) {
            switch(c) {
                case '(':
                case '{':
                case '[': ST.push(c); break;
                case ')': if(ST.empty() || ST.top()!='(') return false; else ST.pop(); break;
                case '}': if(ST.empty() || ST.top()!='{') return false; else ST.pop(); break;
                case ']': if(ST.empty() || ST.top()!='[') return false; else ST.pop(); break;
                default: ;
            }
        }
        return ST.empty();
    }
    
};
