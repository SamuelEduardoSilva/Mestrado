#include <bits/stdc++.h>

using namespace std;

int cont;
int particiona(int sum, int n, vector<int> numeros)
{
	if(sum == n)
	{
		cont++;
		for(int i = 0 ; i < numeros.size(); i++)
		{
			printf("%d ", numeros[i]);
		}
		printf("\n");
	}
	else
	{
		int inicio = 1;
		if(numeros.size()) inicio=numeros[numeros.size() - 1];
		for(int i = inicio ; i <= n ; i++)
		{
			if(sum + i <= n)
			{
				vector<int>novo = numeros;
				novo.push_back(i);
				particiona(sum + i, n, novo);
			}
		}
	}
}


int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		cont = 0;
		vector<int>x;
	particiona(0, n,x);
	printf("Numero de particoes: %d\n", cont);
	}
	
	

	return 0;
}