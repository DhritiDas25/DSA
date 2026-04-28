/*1. Accept the vertices and edges for a graph and stores it as an adjacency matrix.
Implement functions to print in-degree and out-degree of any vertex 'i'. Also display the adjacency matrix.*/
#include <stdio.h>

int main() {
    int v, e, i, j, u, src, dest;
    int adj[20][20] = {0}; // Maximum 20 vertices (0-19)

    printf("Enter number of vertices (max 20): ");
    if (scanf("%d", &v) != 1 || v > 20) {
        printf("Invalid input or too many vertices.\n");
        return 1;
    }

    printf("Enter number of edges: ");
    if (scanf("%d", &e) != 1) return 1;

    for(i = 0; i < e; i++) {
        printf("Edge %d - Enter (source destination): ", i + 1);
        if (scanf("%d %d", &src, &dest) != 2) {
            printf("Invalid edge input.\n");
            return 1;
        }

        // Fix: Check if input exceeds array bounds
        if (src >= v || dest >= v || src < 0 || dest < 0) {
            printf("Error: Vertex index must be between 0 and %d\n", v-1);
            i--; // Decrement to retry this edge
            continue;
        }
        adj[src][dest] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < v; i++) {
        for(j = 0; j < v; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter vertex to find degrees (0 to %d): ", v-1);
    if (scanf("%d", &u) != 1 || u >= v || u < 0) {
        printf("Invalid vertex.\n");
        return 1;
    }

    int in_deg = 0, out_deg = 0;
    for(i = 0; i < v; i++) {
        if(adj[u][i] == 1) out_deg++; // Row check for Out-degree
        if(adj[i][u] == 1) in_deg++;  // Column check for In-degree
    }

    printf("Vertex %d -> In-degree: %d, Out-degree: %d\n", u, in_deg, out_deg);
    
    return 0;
}
