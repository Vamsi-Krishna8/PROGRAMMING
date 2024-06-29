 #define ll long long
 class Solution {
 public:
     int check(ll mid,vector<int> &piles,int h){
         ll res=0;
         for(int i=0;i<piles.size();i++){
             res+=(piles[i]+mid-1)/mid;
         }
         return res<=h;
     }
     int minEatingSpeed(vector<int>& piles, int h) {
         ll low=1,high=1e9,ans=-1;
         while(low<=high){
             ll mid=low+(high-low)/2;
             if(check(mid,piles,h)){
                 ans=mid;
                 high=mid-1;
             }
             else low=mid+1;
         }
         return (int)ans;
     }
 };