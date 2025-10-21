#include "graph.h"
#include <stdio.h>

int main(void) {
  Graph G = graph_init(5);

  graph_insert_arc(G, 0, 1);
  graph_insert_arc(G, 0, 2);
  graph_insert_arc(G, 1, 2);
  graph_insert_arc(G, 2, 3);
  graph_insert_arc(G, 3, 4);
  graph_insert_arc(G, 4, 0);

  for (int v = 0; v < G->V; ++v) {
    int indeg = graph_indeg(G, v);
    int outdeg = graph_outdeg(G, v);
    printf("vertice %d: indeg = %d, outdeg = %d\n", v, indeg, outdeg);
  }

  return 0;
}
