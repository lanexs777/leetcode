# 166
# 整數校數分開討論 / 利用餘數做hashtable
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";

        long long a = numerator, b = denominator;
        int signa = (a>0 ? 1 : -1), signb = (b>0 ? 1 : -1);
        unordered_map<int, int> h;
        a *= signa, b *= signb;
        string ret = (signa*signb<0?"-":"") + to_string(a/b);
        string remder;

        
        int counter = 0;
        for( a %= b ; a && !h.count(a); a %= b) {
            h[a%b] = counter++;
            a *= 10;
            remder += to_string(a/b);
        }

        if( a || !remder.empty() ) {
            ret += ".";
            if(!a) ret += remder;
            else {
                ret += remder.substr(0, h[a]) + "(" +  remder.substr(h[a]) + ")";
            }
        }
        return ret;
    }
};
