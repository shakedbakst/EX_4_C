#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "graph.h"

#define INFINITY 10000000

int Max(pnode node){
    
    if (!node){
        return -1;
    }

    int MAX = node->node_num;
    while(node){
        if(node->node_num > MAX){
            MAX = node->node_num;
        }
        node = node->next;
    }

    return MAX;
}

/*int maximum_key(pnode NODE)
{
    if (NODE == NULL)
    {
        return -1;
    }

    int max = NODE->node_num;
    while (NODE)
    {
        if (NODE->node_num > max)
        {
            max = NODE->node_num;
        }
        NODE = NODE->next;
    }

    return max;
}*/

/*bool empty(int n[], int length){

    for (int i=0 ; i<length ; i++){
        if(!n[i]){
            return false;
        }
    }

    return true;
}


int Min(int len[], int n[], int length){

    int MIN = -1;

    for(int i=0 ; i<length ; i++){
        if (MIN == -1){
            if(len[i] != INF && !n[i]){
                MIN = i;
            }
        }

        else if (len[i] != INF && len[MIN]> len[i] && !n[i]){
            MIN = i;
        }
    }
    return MIN;
}



int Dijkstra(pnode head, int start, int endPoint){

    int distance = Max(head)+1;
    int *len = (int *)malloc(sizeof(int)*distance);
    int *n = (int *)malloc(sizeof(int)*distance);
    int min;

    if(!head){
        return -1;
    }
    
    for (int i=0 ; i<distance ; i++){
        n[i] = 0;
        if(!(findNode(head,i))){
            n[i] = 1;
        }
    }

    for (int i=0 ; i<distance ; i++){
        len[i] = INF;
    }
    len[start] = 0;

    while(!empty(n, distance) && (min = Min(len, n, distance))!=-1){
        pnode q = findNode(head, min);
        pedge edge = q->edges;
        
        while(edge){
            if(!n[edge->endpoint->node_num]){
                if(len[q->node_num] != INF && len[q->node_num]+edge->weight < len[edge->endpoint->node_num]){
                    len[edge->endpoint->node_num] = len[q->node_num]+edge->weight;
                }
            }
            edge = edge->next;
        }
        n[min] = 1;
    }
    
    free(n);

    if (len[endPoint] == INF){
        free(len);
        return -1;
    }

    int x = len[endPoint];
    free(len);
    return x;

}

void short_path_cmd(pnode head){

    int start, endpoint;

    if (!head){
        return;
    }

    scanf("%d, %d", &start, &endpoint);

    int res = Dijkstra(head, start, endpoint);

    if(res == -1){
        printf("Dijsktra shortest path: -1\n");
        return;
    }

    printf("Dijsktra shortest path: %d \n", res);

}


int *delete_array(int arr[], int length, int e){

    int *new_arr = (int *)malloc(sizeof(int) * length - 1);

    for (int i = 0, j = 0; i < length; i++){
        if (i != e){
            new_arr[j] = arr[i];
            j++;
        }
    }

    return new_arr;
}


void print_arr(int arr[], int length){

    for (int i = 0; i < length; i++){
        printf("%d ,", arr[i]);
    }

    printf("\n");
}



int extra(pnode head, int start, int arr[], int length){

    int min = INF;

    if (length == 1){
        return Dijkstra(head, start, arr[0]);
    }

   
    for (int i = 0; i < length; i++){

        if (i != start){

            int *q = delete_array(arr, length, i);
            int shortest = Dijkstra(head, start, arr[i]);
            int res = extra(head, arr[i], q, length - 1);
        
            if (shortest != -1 && res != -1 && res + shortest < min){
                min = res + shortest;
            }

            free(q);
        }
    }

    if (min == INF){
        return -1;
    }

    return min;
}


void TSP(pnode head){

    int min = INF;
    int len;
    scanf("%d", &len);
    int *array = (int *)malloc(sizeof(int) * len);
    
    for (int i = 0; i < len; i++){
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < len; i++){
        int *q = delete_array(array, len, i);
        int tsp = extra(head, array[i], q, len - 1);
        if (tsp != -1 && min > tsp){
            min = tsp;
        }

        free(q);
    }

    if (min == INF){
        printf("TSP shortest path: -1 \n");
    }
    else{
        printf("TSP shortest path: %d \n", min);
    }

    free(array);
}*/





bool is_empty(int is_v[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (!is_v[i])//is visited
        {
            return false;
        }
    }
    return true;
}



int Minimum(int dist[], int is_v[], int length)
{
    int min = -1;

    for (int i = 0; i < length; i++)
    {
        if (min == -1)
        {
            if (dist[i] != INFINITY && !is_v[i])
                min = i;
        }


        else if (dist[i] != INFINITY && dist[i] < dist[min] && !is_v[i])
            min = i;
    }



    return min;
}







int Dijkstra_Algorithm(pnode head, int src, int dest)
{
    if (head == NULL)
        return -1;

    int dist_length = Max(head) + 1;


    int *dist = (int *)malloc(sizeof(int) * dist_length);

    int *is_v = (int *)malloc(sizeof(int) * dist_length);

    
    for (int i = 0; i < dist_length; i++)
    {
        is_v[i] = 0;
        if (findNode(head, i) == NULL)
            is_v[i] = 1;
    }

    
    for (int i = 0; i < dist_length; i++)
        dist[i] = INFINITY;
    dist[src] = 0;

    int min;
    while (!is_empty(is_v, dist_length) && (min = Minimum(dist, is_v, dist_length)) != -1)
    {
        pnode p = findNode(head, min);
        pedge edge = p->edges;
        while (edge)
        {
            if (!is_v[edge->endpoint->node_num])
            {
                if (dist[p->node_num] != INFINITY && dist[p->node_num] + edge->weight < dist[edge->endpoint->node_num])
                {
                    dist[edge->endpoint->node_num] = dist[p->node_num] + edge->weight;
                }
            }
            edge = edge->next;
        }
        is_v[min] = 1;
    }

 
    free(is_v);

    if (dist[dest] == INFINITY)
    {
        free(dist);
        return -1;
    }

    int x = dist[dest];
    free(dist);
    return x;
}

//using Dijkstra Algorithm
void shortsPath_cmd(pnode head)
{
    if (head == NULL)
        return;

    int src, dest;
    scanf("%d %d", &src, &dest);//getting source and destination

    int ans = Dijkstra_Algorithm(head, src, dest);

    if (ans == -1)
    {
        printf("Dijsktra shortest path: -1 \n");
        return;
    }
    printf("Dijsktra shortest path: %d \n", ans);
}

int *delete_from_array(int arr[], int length, int k)
{
    int *new_array = (int *)malloc(sizeof(int) * length - 1);
    for (int i = 0, j = 0; i < length; i++)
    {
        if (i != k)
        {
            new_array[j] = arr[i];
            j++;
        }
    }
    return new_array;
}




void printArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ,", arr[i]);

    printf("\n");
}






int helper(pnode head, int src, int arr[], int length)
{
    if (length == 1)
        return Dijkstra_Algorithm(head, src, arr[0]);

    int min = INFINITY;

    for (int i = 0; i < length; i++)
    {
        if (i != src)
        {
            int *p = delete_from_array(arr, length, i);

            int _shortest = Dijkstra_Algorithm(head, src, arr[i]);

            int ans = helper(head, arr[i], p, length - 1);

            if (_shortest != -1 && ans != -1 && ans + _shortest < min)
                min = ans + _shortest;

            free(p);
        }
    }

    if (min == INFINITY)
        return -1;




    return min;
}






void TSP_cmd(pnode head)
{
    int length;
    scanf("%d", &length);//getting the size 

    int *arr = (int *)malloc(sizeof(int) * length);

    for (int i = 0; i < length; i++)
        scanf("%d", &arr[i]);

    int min = INFINITY;
    for (int i = 0; i < length; i++)
    {
        int *p = delete_from_array(arr, length, i);
        int tsp = helper(head, arr[i], p, length - 1);
        if (tsp != -1 && min > tsp)
        {
            min = tsp;
        }


        free(p);
    }





    if (min == INFINITY)
    {
        printf("TSP shortest path: -1 \n");
    }
    else
    {
        printf("TSP shortest path: %d \n", min);
    }






    free(arr);
}




