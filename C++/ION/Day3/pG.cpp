#include<bits/stdc++.h>
using namespace std;
bool adj[100005][100005];
bool visit[100005];
int ans;
void BFS(){
	// 建立一個queue。
	queue<int> q;
	// 一、把起點放入queue。
	q.push ( 1 );
	visit[1] = true;

	// 二、重複下述兩點，直到queue裡面沒有東西為止：
	while ( !q.empty() ){
		// 甲、從queue當中取出一點。
		int i = q.front();
		q.pop();
		ans++;

		// 乙、找出跟此點相鄰的點，並且尚未遍歷的點，
		//	 依照編號順序通通放入queue。
		for ( int j = 2 ; j < 100005 ; j++ )
			if ( adj[i][j] && !visit[j] ){
				q.push( j );
				visit[j] = true;
			}
	}
}
int main(){
	// ios::sync_with_stdio ( false );
	// cin.tie ( 0 );

	int n, stop;
	cin >> n;
	for ( int i = 1 ; i < n ; i++ ){
		cin >> stop;
		adj[stop][i] = true;
	}

	BFS();

	cout << ans << '\n';

}