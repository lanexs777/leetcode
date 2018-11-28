# 636
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> st;
        int preTime=0;
        
        for(string log:logs) {
            int found1=log.find(":");
            int found2=log.find_last_of(":");
            int idx=stoi(log.substr(0,found1));
            string type=log.substr(found1+1, found2-found1-1);
            int time=stoi(log.substr(found2+1));
            // renew the last execute time
            if(!st.empty()) {
                res[st.top()] += time-preTime;
            }
            //get the preTime
            preTime =time;
            if(type=="start") st.push(idx);
            else {
                auto t=st.top(); st.pop();
                ++res[t];
                ++preTime; // 只是為了下一個人的值是正確的
            }
        }
        return res;
    }
};
