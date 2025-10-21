#include "graph.h"
#include <stdlib.h>

link new_node(vertex w, link next) {
  link a = malloc(sizeof(struct node));
  a->w = w;
  a->next = next;
  return a;
}

Graph graph_init(int V) {
  Graph G = malloc(sizeof *G);
  G->V = V;
  G->A = 0;
  G->adj = malloc(V * sizeof(link));
  for (vertex v = 0; v < V; ++v)
    G->adj[v] = NULL;
  return G;
}

void graph_insert_arc(Graph G, vertex v, vertex w) {
  for (link a = G->adj[v]; a != NULL; a = a->next)
    if (a->w == w)
      return;
  G->adj[v] = new_node(w, G->adj[v]);
  G->A++;
}

int is_isolated(Graph G, vertex v) {
  if (G->adj[v] != NULL)
    return 0;

  for (vertex u = 0; u < G->V; ++u) {
    for (link a = G->adj[u]; a != NULL; a = a->next) {
      if (a->w == v)
        return 0;
    }
  }

  return 1;
}

int graph_outdeg(Graph G, vertex v) {
  int c = 0;
  for (link a = G->adj[v]; a != NULL; a = a->next)
    ++c;
  return c;
}

int graph_indeg(Graph G, vertex v) {
  int c = 0;
  for (vertex u = 0; u < G->V; ++u) {
    for (link a = G->adj[v]; a != NULL; a = a->next) {
      if (a->w == v)
        ++c;
    }
  }
  return c;
}
