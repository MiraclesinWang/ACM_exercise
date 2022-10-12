#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e4 + 10;
#define rep(i, x, y) for(int i = x; i < y; i++)
#define frt(x) return (x==fa[x])?x:(fa[x]=frt(fa[x]))
#define lowbit(x) x&(-x)

queue<int> q;
int n, m, deg[maxn], s[maxn];
struct Edge{
	int u, v;
	bool operator < (Edge &oth) {return u < oth.u;}
} E[maxn];
bitset<maxn> cnct[maxn];
map <int, int> mp;

void init()
{
	memset(cnct, 0, sizeof(cnct));
	memset(deg, 0, sizeof(deg));
	while(!q.empty()) q.pop();
}


int main()
{
	init();
	scanf("%d%d", &n, &m);
	rep(i, 0, m){
		int u, v;
		scanf("%d%d", &u, &v);
		E[i].u = u, E[i].v = v;
		deg[v]++;
	}
	sort(E, E+m);   //�ѱ߰���u�Ĵ�С���� 
	for(int i = m-1; i >-1; i--) mp[E[i].u] = i;
	//��¼ÿ��u0��Ӧ����E�е���ʼλ��,��E[i]-E[j]��һ�ε�uȫ��u0���� mp[u]=i 
	rep(i, 1, n+1) if(!deg[i]) q.push(i);   //�������� 
	int dex = n-1;
	while(!q.empty()){
		s[dex--] = q.front();
		int d = mp[q.front()];
		while(d < m & E[d].u == q.front()){
			if(!(--deg[E[d].v])) q.push(E[d].v);
			d++;
		}
		q.pop();
	}    //���ⶼ�� 
	rep(i, 0, n){
		int u = s[i];     //���������˳����� 
		cnct[u][u] = true;   //�Լ����Ե��Լ� 
		if(mp.find(u) != mp.end()){   //��Щ��û�г��ȣ��ų� 
			int d = mp[u];
			while(d < m & E[d].u == u)
				cnct[u] |= cnct[E[d].v], d++;   //ÿһ���Լ�ָ����ܵ��Ľڵ㣬�Լ�һ��Ҳ���ܵ� 
		}
	}
	rep(i, 1, n+1){
		int res = 0;
		rep(j, 0, n+1) res += cnct[i][j];
		printf("%d\n", res);
	}
}


