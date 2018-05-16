#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define pb push_back

int main(){
	long long n, in, ans = 0, a, b;
	priority_queue < int, vector < int >, greater < int > > pq;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> in;
		pq.push ( in );
	}

	while ( pq.size() != 1 ){
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		ans += a + b;
		pq.push ( a + b );
	}
	// ans += pq.top();

	cout << ans << '\n';
}