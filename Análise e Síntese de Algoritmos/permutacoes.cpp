#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int vet[N], n;
int cont = 0;
void permuta(int inf, int sup, int k, int vet[])
{
	if(k == n)
	{
		cont++;
		for(int i = 0 ; i < n ; i++)
		{
			printf("%d ", vet[i]);
		}
		printf("\n");
	}
	else
	{
		for(int i = inf  ; i <= sup ; i++)
		{
			swap(vet[inf], vet[i]);
			permuta(inf+1, sup, k + 1, vet);
			swap(vet[inf], vet[i]);
		}
	}
}

int main()
{
	scanf("%d",&n);

	for(int i = 0; i < n ; i++) scanf("%d", vet + i);

	permuta(0,n-1, 0, vet);
	cout << cont << " Permutacoes" << endl;

	return 0;
}