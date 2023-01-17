#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "graph.h"
#include "algo.h"



int main(){ 
    char choice;
    int notEOF = 1; 
    int temp = 0;

    pnode headOfGraph = NULL;

while (notEOF == 1){
    if (!temp){
        int in = scanf(" %c", &choice);
        if (in == EOF){
            notEOF = 0;
        }
    }
    if (notEOF == 1){
        temp = 0;
        switch (choice) {
            case 'A':
                deleteGraph_cmd(&headOfGraph);
                choice = build_graph_cmd(&headOfGraph);
                temp = 1;
                break;
            case 'B':
                insert_node_cmd(&headOfGraph);
                break;
            case 'D':
                delete_node_cmd(&headOfGraph);
                break;
            case 'S':
                short_path_cmd(headOfGraph);
                break;
            case 'T':
                TSP(headOfGraph);
                break;
            default:
                break;
        }
    }
}
       
     deleteGraph_cmd(&headOfGraph);
    
}