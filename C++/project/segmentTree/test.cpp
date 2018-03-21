#include<bits/stdc++.h>

using namespace std;

int gcd(int a , int b){
    while(a % b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return b;
}

int main(){
	int a, b;
	cin >> a >> b;
	cout << gcd ( a, b ) << '\n';
}
