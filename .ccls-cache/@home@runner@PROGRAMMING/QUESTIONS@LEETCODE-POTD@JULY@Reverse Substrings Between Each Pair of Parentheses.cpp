//Brute Force

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res="";
        for(auto x:s){
            if(x=='(') st.push(res.size());
            else if(x!=')') res+=x;
            else{
                int len=st.top();
                st.pop();
                reverse(res.begin()+len,res.end());
            }
        }
        return res;
    }
};

