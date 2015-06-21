#include <stdio.h>
#include <ctype.h>
#define MAX 1000

int main()
{
	char s[MAX];
	
	while(1)
	{
		scanf("%[^\n]%*c", s);
		
		if(s[0] == '*')
			break;
		
		bool espaco = false;
		char c = tolower(s[0]);
		char resp = 'Y';
		int i = 1;
		
		while(s[i] != '\0')
		{
			if(s[i] == ' ')
				espaco = true;
			else
			{
				if(espaco)
				{
					if(c != tolower(s[i]))
					{
						resp = 'N';
						break;
					}
					espaco = false;
				}
			}
			i++;
		}
		
		printf("%c\n", resp);
	}
	return 0;
}
