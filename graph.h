#pragma once
#include <stdio.h>
#include <stdlib.h>

#define vertex int

typedef struct node *link;

struct graph {
  int V;
  int A;
  link *adj;
};
typedef struct graph *Graph;

struct node {
  vertex w;
  link next;
};

link new_node(vertex w, link next);
Graph graph_init(int V);
void graph_insert_arc(Graph G, vertex v, vertex w);
int is_isolated(Graph G, vertex v);
int graph_outdeg(Graph G, vertex v);
int graph_indeg(Graph G, vertex v);
