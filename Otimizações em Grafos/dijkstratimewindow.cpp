#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;

int n,m;
vector<vector<pair<int,int> > >g;
int a,b,c;
 int ori, end;

int pai[100005];
int L[100005];
int R[100005];

void backtracking(int u)
{
    if(u == pai[u])
        return;

    backtracking(pai[u]);
    printf( "- > %d", u);

}

int dijkstra()
{

    int rotulos[n+1];
    memset(rotulos, inf, sizeof rotulos);

    priority_queue<pair<int,int>,  vector<pair<int,int> > , greater<pair<int,int> > >pq;

    rotulos[ori] = 0;

    pq.push(make_pair(0,ori));
    
    pai[ori] = ori;
    while(!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        
        if(rotulos[u] != w) continue;

        for(int i = 0 ; i < (int)g[u].size(); i++)
        {
            int v = g[u][i].first;
            int ww = g[u][i].second;
            if((rotulos[u] + ww) > R[v]) continue;

            if(rotulos[v] > max(L[v], (rotulos[u] + ww)))
            {
                rotulos[v] = max(L[v], rotulos[u] + ww);
                pq.push(make_pair(rotulos[v], v));
                pai[v] = u;
            }
        }
    }
    for(int i = 1 ; i <= n ; i++) printf("%d\n", rotulos[i]);
    return rotulos[end];

}

int main()
{
    cin >> n >> m;

    g.assign(n+1, vector<pair<int,int> >());

    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b,c));
        //g[b].push_back(make_pair(a,c)); descomentar caso o grafo não seja orientado
    }
    cin >> ori >> end;
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d%d",&L[i], &R[i]);
    }

    printf("Valor do menor caminho : %d\n", dijkstra());

    printf("Caminho:\n");
    printf("%d",ori);
    backtracking(end);

}