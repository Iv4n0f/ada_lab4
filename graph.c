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

int is_adjacent(Graph G, vertex v, vertex w) {
  for (link a = G->adj[v]; a != NULL; a = a->next)
    if (a->w == w)
      return 1;

  for (link a = G->adj[w]; a != NULL; a = a->next)
    if (a->w == v)
      return 1;

  return 0;
}

void graph_show(Graph G) {
  for (vertex v = 0; v < G->V; ++v) {
    printf("%d:", v);
    for (link a = G->adj[v]; a != NULL; a = a->next)
      printf(" %d", a->w);
    printf("\n");
  }
}

void graph_destroy(Graph G) {
  if (G == NULL)
    return;

  for (vertex v = 0; v < G->V; ++v) {
    link a = G->adj[v];
    while (a != NULL) {
      link temp = a;
      a = a->next;
      free(temp);
    }
  }

  free(G->adj);
  free(G);
}

void graph_remove_arc(Graph G, vertex v, vertex w) {
  if (G == NULL)
    return;

  link prev = NULL;
  link curr = G->adj[v];

  while (curr != NULL) {
    if (curr->w == w) {
      if (prev == NULL)
        G->adj[v] = curr->next;   // primero
      else
        prev->next = curr->next;  // medio o final

      free(curr);
      G->A--;
      return;
    }
    prev = curr;
    curr = curr->next;
  }
}

int graph_undir(Graph G) {
  for (vertex v = 0; v < G->V; ++v) {
    for (link a = G->adj[v]; a != NULL; a = a->next) {
      vertex w = a->w;
      int found = 0;

      // existe w -> v?
      for (link b = G->adj[w]; b != NULL; b = b->next) {
        if (b->w == v) {
          found = 1;
          break;
        }
      }

      if (!found)
        return 0; // falta el arco opuesto no es dirigido
    }
  }
  return 1; // todos los arcos tienen su opuesto
}
