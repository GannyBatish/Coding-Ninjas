#include <bits/stdc++.h>
using namespace std;

bool hasPath(int **edges, int n, int v1, int v2, bool *visited) {
  queue<int> q;
  q.push(v1);
  visited[v1] = true;
  while (!q.empty()) {
    int f = q.front();
    q.pop();
    if (f == v2) {
      return true;
    }
    for (int i = 0; i < n; i++) {
      if (i == f) {
        continue;
      }
      if (edges[f][i] == 1 && !visited[i]) {
        visited[i] = true;
        q.push(i);
      }
    }
  }
  return false;
}

int main() {
  int v, e;
  cin >> v >> e;
  int **edges = new int *[v];
  for (int i = 0; i < v; i++) {
    edges[i] = new int[v];
    for (int j = 0; j < v; j++) {
      edges[i][j] = 0;
    }
  }
  for (int i = 0; i < e; i++) {
    int fv, sv;
    cin >> fv >> sv;
    edges[fv][sv] = 1;
    edges[sv][fv] = 1;
  }
  int v1, v2;
  cin >> v1 >> v2;
  bool *visited = new bool[v];
  for (int i = 0; i < v; i++) {
    visited[i] = false;
  }
  hasPath(edges, v, v1, v2, visited) ? cout << "true" : cout << "false";
  for (int i = 0; i < v; i++) {
    visited[i] = false;
  }
  for (int i = 0; i < v; i++) {
    delete[] edges[i];
  }
  delete[] edges;
  delete[] visited;

  return 0;
}