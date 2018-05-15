#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	cout << min ( min ( min ( a, 600 ) + min ( b, 600 ), 1000 ) + min ( c, 800 ), 1500 )<< '\n';
}