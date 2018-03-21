#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	long long a,b,n;
	while ( cin >> a >> b >> n ){
		cout << fixed << setprecision ( n ) << a / b << endl;
	}
	return 0;
}
