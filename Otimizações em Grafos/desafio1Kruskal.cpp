#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int oo = 0x3f3f3f3f;
int premio[N];

struct edge
{
	int a,b,w;

	bool operator < (const edge &q) const
	{
		return (premio[a] + premio[b])/w;
	}
};

int n,m;
int a,b,v;
vector<edge>g;

int p[N]; 


int findset(int u)
{
	if(p[u] == u) return u;
	return p[u] = findset(p[u]);
}
int unionset(int a, int b)
{
	a = findset(a);
	b = findset(b);

	p[b] = a;
}

int main()
{
	scanf("%d%d",&n,&m);
	map<int, char> mp;
	int cont = 1;
	mp[1] = 'A';
	mp[2] = 'B';
	mp[3] = 'C';
	mp[4] = 'D';
	mp[5] = 'E';
	mp[6] = 'F';
	mp[7] = 'G';
	mp[8] = 'H';
	mp[9] = 'I';
	mp[10] = 'J';
	mp[11] = 'L';
	mp[12] = 'M';
	for(int i = 0 ; i < m ; i++)
	{
		scanf("%d%d%d",&a,&b,&v);
		edge x = {a,b,v};
		g.push_back(x);
	
	}
	for(int i = 1 ; i <= n ; i++) p[i] = i;
	sort(g.begin(),g.end());
	
	mst = 0;

	for(int i = 0 ; i < (int)g.size(); i++)
	{
		int a = g[i].a;
		int b = g[i].b;
		int w = g[i].w;
		if(findset(a) != findset(b))
		{
			unionset(a,b);
			mst += w;
		}
	}
	
	printf("Arvore geradora minima: %d\n",mst);



	return 0;
}