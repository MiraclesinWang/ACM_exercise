#include <bits/stdc++.h>
using namespace std;

#define MEM(A, b) memset(A, b, sizeof(A))
#define rep(i, x, y) for(int i = x; i < y; i++)

const int maxm = 1e2 + 10;
const int maxn = 1e4 + 10;
int vis[maxm];
int n, m, A[maxn];
stack <int> st;

int main()
{
	cin >> n >> m;
	MEM(vis, -1);
	rep(i, 0, n) cin >> A[i];
	sort(A, A+n);
	vis[0] = -2;
	rep(i, 0, n){
		for(int j = m-1; ~j; j--){
			if(~vis[j] && A[i]+j <= m && !~vis[A[i]+j])
				vis[A[i]+j] = j, printf("%d %d\n", A[i], j);
		}
	}
	if(!vis[m]) printf("No Solution");
	else{
		while(!st.empty()) st.pop();
		st.push(m);
		for(int i = m; i != -2; st.push(vis[i]), i=vis[i]) 1;
		int pre = st.top(); st.pop();
		while(!st.empty()){
			cout << st.top() - pre;
			pre = st.top();
			st.pop();
			if(!st.empty()) cout << " ";
		}
	}
}
