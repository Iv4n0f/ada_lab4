#include <stdio.h>
#include "graph.h"

int main(void) {
  Graph G = graph_init(5);
  graph_insert_arc(G, 0, 1);
  graph_insert_arc(G, 1, 2);
  graph_insert_arc(G, 3, 4);
  for (int v = 0; v < G->V; ++v) {
    for (int w = 0; w < G->V; ++w) {
      if (v == w) continue;
      if (is_adjacent(G, v, w))
        printf("%d y %d son adyacentes\n", v, w);
    }
  }

  return 0;
}
