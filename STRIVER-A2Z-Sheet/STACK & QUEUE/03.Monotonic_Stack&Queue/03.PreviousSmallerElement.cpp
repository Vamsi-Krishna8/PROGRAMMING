vector<int> Solution::prevSmaller(vector<int> &A) {
    int n=A.size();
    vector<int> res(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=A[i]) st.pop();
        if(st.empty()) res[i]=-1;
        else res[i]=st.top();
        st.push(A[i]);
    }
    return res;
}
