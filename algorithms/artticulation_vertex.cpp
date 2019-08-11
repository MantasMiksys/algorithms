
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> low, tin;

int time = 0;

void dfs(int from) {
  visited[from] = true;
  low[from] = tin[from] = time++;

  for (int u : adj[from]) {
    if (u == from) continue;
    if (visited[u]) {
      low[from] = low[u]
    } else {

    }
  }
}

void findArticulationVertices(vector<vector<int>>& adj) {
  visited.assign(adj.size(), false);
  low.assign(adj.size(), -1);
  tin.assign(adj.size(), -1);

  for (int i = 0; i < adj.size(); ++i) {
    if (!visited[i]) {
      dfs(i);
    }
  }
}

int main() {}
