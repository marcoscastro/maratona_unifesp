#include <iostream>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo
{
public:
	int V;
	list<pair<int, int> > * adj;

	Grafo(int V)
	{
		this->V = V;
		adj = new list<pair<int, int> >[V];
	}

	void addAresta(int v1, int v2, int custo)
	{
		adj[v1].push_back(make_pair(v2, custo));
	}

	int dijkstra(int orig, int dest)
	{
		int dist[V], visitados[V];

		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		for(int i = 0; i < V; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		dist[orig] = 0;
		pq.push(make_pair(dist[orig], orig));

		while(!pq.empty())
		{
			pair<int, int> p = pq.top();
			int u = p.second;
			pq.pop();

			if(visitados[u] == false)
			{
				visitados[u] = true;
				list<pair<int, int> >::iterator it;

				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					int v = it->first;
					int custo_aresta = it->second;

					if(dist[v] > (dist[u] + custo_aresta))
					{
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		return dist[dest];
	}
};

int main(int argc, char *argv[])
{
	int C, V;

	cin >> C;
	cin >> V;

	Grafo g(C), g_aux(C);

	for(int i = 0; i < V; i++)
	{
		int v1, v2, custo;
		cin >> v1;
		cin >> v2;
		cin >> custo;

		g.addAresta(v1 - 1, v2 - 1, custo);
		g.addAresta(v2 - 1, v1 - 1, custo);
	}

	// gerando o grafo auxiliar
	for(int i = 0; i < C; i++)
	{
		list<pair<int, int> >::iterator it;
		for(it = g.adj[i].begin(); it != g.adj[i].end(); it++)
		{
			int adj = it->first;
			int custo = it->second;
			list<pair<int, int> >::iterator it2;
			bool tam_adj = g.adj[adj].size();

			if(tam_adj > 0)
			{
				for(it2 = g.adj[adj].begin(); it2 != g.adj[adj].end(); it2++)
				{
					int adj2 = it2->first;
					int custo2 = it2->second;
					g_aux.addAresta(i, adj2, custo + custo2);
				}
			}
		}
	}
	
	int custo_min = g_aux.dijkstra(0, C - 1);
	
	if(custo_min == INFINITO)
		cout << "-1\n";
	else
		cout << custo_min << endl;

	return 0;
}