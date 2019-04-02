/************************************/
/*  Date	: 2019-03-31 15:40:56	*/
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

func main(){
	n = make ( chan int )
	n <- 12
	data := <- n
	fmt.Println ( data )
}