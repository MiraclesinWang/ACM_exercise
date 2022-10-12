#include<iostream>
#include<cmath>
using namespace std;
int n, m, root, a, b, total;
#define maxn 100005
int dfn[maxn], low[maxn], flag[maxn], head[maxn*2];
struct node{
    int to;
    int next;
}edge[200010];
 
int cnt = 1;
void add(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void tarjan(int u, int father) {
    int child = 0;//child������¼���������е�ǰ����Ķ��ӵĸ���
    dfn[u] = low[u] = ++total;//ʱ���
    for (int i = head[u]; i != 0; i = edge[i].next) {//ǰ���Ǳ����ö�������б�
        int v = edge[i].to;//�ö������ӵĶ���
        if (!dfn[v]) {//���ʱ���Ϊ0˵��û�з��ʹ�
            child++;
            tarjan(v, u);//������������
            low[u] = min(low[u], low[v]);//���µ�ǰʱ���
            //  �����ǰ�ڵ��Ǹ��ڵ㲢�Ҷ��Ӹ������ڵ���2���������һ��ڵ㣬Ϊ���
            if (u == root && child >= 2) {
                flag[u] = 1;
            //��Ϊ����㵫������ڶ��������Ľڵ�
            } else if (u != root && low[v] >= dfn[u]) {
                flag[u] = 1;
            }
            //������㱻���ʹ����Ҳ��Ǹýڵ�ĸ��ף�˵����ʱ��vΪu�����ȣ������Ҫ�������綥���ʱ���
        } else if (v != father) {
            low[u] = min(low[u], dfn[v]);
        }
    }
}
 
 
int main() {
	int res=0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    root = 1;
    tarjan(1, root);
    for (int i = 1; i <= n; i++)
        if(flag[i]) res++;
    printf("%d\n",res);
    return 0;
}
