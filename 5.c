#include <stdio.h>
#include "graph.h"

int main(void) {
  Graph G = graph_init(4);

  graph_insert_arc(G, 0, 1);
  graph_insert_arc(G, 1, 2);
  graph_insert_arc(G, 2, 3);

  printf("Grafo antes de liberar:\n");
  graph_show(G);

  graph_destroy(G);
  printf("Memoria liberada correctamente\n");
  // graph_show dara segmentation fault
  graph_show(G);

  return 0;
}
