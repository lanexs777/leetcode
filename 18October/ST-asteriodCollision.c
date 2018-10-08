# 735
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ST;
        
        for(int i=0;i<asteroids.size();i++) {
            if(asteroids[i]>0 || ST.empty() || ST.back() <0 ){
                ST.push_back(asteroids[i]);
            }
            else if(ST.back()<= -asteroids[i]) {
                if(ST.back() < -asteroids[i]) i--;
                ST.pop_back();
            }
        }
        return ST;
    }
};
