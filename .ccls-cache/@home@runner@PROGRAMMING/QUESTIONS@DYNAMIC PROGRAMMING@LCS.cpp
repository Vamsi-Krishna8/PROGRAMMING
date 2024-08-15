//MEMO

class Solution {
public:
    int n,m;
    int dp[1001][1001];

    int solve(string s1,string s2,int i,int j){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]=1+solve(s1,s2,i+1,j+1);
        int s1_skip=solve(s1,s2,i,j+1);
        int s2_skip=solve(s1,s2,i+1,j);
        return dp[i][j]=max(s1_skip,s2_skip);
    }
    int longestCommonSubsequence(string s1, string s2) {
        n=s1.size();
        m=s2.size();
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,0,0);
    }
};


//TABULAION

//dp[i][j] => lcs between s1 of length i and s2 of length j
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();

        vector<vector<int> > dp(n+1,vector<int> (m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];

    }
};