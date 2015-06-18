#include <stdio.h>
#include <string.h> // memset

int main()
{
	int v[2000], N, X;
	scanf("%d", &N);
	
	memset(v, 0, sizeof(v));
	
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &X);
		v[X - 1]++;
	}
	
	for(int i = 0; i < 2000; i++)
	{
		if(v[i] != 0)
			printf("%d aparece %d vez(es)\n", i + 1, v[i]);
	}
	
	return 0;
}
