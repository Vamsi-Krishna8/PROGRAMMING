//Memo

class Solution {
public:
    int n;
    int dp[101][101];
    int solve(int row,int col,vector<vector<int> > &matrix){
        if(row==n-1) return matrix[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int sum=matrix[row][col];
        int minSum=INT_MAX;
        if(row+1<n && col-1>=0) minSum=min(minSum,sum+solve(row+1,col-1,matrix));
        if(row+1<n) minSum=min(minSum,sum+solve(row+1,col,matrix));
        if(row+1<n && col+1<n) minSum=min(minSum,sum+solve(row+1,col+1,matrix));
        return dp[row][col]=minSum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row=0;
        n=matrix.size();
        memset(dp,-1,sizeof(dp));
        int res=INT_MAX;
        for(int col=0;col<n;col++){
            res=min(res,solve(row,col,matrix));
        }
        return res;
    }
};

//TABULATION

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int dp[n][n];
        for(int col=0;col<n;col++){
            dp[0][col]=matrix[0][col];
        }

        for(int row=1;row<n;row++){
            for(int col=0;col<n;col++){
                int left=INT_MAX,top=INT_MAX,right=INT_MAX;
                if(col-1>=0) left=dp[row-1][col-1];
                if(col+1<n) right=dp[row-1][col+1];
                top=dp[row-1][col];
                dp[row][col]=matrix[row][col]+min(top,min(left,right));
            }
        }
        int mini=INT_MAX;
        for(int col=0;col<n;col++){
            mini=min(mini,dp[n-1][col]);
        }
        return mini;
    }
};