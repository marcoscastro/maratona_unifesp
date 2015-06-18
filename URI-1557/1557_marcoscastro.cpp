#include <stdio.h>
#include <math.h>

// obtém o número de dígitos de um número inteiro
int obter_num_digitos(int N)
{
	int q_digitos = 0;
	
	while(N) // enquanto N diferente de 0
	{
		N /= 10;
		q_digitos++;
	}
	return q_digitos;
}

int main()
{
	int N; // ordem da matriz
	
	while(1)
	{
		scanf("%d", &N);
		
		if(N == 0)
			break;
			
		if(N == 1)
			printf("1\n");
		else
		{
			/*
				diagonal principal é uma PG de razão 4
				an = a1 * q ^ (N - 1)
				como a1 é sempre 1, então an = q^(n-1)
			 */
			int maior = pow(4, N - 1);
			
			// obtém quantidade de dígitos do número
			int num_digitos = obter_num_digitos(maior);
			
			// obtém o limite das linhas
			int limite_i = pow(2, N - 1);
			
			// imprime a matriz
			for(int i = 1; i <= limite_i; i *= 2)
			{
				// obtém o limite das colunas
				int limite_j = i * pow(2, N - 1);
				
				/*
					no primeiro número de cada linha só formata,
					não coloca o espaço em branco
				*/
				printf("%*d", num_digitos, i);
				
				/*
					nos números restantes formata e coloca
					o espaço em branco
				*/
				for(int j = i * 2; j <= limite_j; j *= 2)
					printf(" %*d", num_digitos, j);
				printf("\n");
			}
		}
		
		// linha em branco
		printf("\n");
	}
	
	return 0;
}
