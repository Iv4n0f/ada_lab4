#include <stdio.h>
#include "graph.h"

int main(void) {
  Graph G = graph_init(5);

  graph_insert_arc(G, 0, 1);
  graph_insert_arc(G, 0, 2);
  graph_insert_arc(G, 1, 3);
  graph_insert_arc(G, 3, 4);

  printf("Antes de eliminar:\n");
  graph_show(G);

  graph_remove_arc(G, 0, 2);
  graph_remove_arc(G, 3, 4);

  printf("\nDespues de eliminar:\n");
  graph_show(G);

  graph_destroy(G);
  return 0;
}
