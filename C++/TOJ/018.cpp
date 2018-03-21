#include<string>
#include<iostream>
#include<stack>
#include<queue>
#define n in.size()
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	
	string in;
	const char data = 'a' - 'A';
	bool ans;
	int count;
	while ( getline ( cin, in ) ){
		stack < char > s;
		queue < char > q;
		ans = true, count = 0;
		for ( int i = 0 ; i < n ; i++ ){
			if ( in[i] >= 'A' && in[i] <= 'Z' ){
				s.push ( in[i] + data );
				q.push ( in[i] + data );
				count++;
			}
			else if ( in[i] >= 'a' && in[i] <= 'z' ){
				s.push ( in[i] );
				q.push ( in[i] );
				count++;
			}
		}
		
		for ( int i = 0 ; i < count ; i++ ){
			if ( s.top() != q.front() ){
				ans = false;
				break;
			}
			s.pop();
			q.pop();
		}
		cout << ( ( ans ) ? "SETUP! " : "" ) << in << '\n';
	}
}