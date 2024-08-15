class Solution {
public:

    vector<int> getNsl(vector<int> &v){
        int n=v.size();
        stack<int> st;
        vector<int> res(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && v[st.top()]>v[i]) st.pop();
            if(st.empty()) res[i]=-1;
            else res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> getNsr(vector<int> &v){
        int n=v.size();
        stack<int> st;
        vector<int> res(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && v[st.top()]>=v[i]) st.pop();
            if(st.empty()) res[i]=n;
            else res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> ls=getNsl(arr);
        vector<int> rs=getNsr(arr);
        long long sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            long long left=i-ls[i];
            long long right=rs[i]-i;
            sum=(sum+left*right*arr[i])%mod;
        }
        return sum;
    }
};