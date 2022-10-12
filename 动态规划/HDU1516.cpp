#include <bits/stdc++.h>
using namespace std;

const int maxn = 85*2;
char src[maxn], tgt[maxn];
int dp[maxn][maxn], ddp[maxn][maxn];
struct ojt{
	int i;
	char j;
	string ope;
} tmp;
stack<ojt> s;

void solve()
{
	scanf("%s", tgt);
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= strlen(src); i++)
		for(int j = 1; j <= strlen(tgt); j++){
			dp[i][j] = dp[i-1][j]+1, ddp[i][j] = -1;  //É¾³ý 
			if(src[i-1] == tgt[j-1] && dp[i-1][j-1] < dp[i][j]) dp[i][j] = dp[i-1][j-1], ddp[i][j] = 0;   //ÎÞ²Ù×÷ 
			if(dp[i-1][j-1]+1 < dp[i][j]) dp[i][j] = dp[i-1][j-1]+1, ddp[i][j] = 2;    //Ìæ»» 
			if(dp[i][j-1]+1 < dp[i][j]) dp[i][j] = dp[i][j-1]+1, ddp[i][j] = 1;     //²åÈë 
		}
	printf("%d\n", dp[strlen(src)][strlen(tgt)]);
	
	int a = strlen(src), b = strlen(tgt), cnt = 1, bias = 0;
	while(a && b){
		if(ddp[a][b] == 1) tmp.ope = "Insert", tmp.i = a, tmp.j = tgt[b], b-= 1;
		else if(ddp[a][b] == 2) tmp.ope = "Replace", tmp.i= a, tmp.j = tgt[b], a-=1, b-=1;
		else if(ddp[a][b] == -1) tmp.ope = "Delete", tmp.i = a, a-=1;
		else a-=1, b-=1;
		s.push(tmp);
	}
	
	while(!s.empty()){
		tmp = s.top(), s.pop();
		printf("%d\n", cnt++);
		cout << tmp.ope << endl;
		printf("%d\n", tmp.i);
		cout <<cnt++ << ' ' <<tmp.ope << ' ' << tmp.i+bias;
		if (tmp.ope[0] == 'I' || tmp.ope[0] == 'R') printf(",%c", tmp.j);
		if (tmp.ope[0] == 'I') bias++;
		bias -= tmp.ope == "Delete";
		printf("\n");
	}
		
	printf("%s, %s, %d, %d\n", src, tgt, strlen(src), strlen(tgt)); 
}

int main()
{
	while(scanf("%s", src) != EOF)
		printf("hello, world\n");
}
