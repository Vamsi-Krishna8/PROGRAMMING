class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        int n=arr.size();
        for(auto x:arr){
            if(x%2==1) count++;
            else count=0;
            if(count==3) return true;
        }
        return false;
    }
};