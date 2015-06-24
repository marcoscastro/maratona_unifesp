// tempo: 0.304 (pode ser melhorado)

#include <stdio.h>
#include <math.h>
#include <set>

using namespace std;

int main()
{
	// N é a quantidade total de bolas
	// B são as bolas que sobraram no globo
	int N, B;
	
	while(1)
	{
		// entrada dos dados
		scanf("%d %d", &N, &B);
		
		// se N e B forem 0, então sai do loop
		if(N == 0 && B == 0)
			break;
			
		// vetor para armazenar as B bolas
		int bolas[B];
		
		// obtém as B bolas
		for(int i = 0; i < B; i++)
			scanf("%d", &bolas[i]);
			
		// conjunto para armazenar as diferenças
		set<int> dif_bolas;
			
		// calcula a diferença entre todas as bolas
		for(int i = 0; i < B; i++)
		{
			for(int j = i; j < B; j++)
				dif_bolas.insert(fabs(bolas[i] - bolas[j]));
		}
		
		// obtém o tamanho do conjunto
		int tam_dif_bolas = dif_bolas.size();
		
		/*
			o globo contém N+1 bolas numeradas de 0 até N
			compara tam_dif_bolas com (N + 1)
		*/
		if(tam_dif_bolas == (N + 1))
			printf("Y\n");
		else
			printf("N\n");
	}
	
	return 0;
}
