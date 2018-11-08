# 658
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index=0;
        vector<int> tmp;
        
        if(x<=arr[0]) return vector<int>(arr.begin(), arr.begin()+k);
        else if(x>=arr[arr.size()-1]) return vector<int>(arr.end()-k, arr.end());
        else {
            while(arr[index]<x) index++;
            
            int i=index-1;
            int j=index;
            while(k--) {
                (i<0 || (j<arr.size() && abs(arr[i]-x) > abs(arr[j]-x) ))? j++:i--;
            }
            return vector<int>(arr.begin()+i+1, arr.begin()+j);
        }
    }
};
