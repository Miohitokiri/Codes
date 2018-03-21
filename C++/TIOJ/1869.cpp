#include<iostream>
using namespace std;
int main(){
	long long n;
	cin >> n;
	long long data[n][n];
	string a;
	for ( int i = 0 ; i < n ; i++ ){
		for ( int j = 0 ; j < n ; j++ ){
			data[i][j] = 0;
		}
	}
	while ( cin >> a ){
		if ( a != "EOF" || a != "eof" ){
			if ( a == "1" ){
				long long x,y,z;
				cin >> x >> y >> z;
				data[x - 1][y - 1] += z;
			}
			else if ( a == "2" ){
				long long x1,x2,y1,y2;
				cin >> x1 >> y1 >> x2 >> y2;
				long long ans = 0;
				for ( int i = x1 ; i < x2 ; i++ ){
					for ( int j = y1 ; j < y2 ; j++ ){
						ans += data[i][j];
					}
				}
				cout << ans << endl;
			}
		}
		else if ( a == "EOF" || a == "eof" ){
			break;
		}
	}
	return 0;
}
