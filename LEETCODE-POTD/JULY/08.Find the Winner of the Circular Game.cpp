//Approach 1(array)

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=n;i++) ans.push_back(i);
        int i=0;
        while(ans.size()>1){
            int idx=(i+k-1)%ans.size();
            ans.erase(ans.begin()+idx);
            i=idx;
        }
        return ans[0];
    }
};

//Approach 2(queue)

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++) q.push(i);
        while(q.size()>1){
            for(int i=1;i<=k-1;i++){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};

//Approach 3 (recursion)

class Solution {
public:

    int findWinnerIdx(int n, int k) {
        if(n==1) return 0; 
        int idx=(findWinnerIdx(n-1,k)+k)%n;
        return idx;
    }

    int findTheWinner(int n, int k) {   
        int res=findWinnerIdx(n, k);
        return res+1;
    }
};