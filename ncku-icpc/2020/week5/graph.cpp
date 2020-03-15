// 假設目前一共有 n 個節點、m 條邊

// 2D array
#include<bits/stdc++.h>
using namespace std;
#define maxN 100005
bool G[maxN][maxN];
int main(){
	int n, m, u, v;
	cin >> n >> m;
	while ( m-- ){
		cin >> u >> v;
		G[u][v] = G[v][u] = true;
	}
}

// vector
#include<bits/stdc++.h>
using namespace std;
#define maxN 100005
vector < int > edges[maxN];
int main(){
	int n, m, u, v;
	cin >> n >> m;
	while ( m-- ){
		cin >> u >> v;
		edges[u].push_back ( v );
		edges[v].push_back ( u );
	}
}

// 如果還有邊權重

// 2D array
#include<bits/stdc++.h>
using namespace std;
#define maxN 100005
int G[maxN][maxN];
int main(){
	int n, m, u, v, w;
	cin >> n >> m;
	while ( m-- ){
		cin >> u >> v >> w;
		G[u][v] = G[v][u] = w;
	}
}

// vector
#include<bits/stdc++.h>
using namespace std;
vector < pair < int, int > > edges[maxN];
// first -> 點編號, second -> 邊權重
int main(){
	int n, m, u, v, w;
	cin >> n >> m;
	while ( m-- ){
		cin >> u >> v >> w;
		edges[u].push_back ( make_pair ( v, w ) );
		edges[v].push_back ( make_pair ( u, w ) );
	}
}