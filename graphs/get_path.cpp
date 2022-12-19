#include <bits/stdc++.h>
using namespace std;

vector<int> getPathDFS(vector<vector<int>> &edges, int v, int v1, int v2,
                       vector<bool> visited) {
  vector<int> path;
  if (v1 == v2) {
    path.push_back(v1);
    return path;
  }
  visited[v1] = true;
  for (int i = 0; i < v; i++) {
    if (i == v1) {
      continue;
    }
    if (edges[v1][i] == 1 && !visited[i]) {
      visited[i] = true;
      vector<int> ans = getPathDFS(edges, v, i, v2, visited);
      if (ans.size() > 0) {
        ans.push_back(v1);
        return ans;
      }
    }
  }
  return path;
}
int main() {
  int v, e;
  cin >> v >> e;
  vector<vector<int>> edges(v, vector<int>(v));
  for (int i = 0; i < e; i++) {
    int sv, lv;
    cin >> sv >> lv;
    edges[sv][lv] = 1;
    edges[lv][sv] = 1;
  }
  int v1, v2;
  cin >> v1 >> v2;
  vector<bool> visited(v, false);
  vector<int> path = getPathDFS(edges, v, v1, v2, visited);
  for (int i = 0; i < path.size(); i++) {
    cout << path[i] << " ";
  }

  return 0;
}