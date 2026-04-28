/*2.Accept the graph as an adjacency matrix and check if the graph is undirected.
[Hint: The matrix for an undirected graph is symmetric.]*/
#include <stdio.h>

int main() {
    int v, i, j, isUndirected = 1;
    int adj[20][20];

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    printf("Enter Adjacency Matrix:\n");
    for(i = 0; i < v; i++) {
        for(j = 0; j < v; j++) scanf("%d", &adj[i][j]);
    }

    // Check for symmetry: adj[i][j] must equal adj[j][i]
    for(i = 0; i < v; i++) {
        for(j = 0; j < v; j++) {
            if(adj[i][j] != adj[j][i]) {
                isUndirected = 0;
                break;
            }
        }
    }

    if(isUndirected) printf("\nThe graph is Undirected (Symmetric).\n");
    else printf("\nThe graph is Directed (Asymmetric).\n");

    return 0;
}
