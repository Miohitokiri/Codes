#include<bits/stdc++.h>

int main(){
	char c;
	while ( ( c = getchar() ) && c != EOF ){
		if ( ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) ) 
			c ^= 32;
		else if ( c != '\n' )
			c = 32;
		putchar ( c );
	}
}