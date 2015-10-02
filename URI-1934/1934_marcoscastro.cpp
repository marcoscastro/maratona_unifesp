#include <iostream>
#include <vector>
#include <map>
#define INFINITO 10000000

using namespace std;

int main(int argc, char *argv[])
{
	int L, C;

	// obt�m linhas e colunas
	cin >> L;
	cin >> C;

	/*
		mat -> matriz do quebra-cabe�a
		vet_linhas -> guarda a soma das linhas
		vet_colunas -> guarda a soma das colunas
		valores -> mapa com a vari�vel (chave) e o seu valor
	*/
	vector<vector<string> > mat(L);
	for(int i = 0 ; i < L ; i++)
		mat[i].resize(C);

	int vet_linhas[L], vet_colunas[C];
	map<string, int> valores;

	// obt�m as entradas da matriz e as somas das linhas
	for(int i = 0; i < L; i++)
	{
		for(int j = 0; j < C; j++)
		{
			cin >> mat[i][j];
			valores[mat[i][j]] = INFINITO;
		}
		cin >> vet_linhas[i];
	}

	// obt�m as somas das colunas
	for(int i = 0; i < C; i++)
		cin >> vet_colunas[i];

	// obt�m a quantidade de vari�veis pelo tamanho do map valores
	int qte_vars = valores.size();

	// quantidade de vari�veis descobertas
	int qte_descobertas = 0;

	/*
		Sempre � poss�vel encontrar uma linha ou coluna em que
		h� apenas uma vari�vel cujo valor ainda � desconhecido!!
	*/
	while(true)
	{
		// verifica se o quebra-cabe�a est� completo
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
					// verifica se existe mais de uma vari�vel desconhecida
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

			// verifica se consegue desvendar a vari�vel na linha
			if(linha_verdade && vars_conhecidas < C)
			{
				// verifica se a linha � formada somente por uma vari�vel
				if(vars_conhecidas == 0)
				{
					// calcula o valor da vari�vel desconhecida
					valores[var_desconhecida] = vet_linhas[i] / C;
				}
				else
				{
					/*
						Se caiu aqui � porque existe somente uma
						vari�vel desconhecida e as outras s�o conhecidas.
						A soma dos valores das conhecidas est� em "soma".
					*/
					valores[var_desconhecida] = (vet_linhas[i] - soma) / qtd_desconhecida;
				}

				// incrementa a quantidade de vari�veis descobertas
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
					// verifica se existe mais de uma vari�vel desconhecida
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

			// verifica se consegue desvendar a vari�vel na coluna
			if(coluna_verdade && vars_conhecidas < L)
			{
				// verifica se a coluna � formada somente por uma vari�vel
				if(vars_conhecidas == 0)
				{
					// calcula o valor da vari�vel desconhecida
					valores[var_desconhecida] = vet_colunas[i] / L;
				}
				else
				{
					/*
						Se caiu aqui � porque existe somente uma
						vari�vel desconhecida e as outras s�o conhecidas.
						A soma dos valores das conhecidas est� em "soma".
					*/
					valores[var_desconhecida] = (vet_colunas[i] - soma) / qtd_desconhecida;
				}

				// incrementa a quantidade de vari�veis descobertas
				qte_descobertas++;
			}
		}
	}

	// mostra as vari�veis do map valores
	map<string, int>::iterator it;
	for(it = valores.begin(); it != valores.end(); it++)
		cout << it->first << " " << it->second << endl;

	return 0;
}