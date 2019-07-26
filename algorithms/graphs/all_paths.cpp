#include <iostream>
#include <vector>

using namespace std;

void allPathsUtil(const vector<vector<int>>& adj, vector<bool> visited, int s,
                  int t, vector<vector<int>>& allPaths, vector<int> path) {
  path.push_back(s);
  visited[s] = true;
  if (s == t) {
    allPaths.push_back(path);
    return;
  }

  for (int v : adj[s]) {
    if (!visited[v]) {
      allPathsUtil(adj, visited, v, t, allPaths, path);
    }
  }
}

vector<vector<int>> allPaths(const vector<vector<int>>& adj, int s, int t) {
  vector<bool> visited(adj.size(), false);
  vector<vector<int>> paths;
  vector<int> path;
  allPathsUtil(adj, visited, s, t, paths, path);

  return paths;
}

int main() {
  vector<vector<int>> adj{{1, 2, 3}, {3}, {0, 1}, {}};
  auto paths = allPaths(adj, 2, 3);
  for (auto path : paths) {
    for (int stop : path) {
      cout << stop << " ";
    }
    cout << endl;
  }
}
