#include "graph.h"

int main(void) {
  Graph G = graph_init(5);

  graph_insert_arc(G, 0, 1);
  graph_insert_arc(G, 0, 2);
  graph_insert_arc(G, 1, 3);
  graph_insert_arc(G, 3, 4);
  graph_insert_arc(G, 4, 0);

  graph_show(G);

  return 0;
}
