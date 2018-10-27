# 165
class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream is1(version1+"."), is2(version2+".");
        int d1,d2;
        char dot='.';
        while(is1.good() || is2.good()) {
            is1 >> d1 >> dot;
            is2 >> d2 >> dot;
            if(d1>d2) return 1;
            else if(d1<d2) return -1;
            d1=d2=0;
        }
        
        return 0;
        
    }
};
