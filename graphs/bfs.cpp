#include<bits/stdc++.h>
using namespace std;

void printGraphBFS(int **edges, int n, int start, bool *visited) {
  queue<int> q;
  q.push(start);
  visited[start] = true;
  while (!q.empty()) {
    int f = q.front();
    cout << f << " ";
    q.pop();
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
}
void printGraphBFS(int **edges, int n, bool *visited) {
  for (int k = 0; k < n; k++) {
    if (!visited[k]) {
      printGraphBFS(edges, n, k, visited);
    }
  }
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
  bool *visited = new bool[v];
  for (int i = 0; i < v; i++) {
    visited[i] = false;
  }
  // print connected graph
  printGraphBFS(edges, v, 0, visited);
  // print disconnected graph
  printGraphBFS(edges, v, visited);
  for (int i = 0; i < v; i++) {
    delete[] edges[i];
  }
  delete[] edges;
  delete[] visited;

  return 0;
}