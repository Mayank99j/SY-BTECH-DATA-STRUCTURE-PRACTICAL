#include <iostream>
using namespace std;

class Graph {
    int adj[10][10], V;
    string city[10];
public:
    Graph(int v) {
        V = v;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
    }
    void setCity(int index, string name) { city[index] = name; }
    void addEdge(int u, int v) { adj[u][v] = adj[v][u] = 1; }

    void DFS_Helper(int current, bool visited[]) {
        visited[current] = true;
        cout << city[current] << " -> ";
        for (int i = 0; i < V; i++)
            if (adj[current][i] && !visited[i])
                DFS_Helper(i, visited);
    }

    void DFS(int start) {
        bool visited[10] = {false};
        cout << "Salesperson Journey:\n";
        DFS_Helper(start, visited);
        cout << "[Return to " << city[start] << "]\n";
    }
};

int main() {
    Graph g(5);
    g.setCity(0, "Office");
    g.setCity(1, "Pune");
    g.setCity(2, "Mumbai");
    g.setCity(3, "Surat");
    g.setCity(4, "Ahmedabad");

    g.addEdge(0,1); g.addEdge(1,2); g.addEdge(2,3);
    g.addEdge(3,4); g.addEdge(4,0);

    g.DFS(0);
    return 0;
}