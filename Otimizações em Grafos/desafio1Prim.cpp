#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int oo = 0x3f3f3f3f;
vector<pair<int,int> >g[N];
int n,m;
int a,b,v;
int premio[N];
int visitado[N]; 
vector<pair<int,int> >arestas;
int prim(int x)
{
	priority_queue<pair<int,int> >pq;

	int i;
	if(x == 0)
		i = 1;
	else
	{
		i = x;
		n = x;
	}
	int ans = oo;
	
	for(; i <= n ; i++)
	{
		
		memset(visitado, 0, sizeof visitado);
		pq.push(make_pair(0,i));
		int premioTotal = premio[i];
		visitado[i] = 1;
		int mst = 0;
		vector<pair<int, int> > edges;
		while(!pq.empty())
		{

			int u = pq.top().second;
			
			pq.pop();
			if(premioTotal >= 50) continue;
			for(int j = 0 ; j <(int)g[u].size(); j++)
			{
				int v = g[u][j].first;
				int w = g[u][j].second;

				if(!visitado[v])
				{
					pq.push(make_pair((premio[v]/w), v));
					edges.push_back(make_pair(u,v));
					premioTotal += premio[v];
					mst += w;
					visitado[v] = 1;
				}
			}	
		}
		if(ans > mst)
		{
			ans =mst;
			arestas = edges;
		}
		
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m);

	for(int i = 0 ; i < m ; i++)
	{
		scanf("%d%d%d",&a,&b,&v);
		g[a].push_back(make_pair(b,v));
		g[b].push_back(make_pair(a,v));
	
	}
	int maior,m = 0;

	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d", &premio[i]);
		if(premio[i] > m)
		{
			m = premio[i];
			maior = i;
		}
	
	} 

	
	int op;
	scanf("%d",&op);
	
	if(op == 1) // versão que começa sempre do vértice de maior premio O(nlogn)
		printf("Valor da arvore: %d\n", prim(maior));
	else // versão que tenta iniciar de cada vértice O(n^2logn)
		printf("Valor da arvore: %d\n", prim(0));

	printf("Arestas da melhor solucao:\n");
	for(int i = 0 ; i < arestas.size(); i++)
	{
		printf("%d - %d\n", arestas[i].first, arestas[i].second);
	}

	return 0;
}