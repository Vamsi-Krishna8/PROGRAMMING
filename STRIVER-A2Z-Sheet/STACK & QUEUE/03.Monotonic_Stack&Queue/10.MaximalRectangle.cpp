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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> heights(m);
        for(int i=0;i<m;i++){
            heights[i]=(matrix[0][i]=='1') ? 1 : 0;
        }
        int maxArea=help(heights);
        for(int row=1;row<n;row++){
            for(int col=0;col<m;col++){
                if(matrix[row][col]=='0') heights[col]=0;
                else heights[col]+=1;
            }
            maxArea=max(maxArea,help(heights));
        }
        return maxArea;
    }
};