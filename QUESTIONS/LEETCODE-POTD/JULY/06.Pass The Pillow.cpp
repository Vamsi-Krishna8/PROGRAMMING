//Approach 1

class Solution {
public:
    int passThePillow(int n, int time) {
        int i=1;
        int dir=1;
        while(time>0){
            if(i+dir>=1 && i+dir<=n){
                time--;
                i+=dir;
            }
            else dir*=-1;
        }
        return i;
    }
};


//Approach 2

class Solution {
public:
    int passThePillow(int n, int time) {
        int turns=time/(n-1);
        int left=time%(n-1);
        if(turns%2==0) return left+1;
        else return n-left;
    }
};
