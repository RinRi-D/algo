#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std ;
const long long MAXN = 1e9+1 ;
const int N = (int)(2e4) + 256 ;
int n , m , timer , used[N] , lim ;
struct edge{
	int v , u , c , f ;
};
vector <edge> e ;
vector <int> g[N] ;
inline void addEdge(int v , int u , int c )
{
	e.pb({v,u,c,0}) ;
	g[v].pb(e.size()-1) ;
	e.pb({u,v,0,0}) ;
	g[u].pb(e.size()-1) ;
}
int dfs ( int v , int t , int pushed = MAXN , int p = -1 )
{
	if (used[v] == timer || pushed < lim) return 0;
	if (!pushed || v == t) return pushed;
	
	used[v] = timer ;
	for ( int i = 0 ; i < g[v].size() ; ++i )
	{
		int id = g[v][i] ;
		int to = e[id].u , f = e[id].f , c = e[id].c ;
		if ( p == to || f == c ) continue ;
		int nxt = dfs ( to , t , min ( pushed , c - f) , v);
		if ( nxt > 0 )
		{
			e[id].f += nxt ;
			e[id^1].f -= nxt ;
			return nxt ;
		}
	}
	return 0 ;
}
inline int fordf(int s,int t)
{
	int res = 0 ;
	lim = 1 << 30 ;
	while ( lim > 0 )
	{
		++timer ;
		int pushed = dfs(s,t) ;
		if ( !pushed )
		{
			lim >>= 1 ;
			continue ;
		}
		res += pushed ;
	}
	return res ;
}
main()
{
	freopen("flow.in","r",stdin) ;
	freopen("flow.out","w",stdout) ;
	cin >> n >> m ;
	for ( int i = 0 ; i < m ; ++i )
	{
		int x , y , c ;
		cin >> x >> y >> c ;
		addEdge(x,y,c) ;
	}
	cout << fordf(1,n) << endl ;
	return 0 ;
}
