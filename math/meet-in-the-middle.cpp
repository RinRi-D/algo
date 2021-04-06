#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int) 3e5 + 1;

int n, k;
ll ans;
int a[maxn], p, u[maxn];
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    p = n / 2;
    for(int i = 0; i < (1 << p); i++){
        ll res = 0;
        for(int j = 0; j < p; j++){
            if((i >> j) & 1){
                res += a[j];
            }
        }
        u[i] = res % k;
        ans = max(ans, res % k);
    }
    sort(u, u + (1 << p));
    n -= p;
    for(int i = 0; i < (1 << n); i++){
        ll res = 0;
        for(int j = 0; j < n; j++){
            if((i >> j) & 1){
                res += a[j + p];
            }
        }
        res %= k;
        ans = max(ans, res);
        int l = 0, r = (1 << p) - 1;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(u[mid] + res >= k){
                r = mid;
            }
            else {
                l = mid;
            }
        }
        int p1 = 0;
        if(u[l] + res >= k){
            p1 = l;
        }
        else {
            p1 = r;
        }
        ans = max(ans, (u[(1 << p) - 1] + res) % k);
        ans = max(ans, (u[p1 - 1] + res) % k);
    }
    cout << ans;
}
