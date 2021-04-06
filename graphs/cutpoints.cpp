#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std ;

vector <int> g[20001] ; set<int> ans ;
bool used[20001] ;
int tin[20001] , fup[20001] , timer ;

void dfs(int v, int p = -1)
{
	used[v] = 1 ;
	tin[v]=fup[v]=timer ,++timer ;
	int children = 0 ;
	for(int i = 0 ; i < g[v].size() ; ++i)
	{
		int u = g[v][i] ;
		if(u==p)
		continue ;
		if(used[u])
			fup[v]=min(fup[v],tin[u]) ;
		else
		{
			dfs(u,v) ;
			fup[v] = min(fup[v],fup[u]) ;
			if(tin[v]<=fup[u]&&p!=-1)
			{
				ans.insert(v) ;
			}
			++children ;
		}
	}
	if(children>1&&p==-1)
	{
		ans.insert(v) ;
	}
}

int main()
{
	freopen("points.in","r",stdin) ;
	freopen("points.out","w",stdout) ;
	int n , m ;
	cin >> n >> m ;
	for(int i = 0 ; i < m ; ++i)
	{
		int l , r ;
		cin >> l >> r ;
		g[l].push_back(r) ;
		g[r].push_back(l) ;
	}
	for(int i = 1 ; i <= n ; ++i)
		if(!used[i]) dfs(i) ;
	cout << ans.size() << '\n' ;
	for (std::set<int>::iterator i= ans.begin() ; i != ans.end() ; ++i)
	{
   		cout << (*i) << ' ' ;
	}
}
