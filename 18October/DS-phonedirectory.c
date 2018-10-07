# 379
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    unordered_map<string, int> dir;
    PhoneDirectory(int maxNumbers) {
        for(int i=0;i<maxNumbers;i++) {
            dir[to_string(i)]=0;
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        for(auto it=dir.begin();it!=dir.end();it++) {
            if(it->second==0) {
                it->second=1;
                return stoi(it->first);                    
            }
        }
        return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if(dir[to_string(number)]==0) return true;
        else return false;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        dir[to_string(number)]=0;
        return;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
