#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void addNewEdge(pnode start, pnode endPoint, int weight);
void removeExiting(pnode n);
void removeEdgesBetweenNodes(pnode NODE, pnode n);


//------------------HELP FUNCTIONS-------------

pnode createNewNode(int num){
    pnode newNode= (pnode)malloc(sizeof(node));

    if(newNode == NULL){
        printf("Error! Couldn't allocate space");
        return NULL;
    }   
    newNode -> node_num = num; 
    newNode -> edges = NULL;
    newNode -> next = NULL;
    
    return newNode;
}

pedge createNewEdge(int weight, pnode endPoint){
    pedge new_Edge = (pedge)malloc(sizeof(edge));
    if (new_Edge == NULL){
        printf("couldn't allocate space!");
        return NULL;
    }
    new_Edge->next = NULL;
    new_Edge->endpoint = endPoint;
    new_Edge->weight = weight;

    return new_Edge;
}

void addNewEdge(pnode start, pnode endPoint, int weight){
    if (start ==NULL || endPoint == NULL){
        return;
    }
    pedge new_edge = createNewEdge(weight, endPoint);
    pedge iteratingEdge = start->edges;
    while (iteratingEdge != NULL && iteratingEdge->next !=NULL){
        iteratingEdge = iteratingEdge->next;
    }

    if (iteratingEdge == NULL){
        start->edges = new_edge;
        return;
    }

    iteratingEdge->next = new_edge;
}

pnode findNode(pnode find, int num){
    while (find && find->node_num != num){
        find = find->next;
    }
    if (find == NULL){
        return NULL;
    }
    return find;
}

void removeOneEdgeEntring(pnode first, pnode second){
    pedge *previous = &first->edges;
    pedge p = first->edges;
    while (p != NULL){
    if (p->endpoint == second){
            *previous = p->next;
            free(p);
            p = *previous;
        }
    else{
        previous = &(p->next);
        p = p->next;            
        }
    }
}

void removeExiting(pnode n){
    pedge ed = n->edges;
    while (ed)
    {
        pedge e = ed;
        ed = ed->next;
        free(e);
    }
}

void removeEdgesBetweenNodes(pnode first, pnode second){
    if (first == NULL){
        return;
    }
    while (first != NULL) {
        removeOneEdgeEntring(first, second);
        first = first->next;
    }
    removeExiting(second);
}


void printGraph_cmd(pnode head) {
    pnode currentNode = head;
    while(currentNode != NULL) {
        printf("Node %d: Edges:\t ,", currentNode->node_num);
        pedge currentEdge = NULL;
        currentEdge = currentNode->edges;
        
        while(currentEdge != NULL) {
            printf("endPoint = %d, weight = %d , ", currentEdge->endpoint->node_num, currentEdge->weight);
            currentEdge = currentEdge->next;
        }
        printf("\n");
        currentNode = currentNode->next;
    }
    putchar('\n');
}


//---------------NEED TO USE FUNCTIONS----------------------
char build_graph_cmd(pnode *head){
    int size, count;
    char C;
    count = 0;
    scanf("%d", &size);
    pnode *p = head;

    while (count < size){
        pnode new_node = createNewNode(count);
        *p = new_node;
        p = &(*p)->next;
        count++;
    }
    while (scanf(" %c", &C) > 0){
        if (C!= 'n'){
            return C;
        }
        else{
            int num, weight, endPoint;
            scanf("%d", &num);
            pnode node = findNode(*head, num);

            while (scanf("%d", &endPoint) > 0){
                scanf("%d", &weight);
                addNewEdge(node, findNode(*head, endPoint), weight);
            }
        }
    }
    return C;
}

void insert_node_cmd(pnode *head){
    int num, weight, endPoint;
    pnode previous = *head;

    scanf("%d", &num);

    pnode new_node = findNode(*head, num);
    int is_there_node = 0;

    if (new_node == NULL){
        new_node = createNewNode(num);
    }
    else{
        is_there_node = 1;
        removeExiting(new_node);
        new_node->edges = NULL;
    }
    while (scanf("%d", &endPoint) > 0){
        scanf("%d", &weight);
        addNewEdge(new_node, findNode(*head, endPoint), weight);
    }

    if (is_there_node == 1 || *head == NULL){
        if (*head == NULL){
            *head = new_node;
            return;
        }
        return;
    }
    while (previous->next){
        previous= previous->next;
    }
    previous->next = new_node;
}

void delete_node_cmd(pnode *head){
    int num;
    if (*head == NULL)
        return;
    scanf("%d", &num);
    pnode temp = *head;
    pnode *previous = head;
    while (temp != NULL){
        if (temp->node_num != num){
            previous = &(temp ->next);
            temp = temp->next;   
        }
        else{
            break;
        }
    }
    if (temp ==NULL){
        return;
    }
    removeEdgesBetweenNodes(*head, temp);
    *previous = temp->next;
    free(temp);
}

void deleteGraph_cmd(pnode *head){
    pnode temp = *head;
    while (temp != NULL){
        removeExiting(temp);
        temp->edges = NULL;
        pnode todelete = temp;
        temp = temp->next;
        free(todelete);
    }
    *head = NULL;
}