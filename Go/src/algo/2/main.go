package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)
func main(){
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	in.Scan()
	n,_:= strconv.Atoi(in.Text())
	for i:=0;i<n;i++{
		in.Scan()
		s:=in.Text()
	    if len(s)>10{
		    s=string(s[0])+strconv.Itoa(len(s)-2)+string(s[len(s)-1])    
	    }
		fmt.Println(s)
    }	
}