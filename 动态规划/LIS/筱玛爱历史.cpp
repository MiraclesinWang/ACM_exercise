#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
typedef long long LL;

const int maxn = 1e6 + 2000;
int a[maxn], n, pre[maxn];
int mt[maxn], md[maxn];

int Get_sequence()
{
	int m = 1;
	memset(mt, 0, sizeof(mt));
	mt[1] = a[1], md[1] = 1;
	
	rep(i, 2, n*(n+1)+1){
//		rep(j, 1, m+1) printf("%d ", mt[j]);
//		printf("\n");
		if(a[i] > mt[m]){
			mt[++m] = a[i], md[m] = i, pre[i] = md[m-1];
			if(m==n*2){
				stack <int> st;
				st.push(i);
				rep(j, 0, n*2-1) st.push(pre[st.top()]);
				printf("%d", st.top());
				st.pop();
				while(!st.empty()) {printf(" %d", st.top());st.pop();}
				return 2;
			}
		}
		else{
			int dex = lower_bound(mt+1, mt+m+1, a[i]) - mt;
			mt[dex] = a[i], md[dex] = i, pre[i] = md[dex-1];
		}
	}
}

int main()
{
	scanf("%d", &n);
	rep(i, 1, n*(n+1)+1) scanf("%d", &a[i]);
	if(Get_sequence()!=2){
		rep(i, 1, n+1) a[i] =-a[i];
		//Get_sequence();
		printf("IMPOSSIBLE\n");
	}
}


