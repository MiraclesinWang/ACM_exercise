#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 600
/*˼·��ǿ�����鼯��״̬���£�+dp+������·��*/
int fa[maxn+10];
int rela[maxn+10];     //1��ʾ��ͬһ����,-1��ʾ���� 
int same[maxn+10],dif[maxn+10];        //����ͳ�� 
int f_same[maxn+10],f_dif[maxn+10],f_dex[maxn+10];     //����ͳ�Ƶ����и��ڵ��������������࣬����ͬ�� 
int dp[maxn+5][maxn+5];     //��¼���ǵ���i���ڵ��ܴճ�j�������� 
bool god[maxn+5];          //god��¼���ڵ��Ƿ����� 
vector <int> res;
int frt(int i)            //׷�ݸ��ڵ㲢����·�������е�����ڵ��ϵ��ͬʱѹ�� 
{
	if(fa[i]==i) return i;
	else{
		int temp=frt(fa[i]);
		rela[i]=rela[i]*rela[fa[i]],fa[i]=temp;
		return fa[i];
	}
}
void connect(int p1,int p2,int type)          //typeΪ-1��ʾ���죬�����ʾ1 
{
	int rt1=frt(p1),rt2=frt(p2);
	fa[rt2]=rt1,rela[rt2]=rela[p1]*rela[p2]*type;
}
int main()
{
	int n,p1,p2,x,y,dex,cpy,p;
	char s[5];
	while(scanf("%d%d%d",&n,&p1,&p2),p1||p2||n){
		res.clear();
		memset(same,0,sizeof(same));
		memset(dif,0,sizeof(dif));
		dex=0,p=p1;              //p�ں���p1�ı������ 
		for(int i=1;i<=p1+p2;i++) rela[i]=1,fa[i]=i;
		for(int i=1;i<=p1+p2;i++)
			for(int j=1;j<=p1;j++) dp[i][j]=0;
		for(int i=0;i<n;i++){
			scanf("%d%d %s",&x,&y,&s);
			if(x!=y) connect(x,y,(s[0]=='n'?-1:1));
		}
		if(p1==p2) {printf("no\n");continue;}
		for(int i=1;i<=p1+p2;i++) frt(i);        //ǿ�����鼯�������нڵ����ӵ����Եĸ��ڵ㣬�γɾջ�ͼ 
		for(int i=1;i<=p1+p2;i++){
			if(fa[i]==i) same[i]=1;
			else{
				if(rela[i]==1) same[fa[i]]++;
				else dif[fa[i]]++;
			}
		}
		for(int i=1;i<=p1+p2;i++)
			if(fa[i]==i) f_same[dex]=same[i],f_dif[dex]=dif[i],f_dex[dex]=i,dex++;     //��ɴ��׼������ 
		dp[0][f_same[0]]=1,dp[0][f_dif[0]]=1;
		for(int i=1;i<dex;i++){
			for(int j=p1;j>=0;j--){
				if(j-f_same[i]>=0) dp[i][j]+=dp[i-1][j-f_same[i]];
				if(j-f_dif[i]>=0) dp[i][j]+=dp[i-1][j-f_dif[i]];			
			}
		}
		if(dp[dex-1][p1]!=1) printf("no\n");
		else{
			cpy=dex,dex--;
			while(dex>0){
				if(dp[dex-1][p1-f_same[dex]]==1) god[dex]=true,p1-=f_same[dex],dex--;
				else god[dex]=false,p1-=f_dif[dex],dex--;
			}
			if(p1==f_same[0]) god[0]=true;
			else god[0]=false;
			for(int i=1;i<=p+p2;i++) printf("%d ",fa[i]);
			printf("\n");
			for(int i=1;i<=p+p2;i++) printf("%d ",rela[i]);
			printf("\n");
			for(int i=0;i<cpy;i++){
				if(god[i]) res.push_back(f_dex[i]);
				else rela[f_dex[i]]=-1;
			}
			for(int i=1;i<=p+p2;i++)
				if(i!=fa[i] && rela[i]*rela[fa[i]]>0) res.push_back(i);
			sort(res.begin(),res.end());
			for(int i=0;i<res.size();i++) printf("%d\n",res[i]);
			printf("end\n");
		}
	}
}
