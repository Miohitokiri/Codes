/************************************/
/*  Date	: 2019-03-19 10:47:08	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

package main

import (
	"fmt"
	// "os"
	// "bufio"
)

func main(){
	e := 1000000007
	p := 5039
	q := 514229
	var (
		n int
		d int
		c int
		m int
		phi int
		tp string
	)

	// fmt.Scanf ( "%d %d\n", &p, &q )
	n = p * q
	phi = ( p - 1 ) * ( q - 1 )
	d = _pow ( e, phi - 1, n )
	fmt.Println ( d )
	fmt.Println ( _pow ( 2, d * e, n ) )
	c = 10
	m = 10
	tp = "10"
	fmt.Printf ( "%d %d %s\n", c, m, tp )
}

func _pow ( a int, b int, mod int ) int {
	res := 1
	base := a
	for b != 0 {
		if b % 2 == 1 {
			res *= base
			res %= mod
		}
		base *= base
		base %= mod
		b >>= 1
	}

	return res
}