#include<bits/stdc++.h>

using namespace std;

int main(){
	int name = 0;

	string firends[5] = { "Danil", "Olya", "Slava", "Ann", "Nikita" }, in;
	cin >> in;

	for ( int s = 0 ; s < 5 ; s++ ){
		string n = firends[s];
		if ( in.size() < n.size() )
			continue;
		for ( int i = 0 ; i < in.size() - n.size() + 1 ; i++ )
			if ( n[0] == in[i] ){
				bool test = true;
				for ( int j = 0 ; j < n.size() ; j++ ){
					if ( n[j] == in[i + j] )
						continue;

					test = false;
				}

				if ( test )
					name++;
			}
	}

	if ( name == 1 )
		cout << "YES";
	else
		cout << "NO";
	cout << '\n';
}