#include <bits/stdc++.h>>
using namespace std;
class Edge {
public:
  int source;
  int destination;
  int weight;
};

int getTopMostParent(int *parent, int index) {
  while (parent[index] != index) {
    index = parent[index];
  }
  return index;
}

bool cmp_edge_by_weight(const Edge e1, const Edge e2) {
  return e1.weight < e2.weight;
}

void kruskal(Edge *edges, int n, int e) {
  // sort the edges in increasing order of weight.
  sort(edges, edges + e, cmp_edge_by_weight);
  // mst i.e. result vector of edges in mst.
  Edge *mst = new Edge[n - 1];
  // create parent array with value as index.
  int *parent = new int[n];
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }
  // create mst array and apply the logic i.e. check topmost parent and add to
  // mst.
  int count = 0;
  int i = 0;
  while (count < n - 1) {
    int p1 = getTopMostParent(parent, edges[i].source);
    int p2 = getTopMostParent(parent, edges[i].destination);
    if (p1 != p2) {
      mst[count] = edges[i];
      count++;
      parent[p1] = p2;
    }
    i++;
  }

  // print the mst array
  for (int i = 0; i < n - 1; i++) {
    Edge edge = mst[i];
    if (edge.source < edge.destination) {
      cout << edge.source << " " << edge.destination << " " << edge.weight
           << endl;
    } else {
      cout << edge.destination << " " << edge.source << " " << edge.weight
           << endl;
    }
  }
}

int main() {
  int v, e;
  cin >> v >> e;
  Edge *edges = new Edge[e];
  for (int i = 0; i < e; i++) {
    int source, destination, weight;
    cin >> source >> destination >> weight;
    edges[i].source = source;
    edges[i].destination = destination;
    edges[i].weight = weight;
  }
  kruskal(edges, v, e);

  return 0;
}