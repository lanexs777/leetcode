# 755
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        while(V>0) {
            // search left
            int flag=0;
            int min_left=K;
            for(int i=K-1;i>=0;i--) {
                if(heights[i]>heights[min_left]){
                    break;
                }
                if(heights[i]<heights[min_left]){
                    min_left=i;
                    flag=1; //find smaller one;
                }        
            }
            if(flag) {
                V--;
                heights[min_left]++;
            }            
            
            int min_right=K;
            if(flag==0) { //left no space
                //search right
                for(int i=K+1;i<heights.size();i++) {
                    if(heights[i]>heights[min_right]) {
                        break;
                    }
                    if(heights[i]<heights[min_right]) {
                        min_right=i;
                        flag=1;
                    }
                }
                if(flag) {
                    V--;
                    heights[min_right]++;
                }
            }
            if(flag==0) {
                heights[K]++;
                V--;
            }
            
        }
        
        return heights;
    }
};
