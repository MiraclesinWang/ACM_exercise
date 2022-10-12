#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
typedef long long LL;
#define INF 0x3f3f3f3f

vector <int> get_euler(int N)
{
    vector <int> euler(N);
    euler[1]=1;
    for(int i=2;i<N;i++) euler[i]=i;
    for(int i=2;i<N;i++){
        if(euler[i]==i){
            for(int j=i;j<N;j+=i)
                euler[j]=euler[j]/i*(i-1);
        }
    }
    return euler;
}


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    auto euler = get_euler(100);
    cout << euler[3];

}