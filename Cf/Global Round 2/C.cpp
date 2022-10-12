#include<cstdio>
#include<iostream>
#define maxn 500+10
using namespace std;
bool t_1[maxn][maxn];
bool t_2[maxn][maxn];
bool t_3[maxn][maxn];
int n,m;
bool jdg(int x,int y){
    for (int j=y+1;j<=m;++j){
        if (!t_3[x][j]) continue;
        for (int i=x+1;i<=n;++i){
            if (!t_3[i][y]) {continue;}
            if (t_3[i][j]){
                t_3[x][y]=t_3[x][j]=t_3[i][y]=t_3[i][j]=0;
                return true;
            }
        }
    }
    if (x<n && y<m){
        t_3[x][y]=!t_3[x][y];
        t_3[x][y+1]=!t_3[x][y+1];
        t_3[x+1][y]=!t_3[x+1][y];
        t_3[x+1][y+1]=!t_3[x+1][y+1];
        return true;
    }
    else return false;
}
int main()
{
	bool f;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&t_1[i][j]);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;j++)
            scanf("%d",&t_2[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;++j)
            t_3[i][j]=t_1[i][j]^t_2[i][j];
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (t_3[i][j]){
                f=jdg(i,j);
                if (!f){
                    printf("No\n");
                    return 0;
                }
            }
        }
    }
    cout<<"Yes\n"<<endl;
}

