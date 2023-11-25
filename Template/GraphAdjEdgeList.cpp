// ref: https://codeforces.com/blog/entry/67883
#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1e5;
const int MAX_EDGES = 2e5;

/* the head points to the index of last added edge, if no connected edges then it will be -1 */
int head[MAX_NODES];

struct edgeData {
  int to, cost, flow;
  int nxt; /* nxt: is the index of the next edge */
} edges[MAX_EDGES];

int edge_count;

void init() {
  memset(head, -1, sizeof head);
  edge_count = 0;
}

/* the index of the new added edge will be "edge_count" 0-based
 * we update the edge data (to, cost, nxt, ...)
 * then we update the head of the "from node" to the index of this edge
 * after that "edge_count" should be incremented  */
void addEdge(int from, int to, int cost) {
  edges[edge_count].to = to;
  edges[edge_count].cost = cost;
  edges[edge_count].nxt = head[from];
  head[from] = edge_count;
  edge_count++;
}

int main() {
  int n, m;
  cin >> n >> m;
  init(); // don't forget to call this before adding any edges
  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    addEdge(from, to, cost);
  }
  for (int i = 0; i < n; i++) {
    cout << i << ":";
    for (int e = head[i]; ~e; e = edges[e].nxt) {
      cout << " " << edges[e].to;
    }
    cout << endl;
  }
  return 0;
}