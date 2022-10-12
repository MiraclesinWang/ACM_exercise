#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <assert.h>
#define IOS ios::sync_with_stdio(false)
using namespace std;
#define inf (0x3f3f3f3f)
typedef long long int LL;


#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <bitset>
const int maxn = 2e3 + 20;
int w[maxn];
int bea[maxn];
int fa[maxn];
int tofind(int x) {
    if (fa[x] == x) return x;
    else return fa[x] = tofind(fa[x]);
}
void tomerge(int x, int y) {
    x = tofind(x);
    y = tofind(y);
    fa[y] = x;
}
vector<int>a[maxn];
int dp[1000 + 20];
void work() {
    int n, m, tot;
    cin >> n >> m >> tot;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) cin >> bea[i];
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        tomerge(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        a[tofind(i)].push_back(i);
    }
    int tn = n;
    for (int i = 1; i <= n; ++i) {
        if (a[i].size() == 0) continue;
        int ww = 0, bb = 0;
        for (int k = 0; k < a[i].size(); ++k) {
            ww += w[a[i][k]];
            bb += bea[a[i][k]];
        }
        w[++tn] = ww;
        bea[tn] = bb;
        a[i].push_back(tn);
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i].size() == 0) continue;
        for (int j = tot; j >= 0; --j) {
            for (int k = 0; k < a[i].size(); ++k) {
                if (j >= w[a[i][k]]) {
                    dp[j] = max(dp[j], dp[j - w[a[i][k]]] + bea[a[i][k]]);
                }
            }
        }
//        int ww = 0, bbea = 0;
//        for (int k = 0; k < a[i].size(); ++k) {
//            ww += w[a[i][k]];
//            bbea += bea[a[i][k]];
//        }
//        for (int j = tot; j >= ww; --j) {
//            dp[j] = max(dp[j], dp[j - ww] + bbea);
//        }
    }
    cout << dp[tot] << endl;
}

int main() {
    work();
    return 0;
}
