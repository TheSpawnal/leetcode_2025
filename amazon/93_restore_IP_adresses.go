package main

import (
	"fmt"
	"strconv"
)

func restoreIpAddresses(s string) []string {
	var result []string
	backtrack(s,0,0,"",&result)
	return result
}

func backtrack(s string, start, dots int, path string, result* []string){
	if dots == 4 && start == len(s){
		//remove traillin dot before adding to the result
		*result = append(*result, path[:len(path)-1])
		return
	}
	if dots > 4 || start >= len(s){
		return
	}
	for length :=1; length <= 3; length++{
		if start+length > len(s){
			break
		}
		segment := s[start : start+length]
		if isValid(segment){
			backtrack(s, start+length, dots+1, path+segment+".",result)
		}
	}
}

func isValid(segment string)bool{
	if len(segment) > 3 || (segment[0]=='0'&&len(segment)>1){
		return false
	}
	val, err := strconv.Atoi(segment)
	if err != nil{
		return false
	}
	return val >= 0 && val <= 255
}

