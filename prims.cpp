#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int, int> iPair;
class Graph
{
    int V;
    list<pair<int, int>> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void primMST();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::primMST()
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    int src = 0;

    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push(make_pair(0, src));
    key[src] = 0;
    vector<int> w;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (inMST[u] == true)
        {
            continue;
        }

        inMST[u] = true;
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            w.push_back(weight);
            if (inMST[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}

int main()
{
    // create the graph given in above figure
    int V = 6;
    Graph g(V);

    // making above shown graph
    g.addEdge(0, 1, 5);
    g.addEdge(0, 1, 6);
    g.addEdge(0, 2, 8);
    g.addEdge(0, 4, 7);
    g.addEdge(0, 3, 4);
    g.addEdge(2, 4, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 3, 1);
    g.addEdge(3, 5, 3);
    g.addEdge(1, 5, 3);
    g.addEdge(1, 5, 2);

    g.primMST();

    return 0;
}

