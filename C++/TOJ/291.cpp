#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int times = 0, i = 0, l;
	bool in[55];
	char now;
	string stop;
	cin >> stop;
	for ( int j = 0 ; j < stop.size() ; j++ )
		in[j] = ( stop[j] == '1' );
	l = stop.size();
	now = 'A';
	while ( times < 10000 && i >= 0 && i < l ){
		times++;
		if ( now == 'A' ){
			if ( !in[i] ){
				i++;
				now = 'B';
			}
			else{
				in[i] = false;
				i += 2;
				now = 'D';
			}
		}
		else if ( now == 'B' ){
			if ( !in[i] ){
				in[i] = true;
				i--;
				now = 'D';
			}
			else{
				break;
			}
		}
		else if ( now == 'C' ){
			if ( !in[i] ){
				in[i] = true;
				i += 2;
				now = 'E';
			}
			else{
				in[i] = false;
				i -= 2;
				now = 'A';
			}
		}
		else if ( now == 'D' ){
			if ( !in[i] ){
				in[i] = true;
				i++;
				now = 'C';
			}
			else{
				i++;
				now = 'E';
			}
		}
		else if ( now == 'E' ){
			if ( !in[i] ){
				i++;
				now = 'A';
			}
			else{
				i--;
				now = 'C';
			}
		}
	}

	for ( i = 0 ; i < stop.size() ; i++ )
		cout << ( ( in[i] ) ? '1' : '0' );
	cout << '\n';
}