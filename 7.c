
#include <stdio.h>
#include "graph.h"

int main(void) {
  Graph G = graph_init(4);

  // caso 1: grafo no dirigido
  graph_insert_arc(G, 0, 1);
  graph_insert_arc(G, 1, 0);
  graph_insert_arc(G, 2, 3);
  graph_insert_arc(G, 3, 2);

  printf("grafo 1:\n");
  graph_show(G);
  printf("no dirigido? %s\n", graph_undir(G) ? "si" : "no");

  // caso 2: grafo dirigido
  Graph H = graph_init(3);
  graph_insert_arc(H, 0, 1);
  graph_insert_arc(H, 1, 2);

  printf("\ngrafo 2:\n");
  graph_show(H);
  printf("no dirigido? %s\n", graph_undir(H) ? "si" : "no");

  graph_destroy(G);
  graph_destroy(H);
  return 0;
}
