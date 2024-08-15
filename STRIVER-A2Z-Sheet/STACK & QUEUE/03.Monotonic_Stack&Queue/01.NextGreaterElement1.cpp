class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[nums2[i]]=i;
        vector<int> nge(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]) st.pop();
            if(st.empty()) nge[i]=-1;
            else nge[i]=st.top();
            st.push(nums2[i]);
        }
        vector<int> res;
        for(auto x:nums1){
            int idx=mp[x];
            res.push_back(nge[idx]);
        }
        return res;
    }
};