#include <bits/stdc++.h>
using namespace std;

int findMinDist(int *distance, bool *visited, int n) {
  int minDistVertex = -1;
  for (int i = 0; i < n; i++) {
    if (!visited[i] &&
        (minDistVertex == -1 || distance[i] < distance[minDistVertex])) {
      minDistVertex = i;
    }
  }
  return minDistVertex;
}

void dijkstra(int **edges, int n) {
  // create visited array
  bool *visited = new bool[n];
  int *distance = new int[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
    distance[i] = INT_MAX;
  }
  distance[0] = 0;
  // check for all the un-visited neighbours
  for (int i = 0; i < n; i++) {
    int m = findMinDist(distance, visited, n);
    visited[m] = true;
    for (int j = 0; j < n; j++) {
      if (!visited[j] && edges[m][j] > 0 &&
          (distance[m] + edges[m][j]) < distance[j]) {
        distance[j] = distance[m] + edges[m][j];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << i << " " << distance[i] << endl;
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
    int sv, lv, w;
    cin >> sv >> lv >> w;
    edges[sv][lv] = edges[lv][sv] = w;
  }
  dijkstra(edges, v);

  return 0;
}