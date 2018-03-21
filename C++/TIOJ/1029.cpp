#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	int n, a = 0, b = 0, stop, i = 0;
	cin >> n;
	queue < int > q;
	stack < int > s;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> stop;
		q.push ( stop );
		s.push ( stop );
	}
	bool ss;
	while ( i < n ){
		i++;
		ss = ( q.front() < s.top() );
		stop = max ( q.front(), s.top() );
		( i % 2 == 1 ) ? a += stop : b += stop;
		( ss ) ? q.pop() : s.pop();
	}
	cout << a << ' ' << b << '\n';
}