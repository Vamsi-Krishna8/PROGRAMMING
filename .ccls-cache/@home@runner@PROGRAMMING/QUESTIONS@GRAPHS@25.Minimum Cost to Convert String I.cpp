//FLOYD WARSHALL

class Solution {
public:
  long long minimumCost(string source, string target, vector<char> &original,
                        vector<char> &changed, vector<int> &cost) {
    vector<vector<long long>> adjMatrix(26, vector<long long>(26, INT_MAX));
    for (int i = 0; i < 25; i++) {
      for (int j = 0; j < 25; j++) {
        if (i == j)
          adjMatrix[i][j] = 0;
      }
    }
    for (int i = 0; i < original.size(); i++) {
      long long val = adjMatrix[original[i] - 'a'][changed[i] - 'a'];
      adjMatrix[original[i] - 'a'][changed[i] - 'a'] =
          min(val, (long long)cost[i]);
    }

    for (int via = 0; via < 26; via++) {
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
          adjMatrix[i][j] =
              min(adjMatrix[i][j], adjMatrix[i][via] + adjMatrix[via][j]);
        }
      }
    }

    long long ans = 0;
    for (int i = 0; i < source.length(); i++) {
      if (source[i] == target[i])
        continue;
      else if (adjMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX)
        return -1;
      else
        ans += adjMatrix[source[i] - 'a'][target[i] - 'a'];
    }
    return ans;
  }
};

//DIJKSTRAS

class Solution {
public:
    void dijkstras(char &src,unordered_map<char,vector<pair<char,int> > > &adj,vector<vector<long long> > &costMatrix){
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>> > pq;
        pq.push({0,src});

        while(!pq.empty()) {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto &it:adj[node]) {
                char adjNode=it.first;
                int cost=it.second;
                if(costMatrix[src - 'a'][adjNode - 'a'] > d + cost) {
                    costMatrix[src - 'a'][adjNode - 'a'] = d + cost;
                    pq.push({d + cost, adjNode});
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char,vector<pair<char,int> > > adj;
        for(int i=0;i<original.size();i++){
            adj[original[i]].push_back({changed[i],cost[i]});
        }
        vector<vector<long long> > costMatrix(26,vector<long long> (26,INT_MAX));

        //dijkstras
        for(int i=0;i<source.length();i++){
            char src=source[i];
            dijkstras(src,adj,costMatrix);
        }

        long long ans=0;
        for(int i=0;i<source.length();i++){
            if(source[i]==target[i]) continue;
            if(costMatrix[source[i]-'a'][target[i]-'a']==INT_MAX) return -1;
            ans+=costMatrix[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};

