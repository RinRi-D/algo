#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

#define pb push_back
#define ll long long
#define ub upper_bound
#define lb lower_bound
#define sc(x) scanf("%I64d",&x)
#define pr(x) printf("%I64d\n",x)

using namespace std ;

const int MAXN = 1e9+1 ;
const int N = 1e6+1 ;
int n , m , k , x , y , z ;
int a[N] , d[30][N] , U[N] ;

struct node
{
    int x, sz, y ;
    node *l, *r ;
    node (int X = 0)
    {
        x = X ;
        sz = 1 ;
        y = rand () ;
        l = r = NULL ;
    }
} *t ;

typedef node* pnode ;

int GetSz (pnode t)
{
    if (!t)
        return 0 ;
   return t -> sz ;
}

int GetKey(pnode t)
{
    if (!t)
        return 0 ;
    return GetSz (t -> l) + 1 ;
}

void upd (pnode t)
{
    if (!t)
        return ;
    t -> sz = GetSz (t -> l) + GetSz (t -> r) + 1 ;
}

pnode Merge (pnode a , pnode b)
{
    if (!a)
        return b ;
    if (!b)
        return a ;
    if (a -> y > b -> y)
    {
        a -> r = Merge ( a -> r , b );
        upd (a) ;
        return a ;
    }
    else
    {
        b -> l = Merge ( a , b -> l ) ;
        upd (b) ;
        return b ;
    }
}

void Split (pnode t , pnode &a , pnode &b , int x)
{
    if (!t)
        return void (a = b = NULL);
    int key = GetKey (t) ;
    if (key <= x)
    {
        Split ( t -> r , t -> r , b , x - key ) ;
        a = t ;
    }
    else
    {
        Split ( t -> l , a , t -> l , x ) ;
        b = t ;
    }
    upd (a) ;
    upd (b) ;
}
 
void add (int x)
{
    pnode L , R , M ;
    L = R = M = NULL ;
    Split ( t , L , R , x ) ;
    Split ( L , L , M , x - 1 ) ;
    M = Merge ( new node ( x ) , M ) ;
    L = Merge ( L , M ) ;
    t = Merge ( L , R ) ;
}

int main()
{
	
}
