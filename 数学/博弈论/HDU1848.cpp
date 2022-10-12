#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
int sg[1005], fb[1005], cnt;
bool vis[1005];

void init()
{
    cnt = 2;
    fb[1] = 1, fb[2] = 2;
    for(int i = 3; fb[i-1]+fb[i-2] <= 3000; i++, cnt++){
        fb[i] = fb[i-1] + fb[i-2];
    }
    sg[0] = 0;
    rep(i, 1, 1001){
        memset(vis, 0, sizeof(vis));
        for(int j = 1; i>=fb[j]; j++) vis[sg[i-fb[j]]] = true;
        for(int j = 0; ; j++){
            if(!vis[j]){
                sg[i] = j;
                break;
            }
        }
    }
}

int main()
{
    int n, m, p;
    init();
    while(cin >> n >> m >> p, m||n||p){
        cout << ((sg[n]^sg[m]^sg[p])?"Fibo\n":"Nacci\n");
    }
}