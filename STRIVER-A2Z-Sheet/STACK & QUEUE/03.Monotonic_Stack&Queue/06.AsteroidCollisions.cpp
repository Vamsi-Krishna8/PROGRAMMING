class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto x:asteroids){
            while(!st.empty() && st.top()>0 && x<0){
                if(abs(x)>st.top()) st.pop();
                else if(abs(x)==st.top()){
                    st.pop();
                    x=0;
                    break;
                }
                else{
                    x=0;
                    break;
                }
            }
            if(x!=0) st.push(x);
        }
        vector<int> res(st.size());
        int m=res.size()-1;
        while(!st.empty()){
            res[m]=st.top();
            st.pop();
            m--;
        }
        return res;
    }
};