#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, type;
	string str, you, last;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> str >> type;
		if ( type == 2 )
			you = "You";
		else if ( type == 1 )
			last = str;
	}

	if ( you == "" && last == "" )
		cout << n << " people like this.\n";
	else{
		if ( you != "" )
			n--;
		if ( last != "" )
			n--;
		if ( !n ){
			if ( you != "" ){
				cout << you;
				if ( last != "" )
					cout << " and " << last;
			}
			else if ( last != "" )
				cout << last;
			cout << " like this.\n";
		}
		else{
			if ( you != "" ){
				cout << you;
				if ( last != "" )
					cout << ", " << last;
			}
			else if ( last != "" )
				cout << last;
			cout << " and " << n << " others like this.";
		}
	}
}