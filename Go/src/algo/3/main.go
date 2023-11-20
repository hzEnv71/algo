package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)
func main(){
	fmt.Println(Contains([]string{"a", "b", "c"}, "b"))
    fmt.Println(Contains([]int{1, 2, 3}, 2))
    fmt.Println(Contains([]int{1, 2, 3}, 10))
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	in.Scan()
	n,_:= strconv.Atoi(in.Text())
	for i:=0;i<n;i++{
		in.Scan()
		s:=in.Text()
		index,_:= strconv.Atoi(s)
		for j,k:=1,1;k<=index;j++{
			ss:=strconv.Itoa(j)
			if !(j%3==0||ss[len(ss)-1]=='3'){
				if k==index{
					fmt.Println(j)
					break
				}
				k++
			}
			
		}
    }	
}

func Contains[T comparable](elems []T, v T) bool {
    for _, s := range elems {
        if v == s {
            return true
        }
    }
    return false
}
