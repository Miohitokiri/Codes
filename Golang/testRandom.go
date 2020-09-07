/************************************/
/* Date		: 2020-07-23 12:32:04	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

// by. MiohitoKiri5474

package main

import "fmt"
import "math/rand"
import "time"

func Rand () int {
	r1 := rand.New ( rand.NewSource ( time.Now().UnixNano() ) )

	return r1.Intn ( 100 )
}

func main() {
	for i := 0 ; i < 10 ; i++ {
		fmt.Println ( Rand() )
	}
}