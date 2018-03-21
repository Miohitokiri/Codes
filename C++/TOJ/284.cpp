#include<bits/stdc++.h>

using namespace std;

inline bool cmp ( int a, int b ){
	return a > b;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int type, x;
	vector < int > box;
	stack < int > s;
	queue < int > q;
	while ( cin >> type ){
		if ( !type )
			break;

		if ( type == 1 ){
			cin >> x;
			box.push_back ( x );
		}
		else if ( type == 2 ){
			cin >> x;
			if ( box.empty() )
				continue;

			int place = box.size();
			bool find = false;
			for ( int j = box.size() - 1 ; j >= 0 && !find ; j-- )
				if ( box[j] >= x ){
					place = j;
					find = true;
				}

			if ( find ){
				reverse ( box.begin() + place, box.end() );
				box.pop_back();
			}
		}
		else if ( type == 3 ){
			if ( !box.empty() )
				sort ( box.begin(), box.end() );
		}
		else if ( type == 4 ){
			if ( !box.empty() )
				sort ( box.begin(), box.end(), cmp );
		}
		else if ( type == 5 ){
			cin >> x;
			for ( auto i: box )
				if ( i > x )
					q.push ( i );

			if ( !box.empty() )
				box.clear();
			while ( !q.empty() ){
				box.push_back ( q.front() );
				q.pop();
			}
		}
	}
	if ( !box.empty() ){
		// reverse ( box.begin(), box.end() );
		cout << box[box.size() - 1];
		for ( int i = box.size() - 2 ; i >= 0 ; i-- )
			cout << ' ' << box[i];
	}

	cout << '\n';
}