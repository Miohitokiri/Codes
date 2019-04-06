/************************************/
/* Date		: 2019-03-31 15:40:56	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
)

func read() int {
	input := bufio.NewScanner ( os.Stdin )
	input.Scan()
	num, _ := strconv.Atoi ( input.Text() )
	return num
}

func min ( a int, b int ) int {
	if a > b {
		tmp := a
		a = b
		b = tmp
	}

	return a
}

func max ( a int, b int ) int {
	if a < b {
		tmp := a
		a = b
		b = tmp
	}

	return a
}

func _gcd ( a int, b int ) int {
	for a % b != 0 && b % a != 0 {
		if a > b {
			a %= b
		} else {
			b %= a
		}
	}

	return min ( a, b )
}

func main() {
	var a, b int
	init()
}

var dis[1005] int

func init() {
	for i := 0 ; i < 1005 ; i++ {
		dis[i] = i
	}
}

func find ( n int ) {
	if dis[n] == n {
		return n
	}
	dis[n] = find ( dis[n] )
	return dis[n]
}

func same ( a int, b int ) bool {
	return find ( a ) == find ( b )
}

func Union ( a int, b int ) {
	dis[find ( a )] = find ( b )
}