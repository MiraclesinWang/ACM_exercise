#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;

const int maxn = 1e4 + 10;

map <string, int> ttl, aut, key, pub, yr;
vector <string> v_t[maxn], v_a[maxn], v_k[maxn], v_p[maxn], v_y[maxn];

int main()
{
	int n, m;
	string id, title, author, word, publisher, year, sentence;
	cin >> n;
	rep(i, 0, n){
		cin >> id;
		getchar();
		getline(cin, title);
		if(ttl.find(title) == ttl.end()) ttl[title] = ttl.size();
		v_t[ttl[title]].push_back(id);
		
		getline(cin, author);
		if(aut.find(author) == aut.end()) aut[author] = aut.size();
		v_a[aut[author]].push_back(id);
		
		getline(cin, sentence);
		stringstream ss;
		ss.str(sentence);
		while(true){
			ss >> word;
			if(ss.fail()) break;
			if(key.find(word) == key.end()) key[word] = key.size();
			v_k[key[word]].push_back(id);
			//cout << word << "\n";
		}
		
		getline(cin, publisher);
		if(pub.find(publisher) == pub.end()) pub[publisher] = pub.size();
		v_p[pub[publisher]].push_back(id);
		
		cin >> year;
		if(yr.find(year) == yr.end()) yr[year] = yr.size();
		v_y[yr[year]].push_back(id);
		
	}
	cin >> m;
	getchar();
	rep(i, 0, m){
		getline(cin, id);
		cout << id << "\n";
		int cnt = 0;
		char mode = id[0];
		id = id.substr(3, id.length()-3);
		if(mode == '1'){
			int dex = ttl[id];
			sort(v_t[dex].begin(), v_t[dex].end());
			if(!v_t[dex].size()){
				cout << "Not Found";
				if(i<m-1) cout << "\n";
			}
			rep(j, 0, v_t[dex].size()){
				cout <<v_t[dex][j];
				if(i < m-1 || j < v_t[dex].size()-1) cout << "\n";
			}
		}
		else if(mode == '2'){
			int dex = aut[id];
			sort(v_a[dex].begin(), v_a[dex].end());
			if(!v_a[dex].size()){
				cout << "Not Found";
				if(i<m-1) cout << "\n";
			}
			rep(j, 0, v_a[dex].size()){
				cout <<v_a[dex][j];
				if(i < m-1 || j < v_a[dex].size()-1) cout << "\n";
			}
		}
		else if(mode == '3'){
			int dex = key[id];
			sort(v_k[dex].begin(), v_k[dex].end());
			if(!v_k[dex].size()){
				cout << "Not Found";
				if(i<m-1) cout << "\n";
			}
			rep(j, 0, v_k[dex].size()){
				cout <<v_k[dex][j];
				if(i < m-1 || j < v_k[dex].size()-1) cout << "\n";
			}
		}
		else if(mode == '4'){
			int dex = pub[id];
			sort(v_p[dex].begin(), v_p[dex].end());
			if(!v_p[dex].size()){
				cout << "Not Found";
				if(i<m-1) cout << "\n";
			}
			rep(j, 0, v_p[dex].size()){
				cout <<v_p[dex][j];
				if(i < m-1 || j < v_p[dex].size()-1) cout << "\n";
			}
		}
		else if(mode == '5'){
			int dex = yr[id];
			sort(v_y[dex].begin(), v_y[dex].end());
			if(!v_y[dex].size()){
				cout << "Not Found";
				if(i<m-1) cout << "\n";
			}
			rep(j, 0, v_y[dex].size()){
				cout <<v_y[dex][j];
				if(i < m-1 || j < v_y[dex].size()-1) cout << "\n";
			}
		}
	}
	return 0;
}

