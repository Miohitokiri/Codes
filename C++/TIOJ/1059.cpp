#include<iostream>
#include<cmath>
using namespace std;
void out ( long long t,long long s,long long tos ){//tos == total of seet
	long long tom = 0,cd = s * t * 0.3;//tom == total of money
	if ( tos <= t * 0.2 )
		tom += tos * 0.7;
	else if ( tos > t * 0.2 && tos <= t * 0.4 ){
		t *= 0.2;
		tom += t * 0.7;
		tos -= t;
		tom += tos * 0.8;
	}
	else if ( tom > t * 0.4 && tos <= t *0.6 ){
		t *= 0.2;
		tom += t * 0.7;
		tom += t * 0.8;
		t *= 2;
		tos -= t;
		tom += tos * 0.9;
	}
	else{
		t *= 0.2;
		tom += t * 0.7;
		tom += t * 0.8;
		tom += t * 0.9;
		t *= 3;
		tos -= t;
		tom += tos;
	}
	tom *= s;
	tom -= cd;
	cout << round ( tom ) << endl;
}
int main(){
	long long s,t,n;
	while ( cin >> s >> t >> n ){
		long long total = 0;
		for ( int i = 0 ; i < n ; i++ ){
			long long stop;
			cin >> stop;
			total += stop;
		}
		out ( t,s,total );
	}
	return 0;
}