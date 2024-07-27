class Solution {
public:
  double averageWaitingTime(vector<vector<int>> &customers) {
    double currTime = 0;
    double wait = 0;
    int n = customers.size();
    for (auto x : customers) {
      int arrivalTime = x[0];
      int orderTime = x[1];

      if (currTime < arrivalTime)
        currTime = arrivalTime + orderTime;

      else
        currTime += orderTime;
      wait += (currTime - arrivalTime);
    }
    return wait / n;
  }
};

