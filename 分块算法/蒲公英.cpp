#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
const int maxn = 4e4 + 10;
const int rsrv = 60;
int a[maxn], a_all[maxn], cnt[65][maxn], mst[65][65][2];

void prepro(int b, int bl, int t)
{
	memset(cnt[0], 0, sizeof(cnt[0]));
	memset(cnt[rsrv], 0, sizeof(cnt[rsrv]));
	rep(i, 1, b){
		memcpy(cnt[i], cnt[i-1], sizeof(cnt[i]));
		rep(j, i*bl, (i+1)*bl) cnt[i][a[j]]++;
	}
	rep(i, 1, b){
		rep(j, i, b){
			int mx = -1, md;
			rep(k, 0, t){
				if(cnt[j][k]-cnt[i-1][k] > mx) mx = cnt[j][k]-cnt[i-1][k], md = k;
			}
			mst[i][j][0] = md, mst[i][j][1] = mx;
		}
	}
}

int query(int l, int r, int dex, int pre, int val)
{
	int md, mx = -1;
	rep(i, l, r+1){
		cnt[dex][a[i]]+=val;
		if(cnt[dex][a[i]] - cnt[pre][a[i]] > mx) mx = cnt[dex][a[i]] - cnt[pre][a[i]], md=a[i];
		else if(cnt[dex][a[i]] - cnt[pre][a[i]] == mx && a_all[md] > a_all[a[i]]) md = a[i];
	}
	return md;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m, x=0;
	cin >> n >> m;
	rep(i, 0, n) cin >> a[i], a_all[i] = a[i];
	sort(a_all, a_all +n);
	int t = unique(a_all, a_all +n) - a_all;
	rep(i, 0, n) a[i] = lower_bound(a_all, a_all +t, a[i]) - a_all;

	int b = pow(n, 1.0/3.0), bl = n/b;
	prepro(b, bl, t);

	while(m--){
		int l, r;
		cin >> l >> r;
		l = (l+x-1)%n, r = (r+x-1)%n;
		if(l > r) swap(l, r);
		int ld = l/bl, rd = r/bl;
		if(rd-ld < 2){
			x = a_all[query(l, r, rsrv, 0, 1)];
			query(l, r, rsrv, 0, -1);
		}
		else{
			int md = mst[ld+1][rd-1][0], mx = mst[ld+1][rd-1][1];
			int ql = query(l, bl*(ld+1)-1, rd-1, ld, 1);
			int qr = query(bl*rd, r, rd-1, ld, 1);
			if(cnt[rd-1][ql] - cnt[ld][ql] > mx) mx = cnt[rd-1][ql] - cnt[ld][ql], md = ql;
			else if(cnt[rd-1][ql] - cnt[ld][ql] == mx && a_all[md] > a_all[ql]) md=ql;
			if(cnt[rd-1][qr] - cnt[ld][qr] > mx) mx = cnt[rd-1][qr] - cnt[ld][qr], md = qr;
			else if(cnt[rd-1][qr] - cnt[ld][qr] == mx && a_all[md] > a_all[qr]) md = qr;
			x = a_all[md];
			query(l, bl*(ld+1)-1, rd-1, ld, -1);
			query(bl*rd, r, rd-1, ld, -1);
		}
		cout << x;
		if(m) cout << '\n';
	}

}