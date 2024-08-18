//TOPOLOGICAL SORT

class Solution
{
  public:
  //Function to return list containing vertices in Topological order.
  stack<int> st;
  void dfs(int curr,vector<int> adj[],vector<int> &vis){
      vis[curr]=1;
      for(auto it:adj[curr]){
          if(!vis[it]){
              dfs(it,adj,vis);
          }
      }
      st.push(curr);
  }
  vector<int> topoSort(int V, vector<int> adj[]) 
  {
      // code here
      vector<int> vis(V,0);
      for(int i=0;i<V;i++){
          if(!vis[i]) dfs(i,adj,vis);
      }
      vector<int> topo;
      while(!st.empty()){
          topo.push_back(st.top());
          st.pop();
      }
      return topo;
  }
};