#include<iostream>
#include<algorithm>
using namespace std;
struct ruby{
	long long red;
	long long blue;
};
int main(){
	long long m;
	while ( cin >> m ){
		ruby data[m],max;
		long long ans = 0;
		max.red = 0;
		max.blue = 0;
		while ( data[m - 1].red != 0 && data[m - 1].blue != 0 ){
			for ( int i = 0 ; i < m ; i++ ){
				cin >> data[i].red >> data[i].blue;
				if ( data[i].red > max.red ){
					max.red = data[i].red;
				}
				if ( data[i].blue > max.blue ){
					max.blue = data[i].red;
				}
			}
			for ( int i = 0 ; i < m ; i++ ){
				if ( max.red == data[i].red ){
					data[i].red = 0;
				}
				if ( max.blue == data[i].blue){
					data[i].blue = 0;
				}
			}
			ans += max.red * max.blue;
		}
		sort ( data + m,data );
		sort ( data + m,data );
		cout << ans << endl;
	}
	return 0;
}