// https://www.urionlinejudge.com.br/judge/pt/problems/view/1321

#include <stdio.h>
#include <string.h> // memset
#include <stdlib.h> // qsort

/*
	São distribuídas 3 cartas para cada jogador.
	O problema fornece as 3 cartas da princesa e
	2 cartas do príncipe. Deve-se descobrir a terceira
	carta dada pelo criado para o príncipe que fará com
	que ele ganhe independente do modo como ele jogar.
	Um jogador ganha o jogo se ganhar dois turnos.
*/

int compare(const void * x, const void * y)
{
	return (*(int*)x - *(int*)y);
}

int main()
{
	int A, B, C, X, Y;
	
	while(1)
	{
		int cartas[52];
		
		// inicializa as cartas com 0 (não utilizadas)
		memset(cartas, 0, sizeof(cartas));
		
		// obtém as entradas
		scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
		
		if(A == 0)
			break;
		
		// marca as cartas utilizadas
		cartas[A - 1] = 1;
		cartas[B - 1] = 1;
		cartas[C - 1] = 1;
		cartas[X - 1] = 1;
		cartas[Y - 1] = 1;
		
		int cartas_princesa[] = {A, B, C};
		
		// ordena as cartas da princesa em ordem crescente
		qsort(cartas_princesa, 3, sizeof(int), compare);
		
		int resp = -1;
		
		// testa todas as cartas (menor carta possível)
		for(int carta = 1; carta <= 52; carta++)
		{
			if(cartas[carta - 1] == 0)
			{
				int rounds_princesa = 0, rounds_principe = 0;
					
				int cartas_principe[] = {X, Y, carta};
				qsort(cartas_principe, 3, sizeof(int), compare);
				
				// primeiro round
				// menor da princesa com maior do príncipe
				// isso serve para eliminar a maior carta do príncipe
				if(cartas_princesa[0] > cartas_principe[2])
					rounds_princesa++;
				else
					rounds_principe++;
					
				// segundo round
				// a princesa joga com a maior e o principe com o segundo maior
				if(cartas_princesa[2] > cartas_principe[1])
					rounds_princesa++;
				else
					rounds_principe++;
					
				// terceiro round
				// princesa joga com a segunda maior e o principe com a menor
				if(cartas_princesa[1] > cartas_principe[0])
					rounds_princesa++;
				else
					rounds_principe++;
					
				// testa se o príncipe ganhou
				if(rounds_principe >= 2)
				{
					resp = carta;
					break;
				}
			}
		}
		
		if(resp != -1)
			printf("%d\n", resp);
		else
			printf("-1\n");
	}
	return 0;
}
