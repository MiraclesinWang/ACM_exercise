#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 2e5 + 10;
const int rsrv = 490;
struct classroom{
    int a, b;
}c[maxn];
int cnt[500][105], classmate[maxn];

void init(int n, int b, int bl)
{
    memset(cnt, 0, sizeof(cnt));
    for(int i= 1;i < b; i++){
        for(int j= i*bl; j < (i+1)*bl; j++) 
            cnt[i][c[j].a] += c[j].b;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.precision(2);
    int n, q;
    cin >> n >> q;
    for(int i= 0;i < n; i++) cin >> c[i].a;
    for(int i= 0;i < n; i++){
        cin >> c[i].b;
        classmate[i] = c[i].b;
        if(i) classmate[i] += classmate[i-1];
    }
    int b = sqrt(n), bl = n/b;

    while(q--){
        int tp, l, r;
        cin >> tp >> l >> r;
        l--, r--;
        int lb = l/bl, rb = r/bl;
        memset(cnt[rsrv], 0, sizeof(cnt[rsrv]));
        for(int i= bl+1; i < rb; i++) 
            for(int j= 1; j < 101; j++)
                cnt[rsrv][j] += cnt[i][j];
        for(int i=l; i< lb*bl; i++) cnt[rsrv][c[i].a] += c[i].b;
        for(int i= rb*bl+1;i < r+1; i++) cnt[rsrv][c[i].a] += c[i].b;

        if(tp==1){
            LL sm = 0;
            for(int i= 1; i< 101; i++) sm += cnt[rsrv][i]*i;
            cout << double(sm) / double(r-l+1);
        }
        else if(tp==2){
            int md = 1;
            for(int i= 2;i< 101; i++)
                if(cnt[rsrv][i] > cnt[rsrv][md]) md = i;
            cout << md;
        }
        else{
            int md = 0;
            for(int i= 1; i< 101; i++){
                if(cnt[rsrv][i] > 0){
                    md = i;
                    break;
                }
            }
            for(int i = 100; i >= md; i--){
                if(cnt[rsrv][i] > 0){
                    cout << i-md;
                    break;
                }
            }
        }
        if(q) cout << '\n';
    }
}
