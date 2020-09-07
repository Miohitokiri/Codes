/************************************/
/* Date		: 2020-07-17 11:11:11	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

// by. MiohitoKiri5474

package main

import . "fmt"

type node *int

func plus2 ( n node, m node ) {
	*n += *m
}

func main() {
	num1, num2 := 10, 100
	n, m := node ( &num1 ), node ( &num2 )
	plus2 ( n, m )
	Println ( *n )
}