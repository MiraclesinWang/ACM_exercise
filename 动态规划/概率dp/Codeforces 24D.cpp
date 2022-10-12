#include <cstdio>
#include <cstring>
using namespace std;

double b[1010][1010], c[1010], dp[1010][1010];

int main()
{
	int n, m, x, y;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for(int i = 1; i <= m; i++) dp[n][i] = 0;
	if(x == n) {printf("0.00000\n");return 0;}
	if(m == 1) {printf("%d.00000\n", 2*(n-x));return 0;}
	for(int i = n-1; i >= x; i--){
		for(int j = 1; j <= m; j++) c[j] = dp[i+1][j]+4.0;
		for(int j = 2; j < m; j++) b[j][j] = 3.0;
		b[1][1] = b[m][m] = 2.0, c[1] -= 1.0, c[m] -= 1.0;
		for(int j = 2; j <=m; j++) b[j][j-1] = b[j-1][j] = -1.0;
		for(int j = 1; j < m; j++){
			c[j+1] -= b[j+1][j]/b[j][j]*c[j];
			b[j+1][j+1] -= b[j+1][j]/b[j][j]*b[j][j+1];
		}
		dp[i][m] = c[m]/b[m][m];
		for(int j = m-1; j; j--)
			dp[i][j] = (c[j]-b[j][j+1]*dp[i][j+1])/b[j][j];
	}
	printf("%.5f\n", dp[x][y]);
}
