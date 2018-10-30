# 122
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int i=0;
        int valley=prices[i];
        int peak=prices[i];
        int max_profit=0;
        while(i< prices.size()-1) {
            while(i<prices.size()-1 && prices[i]>=prices[i+1])
                i++;
            valley=prices[i];
            while(i<prices.size()-1 && prices[i]<=prices[i+1])
                i++;
            peak=prices[i];
            max_profit += peak-valley;
        }
        return max_profit;
    }
};
