class Solution {
public:
    // brute force --> fail.
    /*bool check(int i) {
        while(i%2==0) {
            i=i/2;
            if(i==1) return true;
        }
        while(i%3==0) {
            i=i/3;
            if(i==1) return true;
        }
        while(i%5==0) {
            i=i/5;
            if(i==1) return true;
        }
        return false;
    }
    int nthUglyNumber(int n) {
        int count = 1;
        if(count==n) return 1;
        int i=2;
        while(1) {
            if(check(i)) {
                count++;
                if(count==n) return i; 
                i++;
            }
            else i++;
        }
        
    }*/
    
    // 因為只有2,3,5可能的因素 所以就用2,3,5下去乘 在push_back 最小的值
    int nthUglyNumber(int n) {
        vector<int> result (1,1);
        int i=0;
        int j=0;
        int k=0;
        while(result.size()<n) {
            result.push_back( min(result[i]*2, min(result[j]*3, result[k]*5)));
            if(result.back()==result[i]*2) i++;
            if(result.back()==result[j]*3) j++;
            if(result.back()==result[k]*5) k++;
        }
        return result.back();
    } 
};
