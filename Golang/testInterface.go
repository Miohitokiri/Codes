/************************************/
/* Date		: 2020-07-17 12:10:41	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

// by. MiohitoKiri5474

package main

import "fmt"

type nodeInterface interface {
	plus ( value int )
}

type nodeValue struct {
	a, b int
}

func ( self *nodeValue ) plus ( value nodeValue ) {
	self.a += value.a
	self.b += value.b
}

func main(){
	n := nodeValue { a: 100, b: 200 }
	n.plus ( nodeValue { a: 100, b: 200 } )
	fmt.Println ( n )
}