#include <iostream>
#include <vector>
#include <map>
#define INFINITO 10000000

using namespace std;

int main(int argc, char *argv[])
{
	int L, C;

	// obtém linhas e colunas
	cin >> L;
	cin >> C;

	/*
		mat -> matriz do quebra-cabeça
		vet_linhas -> guarda a soma das linhas
		vet_colunas -> guarda a soma das colunas
		valores -> mapa com a variável (chave) e o seu valor
	*/
	vector<vector<string> > mat(L);
	for(int i = 0 ; i < L ; i++)
		mat[i].resize(C);

	int vet_linhas[L], vet_colunas[C];
	map<string, int> valores;

	// obtém as entradas da matriz e as somas das linhas
	for(int i = 0; i < L; i++)
	{
		for(int j = 0; j < C; j++)
		{
			cin >> mat[i][j];
			valores[mat[i][j]] = INFINITO;
		}
		cin >> vet_linhas[i];
	}

	// obtém as somas das colunas
	for(int i = 0; i < C; i++)
		cin >> vet_colunas[i];

	// obtém a quantidade de variáveis pelo tamanho do map valores
	int qte_vars = valores.size();

	// quantidade de variáveis descobertas
	int qte_descobertas = 0;

	/*
		Sempre é possível encontrar uma linha ou coluna em que
		há apenas uma variável cujo valor ainda é desconhecido!!
	*/
	while(true)
	{
		// verifica se o quebra-cabeça está completo
		if(qte_descobertas == qte_vars)
			break;

		// procura na linha
		for(int i = 0; i < L; i++)
		{
			string var_desconhecida;
			int vars_conhecidas = 0, qtd_desconhecida = 0, soma = 0;
			int linha_verdade = true;

			for(int j = 0; j < C; j++)
			{
				if(valores[mat[i][j]] == INFINITO)
				{
					// verifica se existe mais de uma variável desconhecida
					if(qtd_desconhecida >= 1 && var_desconhecida != mat[i][j]
							&& var_desconhecida.size() != 0)
					{
						linha_verdade = false;
						break;
					}
					var_desconhecida = mat[i][j];
					qtd_desconhecida++;
				}
				else
				{
					soma += valores[mat[i][j]];
					vars_conhecidas++;
				}
			}

			// verifica se consegue desvendar a variável na linha
			if(linha_verdade && vars_conhecidas < C)
			{
				// verifica se a linha é formada somente por uma variável
				if(vars_conhecidas == 0)
				{
					// calcula o valor da variável desconhecida
					valores[var_desconhecida] = vet_linhas[i] / C;
				}
				else
				{
					/*
						Se caiu aqui é porque existe somente uma
						variável desconhecida e as outras são conhecidas.
						A soma dos valores das conhecidas está em "soma".
					*/
					valores[var_desconhecida] = (vet_linhas[i] - soma) / qtd_desconhecida;
				}

				// incrementa a quantidade de variáveis descobertas
				qte_descobertas++;
			}
		}

		// procura na coluna
		for(int i = 0; i < C; i++)
		{
			string var_desconhecida;
			int vars_conhecidas = 0, qtd_desconhecida = 0, soma = 0;
			int coluna_verdade = true;

			for(int j = 0; j < L; j++)
			{
				if(valores[mat[j][i]] == INFINITO)
				{
					// verifica se existe mais de uma variável desconhecida
					if(qtd_desconhecida >= 1 && var_desconhecida != mat[j][i]
							&& var_desconhecida.size() != 0)
					{
						coluna_verdade = false;
						break;
					}
					var_desconhecida = mat[j][i];
					qtd_desconhecida++;
				}
				else
				{
					soma += valores[mat[j][i]];
					vars_conhecidas++;
				}
			}

			// verifica se consegue desvendar a variável na coluna
			if(coluna_verdade && vars_conhecidas < L)
			{
				// verifica se a coluna é formada somente por uma variável
				if(vars_conhecidas == 0)
				{
					// calcula o valor da variável desconhecida
					valores[var_desconhecida] = vet_colunas[i] / L;
				}
				else
				{
					/*
						Se caiu aqui é porque existe somente uma
						variável desconhecida e as outras são conhecidas.
						A soma dos valores das conhecidas está em "soma".
					*/
					valores[var_desconhecida] = (vet_colunas[i] - soma) / qtd_desconhecida;
				}

				// incrementa a quantidade de variáveis descobertas
				qte_descobertas++;
			}
		}
	}

	// mostra as variáveis do map valores
	map<string, int>::iterator it;
	for(it = valores.begin(); it != valores.end(); it++)
		cout << it->first << " " << it->second << endl;

	return 0;
}