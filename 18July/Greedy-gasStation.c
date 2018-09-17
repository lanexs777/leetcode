#134
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        for(int i=0;i<gas.size();i++) {
            if(gas[i]<cost[i]) {
                continue;
            }
            else {
                int count=0;
                int current_gas=gas[i];
                int current_cost=cost[i];
                for( int j=(i+1)%gas.size();count!=gas.size()-1;j=(j+1)%gas.size() ) {
                    current_gas=current_gas+gas[j];
                    current_cost=current_cost+cost[j];
                    if(current_gas >= current_cost) {
                        count++;
                        if(count == (gas.size()-1) ) return i;
                        continue;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        if(gas.size()==1 && gas[0]>=cost[0]) return 0;
        return -1;
    }
    // 另一個超神解法
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=gas.size()-1;
        int end=0;
        int sum=gas[start]-cost[start];
        while(start>end) {
            if(sum>=0) {                
                sum = sum + gas[end] - cost[end];
                end++;
            }
            else {
                start--;
                sum = sum + gas[start] - cost[start];
            }
        }
        return (sum>=0)? start:-1;
    }    
};
