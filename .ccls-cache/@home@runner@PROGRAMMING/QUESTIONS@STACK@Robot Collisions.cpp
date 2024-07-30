class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& hp, string dir) {
        int n=pos.size();
        vector<pair<int,int> > vec;
        for(int i=0;i<n;i++){
            vec.push_back({pos[i],i});
        }
        sort(vec.begin(),vec.end());
        stack<int> st;

        for(auto x:vec){
            int line_pos=x.first;
            int curr_pos=x.second;

            if(dir[curr_pos]=='R'){
                st.push(curr_pos);
            }
            else{ //towards left
                while(!st.empty() && hp[curr_pos]>0){
                    int prev_pos=st.top();
                    if(hp[prev_pos]>hp[curr_pos]){
                        hp[curr_pos]=0;
                        hp[prev_pos]-=1;
                    }
                    else if(hp[prev_pos]<hp[curr_pos]){
                        hp[prev_pos]=0;
                        hp[curr_pos]-=1;
                        st.pop();
                    }
                    else{
                        hp[prev_pos]=0;
                        hp[curr_pos]=0;
                        st.pop();
                    }
                }
            }
        }
        vector<int> res;
        for(auto x:hp){
            if(x)
                res.push_back(x);
        }
        return res;
    }
};