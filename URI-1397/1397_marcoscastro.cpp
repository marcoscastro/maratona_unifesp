#include <stdio.h>

int main()
{
	while(1)
	{
		int N, A, somaA = 0, B, somaB = 0;
		
		scanf("%d", &N);
		if(N == 0) break;
		for(int i = 0; i < N; i++)
		{
			scanf("%d %d", &A, &B);
			if(A > B)
				somaA++;
			else if(A < B)
				somaB++;
		}
		printf("%d %d\n", somaA, somaB);
	}
}
