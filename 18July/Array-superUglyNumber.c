#313
// 本題 跟#264 是一樣的想法，只是將264的2,3,5 改乘用一個vector去存取。
class Solution {
public:
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> result (1,1);
        vector<int> point (primes.size(),0); // substitute for i,j,k
        while(result.size()<n) {
            int Min=result[point[0]]*primes[0];
            for(int i=0;i<primes.size();i++) {
                Min=min(Min, result[point[i]]*primes[i]);
            }
            
            result.push_back(Min);
            
            for(int i=0;i<primes.size();i++) {
                if(Min == result[point[i]]*primes[i]) {
                    point[i]++;
                    //break;  注意，不可以break在這裡 因為只要是可以透過那個方式前進的都要算。
                }
                    
            }                       
        }
        return result.back();
        
        
    }
};
