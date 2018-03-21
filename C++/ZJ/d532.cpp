#include<iostream>
using namespace std;
long long year ( long long a,long long b ){
	long long ans,ad = a / 400 - b / 400,da = a / 100 - b / 100;
	ans =  ( b - ( b % 4 ) - a + ( a % 4 ) / 4 ) / 4 + 1;
	ans += ad;
	ans -= da;
	if ( ans == 1 ){
		return 0;
	}
	else{
		return ans;
	}
}
int main(){
	long long a,b;
	cin >> a >> b;
	if ( b > a ){
		cout << year ( a , b ) << endl;
	}
	else{
		cout << year ( b , a ) << endl;
	}
	return 0;
}
