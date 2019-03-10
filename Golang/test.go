package main
import (
	"fmt"
)
func main(){
	// var s, swp string
	lib := "1234567"
	for i := 1 ; i < len ( lib ) ; i++ {
		fmt.Print ( lib[len ( lib ) - i] )
		fmt.Print ( " " )
	}

	fmt.Println()
	// fmt.Println ( lib )
	fmt.Println ( len ( lib ) )
}