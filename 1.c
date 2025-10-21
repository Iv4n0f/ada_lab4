#include "graph.h"
#include <stdio.h>

int main(void) {
  Graph G = graph_init(5);

  graph_insert_arc(G, 0, 1);
  graph_insert_arc(G, 1, 2);
  graph_insert_arc(G, 2, 3);

  for (int v = 0; v < G->V; ++v) {
    if (is_isolated(G, v))
      printf("El vertice %d esta aislado\n", v);
    else
      printf("El vertice %d NO esta aislado\n", v);
  }

  return 0;
}
