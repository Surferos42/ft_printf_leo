#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{

	char lol[50];
	
	int b = 0;
	int o = 0;	
	
	while(1)
	{
		printf("Wpisz swoje zdanie: ");
		fgets(lol, 50, stdin);
		
		if (lol[strlen(lol) - 1] != '\n')
		{
			printf("Za długie zdanie :( Jeszcze raz\n");
			
			int c;
			
			while ((c = getchar()) != '\n' && c != EOF);
			continue;
		}
		
		lol[strlen(lol) - 1] = '\0';
		
		int onlyspaces = 1;
		
		for (int i = 0; lol[i]; i++)
		{
			if (!isspace(lol[i]))
			{
				onlyspaces = 0;
				break;
			}		
				
		}

		if(strlen(lol) == 0 || onlyspaces)
		{
			o++;
			printf("Jeszcze raz wpisz swoje zdanie :): %d/5\n", o);
			
			if (o >= 5)
			{
				printf("Nic nie wpisałeś :(\n");
				break;
			}
			continue;
		}
		
	o = 0;
	
	int result = 0;
	
	for (int i = 0; lol[i]; i++)
	{
		if (!isspace(lol[i]))
		{
			result++;
		}
	}

	if (result >= 2 && result <= 4)
	{
		printf("Twoje zdanie %s, ma %d znaki.\n", lol, result);
	}
	else if (result >= 5)
	{
		printf("Twoje zdanie %s, ma %d znaków.\n", lol, result);
	}
	else
	{
		printf("Twoje zdanie %s, ma %d znak.\n", lol, result);
	}
	
	b++;
	if (b >= 5)
	{
		printf("Wpisano 5 zdań, koniec programu :)\n");
		break;
	}
	
	}
	return (0);
}
