#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


// estado representa cada nó (vértice)
typedef struct estado 
{
	int tam; // tamanho do estado (quantidade de números)
	vector<int> numeros; // conjunto de números que forma um estado
	vector<struct estado> filhos; // cada estado tem seus estados filhos
}t_estado;


// estrutura de árvore
typedef struct arvore
{
	t_estado estado_inicial;
	t_estado estado_final;
	bool achou;
	
	// construtor
	arvore(t_estado estado_inicial, t_estado estado_final)
	{
		this->estado_inicial = estado_inicial;
		this->estado_final = estado_final;
		this->achou = false;
	}
	
	// gera os estados filhos a partir de um estado
	void gerar_estados(t_estado e)
	{
		// só chama se ainda não achou
		if(this->achou == false)
		{
			// verifica se o estado "e" é igual ao estado final
			if((e.tam == this->estado_final.tam) && (equal(e.numeros.begin(), e.numeros.end(), this->estado_final.numeros.begin())))
			{
				this->achou = true;
				return;
			}
			
			// só gera filhos se o tamanho de "e" for maior que 1 E for maior que o tamanho do estado final
			if(e.tam > 1 && e.tam > estado_final.tam)
			{
				int tam_filhos = 0;
				
				// faz todos os cortes
				for(int corte = 1; corte < e.tam; corte++)
				{
					int ini = corte - 1, fim = corte;
					t_estado estado_filho;
					
					// faz a dobra através das somas
					while(1)
					{
						// verifica os extremos
						if(ini < 0 || fim == e.tam)
							break;
						
						estado_filho.numeros.push_back(e.numeros[ini] + e.numeros[fim]);
						
						// percorre no sentido: <- ->
						ini--;
						fim++;
					}
					
					// adiciona o restante (se houver)
					if(ini < 0 && fim < e.tam)
					{
						for(int i = fim; i < e.tam; i++)
							estado_filho.numeros.push_back(e.numeros[i]);
					}
					else if(ini >= 0 && fim == e.tam)
					{
						for(int i = ini; i >= 0; i--)
							estado_filho.numeros.push_back(e.numeros[i]);
					}
					
					// armazena o tamanho do estado
					estado_filho.tam = estado_filho.numeros.size();
					
					/*
						NÃO adiciona se o estado filho tiver
						tamanho menor que o estado final
					*/
					if(estado_filho.tam >= this->estado_final.tam)
					{
						// adiciona ao vetor de filhos
						e.filhos.push_back(estado_filho);
						
						// incrementa a quantidade de filhos
						tam_filhos++;
						
						// faz o reverso do filho se o tamanho for maior que 1
						if(estado_filho.tam > 1)
						{
							vector<int> filho_copia;
							// faz o reverse copy
							reverse_copy(estado_filho.numeros.begin(), estado_filho.numeros.end(), back_inserter(filho_copia));
							
							// compara se NÃO são iguais (não adiciona filhos repetidos)
							if(!equal(estado_filho.numeros.begin(), estado_filho.numeros.end(), filho_copia.begin()))
							{
								// cria o filho 2
								t_estado estado_filho2;
								estado_filho2.tam = estado_filho.tam;
								estado_filho2.numeros = filho_copia;
								
								// adiciona o filho 2
								e.filhos.push_back(estado_filho2);
								
								// incrementa a quantidade de filhos
								tam_filhos++;
							}
						}
					}
				}
				
				// faz uma busca para todos os estados filhos
				for(int i = 0; i < tam_filhos; i++)
					gerar_estados(e.filhos[i]);
			}
		}
	}
	
	void buscar()
	{
		// se o inverso de "e" for igual ao estado final, então achou
		vector<int> inverso;
		reverse_copy(this->estado_inicial.numeros.begin(), this->estado_inicial.numeros.end(), back_inserter(inverso));
		if((equal(this->estado_final.numeros.begin(), this->estado_final.numeros.end(), inverso.begin())))
			this->achou = true;
		else
		{
			/*
				verifica a soma do vetor para evitar um pior caso
				de dobrar toda a fita (sobrar um element) e não
				ser igual
			*/
			if(this->estado_final.tam == 1)
			{
				int soma = accumulate(this->estado_inicial.numeros.begin(), this->estado_inicial.numeros.end(), 0);
				if(soma == this->estado_final.numeros[0])
					this->achou = true;
				else
					this->achou = false;
			}
			else
				gerar_estados(this->estado_inicial);
		}
		
		if(this->achou)
			printf("S\n");
		else
			printf("N\n");
	}
	
}t_arvore;

int main()
{
	int N;
	
	while(scanf("%d", &N) != EOF)
	{
		t_estado estado_inicial, estado_final;
		
		estado_inicial.tam = N;
		for(int i = 0; i < N; i++)
		{
			int X;
			scanf("%d", &X);
			estado_inicial.numeros.push_back(X);
		}
		
		int M;
		
		scanf("%d", &M);
		estado_final.tam = M;
		
		for(int i = 0; i < M; i++)
		{
			int X;
			scanf("%d", &X);
			estado_final.numeros.push_back(X);
		}
		
		t_arvore arv(estado_inicial, estado_final);
		
		// realiza a busca
		arv.buscar();
	}
	return 0;
}
