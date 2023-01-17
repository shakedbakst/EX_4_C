#include "graph.h"

bool empty(int n, int length);
int Min(int len[], int n[], int length);
int Max(pnode node);
int Dijkstra(pnode head, int start, int endPoint);
void short_path_cmd(pnode head);
int *delete_array(int arr[], int length, int e);
void print_arr(int arr[], int length);
int extra(pnode head, int start, int arr[], int length);
void TSP(pnode head);