#include <iostream>
using namespace std;

#define MAX 10

// Node structure
struct Node {
    int data;
};

// Graph data
Node nodes[MAX];      // Array of nodes
int adj[MAX][MAX];    // Adjacency matrix
int visited[MAX];
int n;

// Add edge
void insertEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Delete edge
void deleteEdge(int u, int v) {
    adj[u][v] = 0;
    adj[v][u] = 0;
}

// DFS
void DFS(int node) {
    cout << nodes[node].data << " ";
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

// BFS
void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int node = queue[front++];
        cout << nodes[node].data << " ";

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

// Main
int main() {
    cout << "Enter number of nodes: ";
    cin >> n;

    // Initialize nodes
    for (int i = 0; i < n; i++) {
        nodes[i].data = i;   // Assign values (0,1,2,...)
        visited[i] = 0;

        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Insert edges
    insertEdge(0, 1);
    insertEdge(0, 2);
    insertEdge(1, 3);
    insertEdge(2, 4);

    cout << "\nDFS: ";
    DFS(0);

    cout << "\nBFS: ";
    BFS(0);

    // Delete edge
    deleteEdge(0, 2);

    cout << "\nAfter deleting edge (0,2), BFS: ";
    BFS(0);

    return 0;
}