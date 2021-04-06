#include <bits/stdc++.h>

using namespace std;

int n , m , add[1200004],t[1200004],l[300003],r[300003],x[300003];

void push(int v , int tl ,int tr)
{
    if(add[v] != 0)
	{
        if(tl != tr)
            add[v * 2] = add[v] ,
            add[v * 2 + 1] = add[v] ;
        t[v] = add[v] ;
        add[v] = 0 ;
    }
}
void update(int v,int tl, int tr , int l,int r ,int x)
{
    push(v,tl,tr) ;
    if(tl > r || tr < l || l > r){
        return ;
    }
    if(l <= tl && tr <= r)
	{
        add[v] = x ;
        push(v,tl,tr) ;
        return ;
    }
    int mid = (tl + tr) / 2 ;
    update(v * 2 , tl , mid , l ,r , x);
    update(v * 2 + 1, mid + 1, tr , l , r , x);
}
int get(int v , int tl ,int tr , int pos)
{
    push(v,tl,tr) ;
    if(tl == tr)
        return t[v ];
    else
	{
        int mid = (tl + tr) / 2 ;
        if(pos <= mid)
            get(v * 2, tl ,mid , pos) ;
        else
            get(v * 2 + 1, mid + 1, tr, pos) ;
    }
}
int main()
{
    cin >> n >> m ;
    for(int i = 1 ; i <= m ; i++) cin >> l[i] >> r[i] >> x[i] ;
    for(int i = m ; i >= 1 ; i--)
	{
            update(1,1,n,x[i]+1,r[i],x[i]) ;
            update(1,1,n,l[i],x[i]-1,x[i]) ;
    }
    for(int i = 1; i <= n ; i++)
        cout << get(1,1,n,i) << ' ' ;
}
