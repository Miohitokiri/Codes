// by. MiohitoKiri5474
#include<stdio.h>
#include<math.h>
#include<string.h>

double strToDouble ( int len, char str[] ){
	int idx = 0, i, res = 0, flag = 0;
	double resD = 0.0, cnt;
	if ( str[0] == '-' ){
		flag = 1;
		str[0] = '0';
	}

	for ( idx = 0 ; idx < len ; idx++ ){
		if ( str[idx] == '.' )
			break;
	}

	for ( i = 0 ; i < len ; i++ ){
		if ( i == idx )
			break;
		res *= 10;
		res += ( str[i] - '0' );
	}

	if ( idx == len ){
		if ( flag == 1 )
			res *= -1;
		return res * 1.0;
	}

	for ( i = len - 1 ; i >= idx ; i-- ){
		resD /= 10.0;
		resD += ( str[i] - '0' );
	}
	resD += res * 1.0;

	if ( flag == 1 )
		resD *= -1.0;
	return resD;
}

int atoi ( int len, char str[] ){
	int i, res = 0;
	for ( i = 0 ; i < len ; i++ ){
		res *= 10;
		res += ( str[i] - '0' );
	}

	return res;
}

int c[64];
int translate ( int n ){
	int i = 0, j, tmp, res = 0;
	while ( n ){
		c[i++] = ( n & 1 );
		n >>= 1;
		res++;
	}

	for ( j = 0 ; j < ( i >> 1 ) ; j++ ){
		tmp = c[j];
		c[j] = c[i - j - 1];
		c[i - j - 1] = tmp;
	}

	c[i] = -1;

	return res - 1;
}

// union part
typedef union fd{
	float f;
	double d;
} fd;
typedef union bitPattern{
	char f64[70];
	char f32[35];
} bitPattern;

void solve1Univer ( fd Num, int len ){
	double basic = ( len == 32 ? Num.f : Num.d ), num = basic;
	int data[64];
	int bit[64], pre[64];
	int swp = basic, tmp, i, j;
	for ( i = 0 ; i < len ; i++ )
		data[i] = 0;
	if ( basic < 0 ){
		data[0] = 1;
		num *= -1.0, swp *= -1;
	}
	tmp = translate ( swp );
	for ( i = 0 ; i < len ; i++ )
		bit[i] = c[i];
	bit[i] = c[i];

	translate ( tmp + 127 );
	for ( i = 0 ; i < len ; i++ ){
		!~c[i] ? c[i] = 0 : c[i];
		pre[i] = c[i];
	}
	for ( i = 0 ; i < len && bit[i] != -1 ; i++ );

	while ( num != 0.0 ){
		if ( num - ( int ) num == 0 )
			break;
		num -= ( int ) num;
		num *= 2;
		bit[i++] = ( int ) num;
	}

	tmp = i;
	for ( i = 1, j = 0 ; i < 9 ; i++, j++ )
		data[i] = pre[j];
	for ( i = 9, j = 1 ; j < tmp ; i++, j++ )
		data[i] = bit[j];

	for ( i = 0 ; i < len ; i++ )
		!~data[i] ? data[i] = 0 : data[i];

	printf ( "%d ", ( basic < 0 ? 1 : 0 ) );
	for ( i = 1 ; i < 9 ; i++ )
		putchar ( '0' + data[i] );
	putchar ( ' ' );
	for ( i = 9 ; i < len ; i++ )
		putchar ( '0' + data[i] );
	puts ( "" );
}

void solve2Univer ( bitPattern input, int len ){
	int data[64], i, digit = 0, st = ( len == 32 ? 9 : 12 );
	double res = 0.0, cnt;
	if ( len == 32 )
		for ( i = 0 ; i < 32 ; i++ )
			data[i] = input.f32[i];
	else
		for ( i = 0 ; i < 64 ; i++ )
			data[i] = input.f64[i];

	for ( i = 1 ; i < st ; i++ ){
		digit <<= 1;
		if ( data[i] == '1' )
			digit |= 1;
	}
	digit -= ( len == 32 ? 127 : 1023 );
	digit += st;
	st--;

	data[st] = '1';
	for ( i = st ; i < digit ; i++ ){
		res *= 2.0;
		if ( data[i] == '1' )
			res += 1.0;
	}

	for ( cnt = -1.0 ; i < len ; i++, cnt -= 1.0 )
		if ( data[i] == '1' )
			res += pow ( 2, cnt );

	printf ( "%lf\n", res * ( data[0] == '1' ? -1 : 1 ) );
}

// struct part
typedef struct fu{
	fd num;
	int bit;
} fu;
typedef struct bitPattern2{
	bitPattern bp;
	int bit;
} bitPattern2;

void solve1Strver ( fu input ){
	fd Num = input.num;
	double basic = ( input.bit == 32 ? Num.f : Num.d ), num = basic;
	int swp = basic, tmp, i, j, len = input.bit;
	int data[64];
	int bit[64], pre[64];
	for ( i = 0 ; i < len ; i++ )
		data[i] = 0;
	if ( basic < 0 ){
		data[0] = 1;
		num *= -1.0, swp *= -1;
	}
	tmp = translate ( swp );
	for ( i = 0 ; i < len ; i++ )
		bit[i] = c[i];
	bit[i] = c[i];

	translate ( tmp + 127 );
	for ( i = 0 ; i < len ; i++ ){
		!~c[i] ? c[i] = 0 : c[i];
		pre[i] = c[i];
	}
	for ( i = 0 ; i < len && bit[i] != -1 ; i++ );

	while ( num != 0.0 ){
		if ( num - ( int ) num == 0 )
			break;
		num -= ( int ) num;
		num *= 2;
		bit[i++] = ( int ) num;
	}

	tmp = i;
	for ( i = 1, j = 0 ; i < 9 ; i++, j++ )
		data[i] = pre[j];
	for ( i = 9, j = 1 ; j < tmp ; i++, j++ )
		data[i] = bit[j];

	for ( i = 0 ; i < len ; i++ )
		!~data[i] ? data[i] = 0 : data[i];

	printf ( "%d ", ( basic < 0 ? 1 : 0 ) );
	for ( i = 1 ; i < 9 ; i++ )
		putchar ( '0' + data[i] );
	putchar ( ' ' );
	for ( i = 9 ; i < len ; i++ )
		putchar ( '0' + data[i] );
	puts ( "" );
}

void solve2Strver ( bitPattern2 input ){
	int data[64], i, digit = 0,  len = input.bit, st = ( len == 32 ? 9 : 12 );
	double res = 0.0, cnt;
	if ( len == 32 )
		for ( i = 0 ; i < 32 ; i++ )
			data[i] = input.bp.f32[i];
	else
		for ( i = 0 ; i < 64 ; i++ )
			data[i] = input.bp.f64[i];

	for ( i = 1 ; i < st ; i++ ){
		digit <<= 1;
		if ( data[i] == '1' )
			digit |= 1;
	}
	digit -= ( len == 32 ? 127 : 1023 );
	digit += st;
	st--;

	data[st] = '1';
	for ( i = st ; i < digit ; i++ ){
		res *= 2.0;
		if ( data[i] == '1' )
			res += 1.0;
	}

	for ( cnt = -1.0 ; i < len ; i++, cnt -= 1.0 )
		if ( data[i] == '1' )
			res += pow ( 2, cnt );

	printf ( "%lf\n", res * ( data[0] == '1' ? -1 : 1 ) );
}

int main ( int argc, char *argv[] ){
	int type = atoi ( strlen ( argv[1] ), argv[1] ), i = 0, j, len = ( type & 1 ? 32 : 64 );
	fd numfd;
	fu numfu;
	bitPattern bpu;
	bitPattern2 bps;
	if ( type == 1 || type == 2 ){
		if ( type == 1 )
			numfd.f = strToDouble ( strlen ( argv[2] ), argv[2] );
		else
			numfd.d = strToDouble ( strlen ( argv[2] ), argv[2] );
		numfu.num = numfd;
		numfu.bit = len;
		printf ( "Struct: " );
		solve1Strver ( numfu );
		printf ( "Union:  " );
		solve1Univer ( numfd, len );
	}
	else{
		if ( type & 1 ){
			#define data bpu.f32
		}
		else{
			#define data bpu.f64
		}
		for ( j = 0 ; j < strlen ( argv[2] ) ; i++, j++ )
			data[i] = argv[2][j];
		for ( j = 0 ; j < strlen ( argv[3] ) ; i++, j++ )
			data[i] = argv[3][j];
		for ( j = 0 ; j < strlen ( argv[4] ) ; i++, j++ )
			data[i] = argv[4][j];
		data[i] = '\0';
		bps.bp = bpu;
		bps.bit = len;
		printf ( "Struct: " );
		solve2Strver ( bps );
		printf ( "Union:  " );
		solve2Univer ( bpu, len );
	}
}