#include <stdio.h>

int kadane(int cot[], int N, int C)
{
	int max_atual, max_final, max_lucro = 0;

	max_atual = max_final = cot[0];

	for(int i = 1; i < N; i++)
	{
		if((max_atual > cot[i] && (max_atual - cot[i] >= C))
				|| cot[i] < max_final)
		{
			if(max_atual - max_final - C > 0)
				max_lucro += max_atual - max_final - C;
			max_atual = max_final = cot[i]; 
		}
		if(cot[i] > max_atual)
			max_atual = cot[i];
	}
	
	if(max_atual - max_final - C > 0)
		max_lucro += max_atual - max_final - C; 

	return max_lucro;
}

int main(int argc, char *argv[])
{
	int N, C;

	scanf("%d %d", &N, &C);

	int cot[N];

	for(int i = 0; i < N; i++)
		scanf("%d", &cot[i]);

	printf("%d\n", kadane(cot, N, C));

	return 0;
}
