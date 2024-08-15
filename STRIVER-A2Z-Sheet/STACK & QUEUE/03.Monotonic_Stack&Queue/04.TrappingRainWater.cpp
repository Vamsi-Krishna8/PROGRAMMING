//Approach 1 

//TC => O(n) SC => O(n);
class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        vector<int> pref(n);
        vector<int> suff(n);
        pref[0]=arr[0];
        suff[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            pref[i]=max(pref[i-1],arr[i]);
            suff[n-i-1]=max(suff[n-i],arr[n-i-1]);
        }
        int water_count=0;
        for(int i=0;i<n;i++){
            water_count+=min(pref[i],suff[i])-arr[i];
        }
        return water_count; 
    }
};

//Approach 2 

// TC => O(n) SC => O(1);
class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int l=0,r=n-1;
        int res=0;
        int lmax=0,rmax=0;
        while(l<=r){
            if(h[l]<=h[r]){
                if(lmax>h[l]) res+=lmax-h[l];
                else lmax=h[l];
                l++;
            }
            else{
                if(rmax>h[r]) res+=rmax-h[r];
                else rmax=h[r];
                r--;
            }
        }
        return res;
    }
};