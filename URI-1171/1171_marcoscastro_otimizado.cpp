// versão com tempo 0.000

#include <stdio.h>
#include <vector>

using namespace std;

int main() 
{
	int N, num;
	vector<int> v(2000);
	
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		v[num-1]++;
	}
	
	for(int i = 0; i < 2000; i++)
	{
		if(v[i] != 0)
			printf("%d aparece %d vez(es)\n", i + 1, v[i]);
	}
	
	return 0;
}
