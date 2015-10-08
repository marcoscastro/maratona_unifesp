// Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1806

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#define INFINITO 100000
using namespace std;

vector<int> dist_bino, dist_criminosos;

void dijkstra(vector<list<pair<int, int> > > grafo,
			  int orig, int dest, int N, bool bino = true)
{

	// set usado como fila de prioridade m�nima
	set<pair<int, int> > fila;

	// vetor de visitados
	vector<int> visitados(N);
	for(int i = 0; i < N; i++)
		visitados[i] = false;

	// inicia o vetor de dist�ncias
	if(bino)
	{
		for(int i = 0; i < N; i++)
			dist_bino.push_back(INFINITO);
	}
	else
	{
		for(int i = 0; i < N; i++)
			dist_criminosos.push_back(INFINITO);
	}

	// a dist�ncia da origem para origem � 0
	if(bino)
		dist_bino[orig] = 0;
	else
		dist_criminosos[orig] = 0;

	// insere na fila
	if(bino)
		fila.insert(make_pair(dist_bino[orig], orig));
	else
		fila.insert(make_pair(dist_criminosos[orig], orig));

	// loop do algoritmo do Dijkstra
	while(!fila.empty())
	{
		// obt�m o v�rtice com a menor dist�ncia
		set<pair<int, int> >::iterator it = fila.begin();
		int u = it->second;

		// remove da fila
		fila.erase(it);

		if(!visitados[u])
		{
			// marca como visitado
			visitados[u] = true;

			// percore os adjacentes de "u"
			list<pair<int, int> >::iterator it_list;

			if(bino)
			{
				for(it_list = grafo[u].begin();
						it_list != grafo[u].end(); it_list++)
				{
					// obt�m o v�rtice adjacente e o custo da aresta
					int v = it_list->first;
					int custo = it_list->second;

					// relaxamento
					if(dist_bino[v] > (dist_bino[u] + custo))
					{
						// atualiza a menor dist�ncia e insere na fila
						dist_bino[v] = dist_bino[u] + custo;
						fila.insert(make_pair(dist_bino[v], v));
					}
				}
			}
			else
			{
				for(it_list = grafo[u].begin();
						it_list != grafo[u].end(); it_list++)
				{
					// obt�m o v�rtice adjacente e o custo da aresta
					int v = it_list->first;
					int custo = it_list->second;

					// relaxamento
					if(dist_criminosos[v] > (dist_criminosos[u] + custo))
					{
						// atualiza a menor dist�ncia e insere na fila
						dist_criminosos[v] = dist_criminosos[u] + custo;
						fila.insert(make_pair(dist_criminosos[v], v));
					}
				}
			}
		}
	}
}

int main()
{
	/*
		N -> n�mero de lugares na cidade
		C -> n�mero de rotas conhecidas por Bino
		S -> n�mero de rotas conhecidas pelos criminosos
		B -> n�mero de criminosos
	*/
	int N, C, S, B;

	cin >> N >> C >> S >> B;

	vector<list<pair<int, int> > > grafo_bino(N);
	vector<list<pair<int, int> > > grafo_criminosos(N);


	// entradas para o grafo do Bino e dos criminosos
	for(int i = 0; i < C; i++)
	{
		int a, b, v;

		cin >> a >> b >> v;

		/*
			"a" est� ligado a "b" (vice-versa)
			a uma dist�ncia de "v" metros
		*/
		grafo_bino[a - 1].push_back(make_pair(b - 1, v));
		grafo_bino[b - 1].push_back(make_pair(a - 1, v));

		grafo_criminosos[a - 1].push_back(make_pair(b - 1, v));
		grafo_criminosos[b - 1].push_back(make_pair(a - 1, v));
	}

	// entradas somente para o grafo dos criminosos (rotas secretas)
	for(int i = 0; i < S; i++)
	{
		int a, b, v;

		cin >> a >> b >> v;

		/*
			"a" est� ligado a "b" (vice-versa)
			a uma dist�ncia de "v" metros
		*/
		grafo_criminosos[a - 1].push_back(make_pair(b - 1, v));
		grafo_criminosos[b - 1].push_back(make_pair(a - 1, v));
	}

	// mapa de criminosos e lugares onde eles est�o
	map<int, int> lugares_criminosos;

	for(int i = 0; i < B; i++)
		cin >> lugares_criminosos[i];

	/*
		K -> lugar inicial do Bino
		F -> lugar onde Bino vai ter que entregar a mensagem secreta
	*/
	int K, F;

	cin >> K >> F;

	// faz um dijkstra no grafo do Bino
	dijkstra(grafo_bino, K - 1, F - 1, N);

	// obt�m a menor dist�ncia do Bino ao destino
	int menor_dist_bino = dist_bino[F - 1];

	/*
		faz um dijkstra no grafo dos criminosos partindo de F - 1,
		como o grafo � bidirecional, ent�o teremos as menores
		dist�ncias do destino (F - 1) para todos os outros v�rtices
	*/
	dijkstra(grafo_criminosos, F - 1, 0, N, false);

	int qte_criminosos = 0;

	for(int i = 0; i < B; i++)
	{
		int dist_criminoso = dist_criminosos[lugares_criminosos[i] - 1];

		// verifica se a dist�ncia � menor ou igual
		if(dist_criminoso <= menor_dist_bino)
			qte_criminosos++;
	}

	cout << qte_criminosos << endl;

	return 0;
}
