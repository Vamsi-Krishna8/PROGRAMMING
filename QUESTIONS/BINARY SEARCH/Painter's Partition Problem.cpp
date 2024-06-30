
int check(long long mid,vector<int> &boards){
    int count=1;
    long long sum=0;
    int n=boards.size();
    for(int i=0;i<n;i++){
        if(sum+boards[i]<=mid) sum+=boards[i];
        else{
            count++;
            sum=boards[i];
        }
    }
    return count;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int n=boards.size();
    long long lo=*max_element(boards.begin(),boards.end());
    long long hi=1e14;
    int ans=-1;
    while(lo<=hi){
        long long mid=lo+(hi-lo)/2;
        int res=check(mid,boards);
        if(res>k) lo=mid+1;
        else{
            ans=mid;
            hi=mid-1;
        }
    }
    return ans;
}