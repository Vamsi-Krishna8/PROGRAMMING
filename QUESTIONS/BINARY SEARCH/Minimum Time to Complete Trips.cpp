class Solution {
public:
    bool check(long long mid,vector<int> &time,int trips){
        long long count=0;
        int n=time.size();
        for(int i=0;i<n;i++){
            count+=mid/time[i];
        }
        return count>=trips;
    }
    long long minimumTime(vector<int>& time, int trips) {
        long long lo=1,hi=1e14;
        long long ans=1e14;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if(check(mid,time,trips)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};