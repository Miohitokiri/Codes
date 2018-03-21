#include<iostream>
#include<float.h>
#include<iomanip>
using namespace std;
double c ( double f ){
	return ( f - 32 ) * 5 / 9;
}
int main(){
	double f;
	while ( cin >> f ){
		cout << fixed << setprecision( 3 ) << c ( f ) << endl;
	}
}
