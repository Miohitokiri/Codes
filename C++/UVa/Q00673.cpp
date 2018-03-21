#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	cin >> n;
	string stop;
	bool ans;
	getline ( cin, stop );
	while ( n-- ){
		ans = true;
		getline ( cin, stop );
		if ( stop.size() & 1 ){
			cout << "No\n";
			continue;
		}
		stack < char, vector < char > > left;
		for ( auto i: stop ){
			if ( i == '(' || i == '[' )
				left.emplace ( i );
			else if ( i == ')' || i == ']' ){
				if ( left.empty() ){
					ans = false;
					break;
				}
				char top = left.top();
				left.pop();
				if ( ( top == '(' && i != ')' ) || ( top == '[' && i != ']' ) ){
					ans = false;
					break;
				}
			}
		}
		if ( left.size() != 0 )
			ans = false;

		cout << ( ans ? "Yes" : "No" ) << '\n';
	}
}