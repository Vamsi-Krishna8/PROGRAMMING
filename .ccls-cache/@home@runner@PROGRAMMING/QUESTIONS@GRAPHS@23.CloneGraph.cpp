// DFS

class Solution {
public:
  unordered_map<Node *, Node *> mp;

  void dfs(Node *node, Node *clone_node) {
    for (Node *n : node->neighbors) {
      // The neighbour node has not yet been created
      if (mp.find(n) == mp.end()) {
        // simply create it
        Node *clone =
            new Node(n->val); // created new clone node for the neighbour
        mp[n] = clone;
        clone_node->neighbors.push_back(clone);
        dfs(n, clone);
      } else { // if the neigbour clone node has already been created
        // simply bring that clone node address from the map and add it
        Node *clone = mp[n];
        clone_node->neighbors.push_back(clone);
      }
    }
  }
  Node *cloneGraph(Node *node) {
    if (node == NULL)
      return NULL;

    // create new clone node for the given node
    Node *clone_node = new Node(node->val);
    mp[node] = clone_node;
    dfs(node, clone_node);
    return clone_node;
  }
};

// BFS

class Solution {
public:
  unordered_map<Node *, Node *> mp;

  void bfs(queue<Node *> q) {
    while (!q.empty()) {
      Node *curr = q.front();
      q.pop();
      for (Node *n : curr->neighbors) {
        if (mp.find(n) == mp.end()) {
          Node *clone = new Node(n->val);
          mp[n] = clone;
          mp[curr]->neighbors.push_back(clone);
          q.push(n);
        } else {
          mp[curr]->neighbors.push_back(mp[n]);
        }
      }
    }
  }
  Node *cloneGraph(Node *node) {
    if (node == NULL)
      return NULL;

    // create new clone node for the given node
    Node *clone_node = new Node(node->val);
    mp[node] = clone_node;
    queue<Node *> q;
    q.push(node);
    bfs(q);
    return clone_node;
  }
};