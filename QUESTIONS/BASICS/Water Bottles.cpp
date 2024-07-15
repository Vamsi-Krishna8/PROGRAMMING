//approach 1 
//TC==> O(n)

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank=0;
        while(numBottles>=numExchange){
            drank+=numExchange;
            numBottles-=(numExchange-1);
        }
        return drank+numBottles;
    }
};

//Approach 2
//TC==> O(logn)

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank=numBottles;
        int empty=numBottles;
        while(empty>=numExchange){
            int extra=empty/numExchange;
            drank+=extra;
            int remain=empty%numExchange;
            empty=remain+extra;
        }
        return drank;
    }
};

//Approach 3

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles+((numBottles-1)/(numExchange-1));
    }
};