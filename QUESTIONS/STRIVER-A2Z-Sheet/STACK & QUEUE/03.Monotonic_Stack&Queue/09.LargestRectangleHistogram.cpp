class Solution {
public:
    vector<int> getNsl(vector<int>& v) {
        int n = v.size();
        stack<int> st;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && v[st.top()] > v[i]) st.pop();
            if (st.empty()) res[i] = -1;
            else res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> getNsr(vector<int>& v) {
        int n = v.size();
        stack<int> st;
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && v[st.top()] >= v[i]) st.pop();
            if (st.empty()) res[i] = n;
            else res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    int help(vector<int> &heights){
        vector<int> ls = getNsl(heights);
        vector<int> rs = getNsr(heights);
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            maxi=max((rs[i]-ls[i]-1)*heights[i],maxi);
        }
        return maxi;
    }
    int largestRectangleArea(vector<int>& heights) {
        return help(heights);
    }
};