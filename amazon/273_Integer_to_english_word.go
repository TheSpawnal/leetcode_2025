package main

import (
	"fmt"
	"strings"
)

func numberToWords(num int) string {
	if num == 0 {
		return "Zero"
	}

	parts := []string{}
	scales := []string{"", "Thousand", "Million", "Billion"}

	// Process each three-digit chunk
	index := 0
	for num > 0 {
		chunk := num % 1000
		if chunk > 0 {
			chunkStr := threeDigitsToWords(chunk)
			if scales[index] != "" {
				chunkStr += " " + scales[index]
			}
			parts = append([]string{chunkStr}, parts...)
		}
		num /= 1000
		index++
	}

	return strings.Join(parts, " ")
}

func threeDigitsToWords(num int) string {
	lessThan20 := []string{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
		"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
		"Sixteen", "Seventeen", "Eighteen", "Nineteen"}
	tens := []string{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}

	a := num / 100
	b := num % 100
	c := num % 10

	result := ""
	if a > 0 {
		result += lessThan20[a] + " Hundred"
	}
	if b > 0 {
		if a > 0 {
			result += " "
		}
		if b < 20 {
			result += lessThan20[b]
		} else {
			result += tens[b/10]
			if c > 0 {
				result += " " + lessThan20[c]
			}
		}
	}
	return result
}

func main() {
	fmt.Println(numberToWords(1234567)) // "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
	fmt.Println(numberToWords(12345))   // "Twelve Thousand Three Hundred Forty Five"
	fmt.Println(numberToWords(123))     // "One Hundred Twenty Three"
	fmt.Println(numberToWords(1000010)) // "One Million Ten"
}



//efficency ++ 

var (
    onesMap = map[int]string { 0: "Zero", 1: "One", 2: "Two", 3: "Three", 4 : "Four", 5 : "Five", 6: "Six", 7: "Seven", 8: "Eight", 9: "Nine"}
    teensMap = map[int]string {11: "Eleven", 12: "Twelve", 13: "Thirteen", 14: "Fourteen", 15: "Fifteen", 16: "Sixteen", 17: "Seventeen", 18: "Eighteen", 19: "Nineteen"}
    tensMap = map[int]string {10: "Ten", 20: "Twenty", 30: "Thirty", 40: "Forty", 50: "Fifty", 60: "Sixty", 70: "Seventy", 80: "Eighty", 90: "Ninety"}
)

func numberToWords(num int) string {
    // we need to go up to billion
    // keep dividing by 1000 and then add appropriate suffix
    ret := ""
    orignum := num
    if num >= 1000000000 {
        bn := num / 1000000000
        ret = helper(bn) + " Billion"
        num = num % 1000000000 
    }
    if num >= 1000000 {    
        mn := num/1000000
        ret = ret + " " + helper(mn) + " Million"
        num = num % 1000000         
    }
    if num >= 1000 {    
        mn := num/1000
        ret = ret + " " + helper(mn) + " Thousand"
        num = num % 1000
    }    
    if num > 0 {
        ret = ret + " " + helper(num)
    }
    if orignum == 0 {
        ret = helper(num)
    } 
    return strings.TrimSpace(ret)
}

func helper(num int) string {
    ret := ""
    if len(strconv.Itoa(num)) == 3 {
        hd := num/100 
        ret = onesMap[hd] + " Hundred"
        num = num%100
        td := num/10
        if num > 0 {
            if _, ok := teensMap[num]; ok {
                ts := teensMap[num]
                ret = ret + " " + ts
                return ret
            } else if _, ok1 := tensMap[td*10]; ok1 {
                ts := tensMap[td*10]
                ret = ret + " " + ts
            }
        }
        num = num%10
        if num > 0 {
            if _, ok := onesMap[num]; ok {
                 return ret + " " +  onesMap[num]   
            }
        }
    } else if len(strconv.Itoa(num)) == 2 {
        if _, ok := teensMap[num]; ok {
            ts := teensMap[num]
            ret = ts
            return ret
        } 
        td := num/10        
        if _, ok := tensMap[td*10]; ok {
            ts := tensMap[td*10]
            ret = ts
        }
        num = num%10
        if num > 0 {
            if _, ok := onesMap[num]; ok {
                 return ret + " " +  onesMap[num]   
            }        
        }
    } else if len(strconv.Itoa(num)) == 1 {
        if _, ok := onesMap[num]; ok {
            return  onesMap[num]   
        }        
    }
    return ret
}
