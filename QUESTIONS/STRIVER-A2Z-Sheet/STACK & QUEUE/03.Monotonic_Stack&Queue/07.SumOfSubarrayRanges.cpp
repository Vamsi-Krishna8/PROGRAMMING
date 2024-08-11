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

    vector<int> getNgL(vector<int>& v) {
        int n = v.size();
        stack<int> st;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && v[st.top()] < v[i]) st.pop();
            if (st.empty()) res[i] = -1;
            else res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> getNgR(vector<int>& v) {
        int n = v.size();
        stack<int> st;
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && v[st.top()] <= v[i]) st.pop();
            if (st.empty()) res[i] = n;
            else res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ls = getNsl(arr);
        vector<int> rs = getNsr(arr);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - ls[i];
            long long right = rs[i] - i;
            sum += left * right * arr[i];
        }
        return sum;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> lg = getNgL(arr);
        vector<int> rg = getNgR(arr);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - lg[i];
            long long right = rg[i] - i;
            sum += left * right * arr[i];
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long minSum = sumSubarrayMins(nums);
        long long maxSum = sumSubarrayMaxs(nums);
        return maxSum - minSum;
    }
};  