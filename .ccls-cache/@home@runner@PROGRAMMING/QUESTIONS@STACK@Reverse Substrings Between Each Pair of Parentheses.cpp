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

//WormHole Technique

class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<int> st;
        vector<int> vec(n);
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                int j=st.top();
                st.pop();
                vec[i]=j;
                vec[j]=i;
            }
        }
        int flag=1;
        for(int i=0;i<n;i+=flag){
            if(s[i]=='(' || s[i]==')'){
                i=vec[i];
                flag*=-1;
            }
            else{
                res.push_back(s[i]);
            }
        }
        return res;
    }
};

//WormHole Technique
class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<int> st;
        vector<int> vec(n);
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                int j=st.top();
                st.pop();
                vec[i]=j;
                vec[j]=i;
            }
        }
        int flag=1;
        for(int i=0;i<n;i+=flag){
            if(s[i]=='(' || s[i]==')'){
                i=vec[i];
                flag*=-1;
            }
            else{
                res.push_back(s[i]);
            }
        }
        return res;
    }
};