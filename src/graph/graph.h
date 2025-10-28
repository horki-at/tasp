#ifndef INCLUDED_GRAPH_
#define INCLUDED_GRAPH_

#include <stddef.h>

typedef struct
{
    int x, y;
} Vertex;

typedef struct
{
    size_t size;
    Vertex *data;
    float *distance;
} Graph;

Graph graph_create_rand(size_t size, int min, int max);
Graph graph_create_stdin(void);

void graph_destroy(Graph graph);           // destroy the graph
void graph_display(Graph graph);           // display the graph
void graph_distances_display(Graph graph); // display the distances matrix

#endif
