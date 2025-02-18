
// Convert a non-negative integer num to its English words representation.

// Example 1:
// Input: num = 123
// Output: "One Hundred Twenty Three"

// Example 2:
// Input: num = 12345
// Output: "Twelve Thousand Three Hundred Forty Five"

// Example 3:
// Input: num = 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

// Constraints:

// 0 <= num <= 2^31 - 1

// hint 1:
// Did you see a pattern in dividing the number into chunk of words? 
// For example, 123 and 123000.
// Hint 2
// Group the number by thousands (3 digits). 
// You can write a helper function that takes a number less than 
// 1000 and convert just that chunk to words.
// Hint 3
// There are many edge cases. What are some good test cases? 
// Does your code work with input such as 0? Or 1000010? 
// (middle chunk is zero and should not be printed out)


// Strategy 1: Break Down into Chunks
// -Handle Special Cases: Begin by handling the simplest case, 
// where num = 0. Return "Zero" directly.
// -Chunk Processing: Divide the number into three-digit chunks 
// (thousands, millions, billions).
// -Small Chunk Conversion: Create a helper function to convert 
// any three-digit number into words.
// -Concatenate Chunks: As you process each chunk, prepend its 
// corresponding scale ("Thousand", "Million", "Billion") if 
// the chunk is not zero.
// -Edge Cases and Clean-up: Handle edge cases where chunks might 
// return empty strings (like 000 in 1,000,000). 
// Clean up multiple spaces or trailing spaces.


#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    string numberToWords(int num){
        if(num == 0) return "Zero";
        vector<string> parts;
        vector<string> scale = {"", "Thousand", "Million","Billion"};
        int index = 0;

        while(num > 0){
            int chunk = num % 1000;
            if(chunk > 0){
                string chunkStr = threeDigitsToWords(chunk);
                if(!scale[index].empty()){
                    chunkStr += " " + scale[index];
                }
                parts.insert(parts.begin(), chunkStr); 
            }
            num /= 1000;
            index++;
        }
        return join(parts," ");
    }
private:
    string threeDigitsToWords(int num){
        vector<string> lessThan20 = {"","One","Two", "Three", "Four", "Five","Six","Seven","Eight",
                                        "Nine", "Ten","Eleven","Twelve", "Thirteen", "Fourteen", "Fifteen",
                                        "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty","Fifty","Sixty", "Seventy", "Eighty", "Ninety"};

        string result;
        int a = num /100, b = num %100, c = num%10;
        if(a>0) result += lessThan20[a] + " Hundred";
        if(b>0){
            if(a>0) result += " ";
            if(b<20) result += lessThan20[b];
            else{
                result += tens[b/10];
                if(c > 0) result += " " + lessThan20[c];
            }
        }
        return result;
    }

    string join(const vector<string>& parts, const string& delimiter){
        string result;
        for(size_t i = 0; i < parts.size(); i++){
            if(i > 0 ) result += delimiter;
            result += parts[i];
        }
        return result;
    }
};


// Strategy 2: Recursive Decomposition
// Key Steps:
// -Recursive Function: Implement a recursive helper function that handles each 
// three-digit chunk from the least significant to the most significant, 
// appending the scale (like "Thousand", "Million") based on the recursion depth.
// -Base Cases: The recursion should handle edge cases, including numbers less 
// than 20 directly, numbers between 20 and 99 using tens, and numbers 
// between 100 and 999 by combining hundreds and the recursive results
// of the remainder.
// -Scale Management: Use a static array or vector to manage scale names, 
// ensuring that each recursive call appends the correct scale based on 
// the current depth or the number of digits processed.
// -String Management: Handle spaces and string concatenation carefully 
// to avoid leading, trailing, or multiple consecutive spaces.
// -Efficiently Join Parts: As each recursive call returns, build the 
// string from the least significant part to the most significant part 
// by prepending strings to ensure correct word order.



class Solution{
public:
    string numberToWords(int num){
        if(num == 0) return "Zero";
        return trim(recursiveWords(num, 0));
    }
private:
    vector<string> scales = {"", "Thousand","Million","Billion"};

    string recursiveWords(int num, int level){
        if(num == 0) return "";
        if(num < 20) return singleDigits[num] + (level > 0 ? " " + scales[level] : "");
        if(num < 100) return tens[num / 10] + (num % 10 ? " " + recursiveWords(num % 10, 0) : "") + (level > 0 ? " " + scales[level] : "");
        if(num < 1000) return singleDigits[num / 100] + " Hundred" + (num % 100 ? " " + recursiveWords(num % 100, 0) : "") + (level > 0 ? " " + scales[level] : "");

        return recursiveWords(num/1000, level + 1)+ " " + recursiveWords(num%1000, level);
    }

    //helper to trim excess spaces from the result
    string trim(const string& str){
        string result;
        bool in_space = false;
        for(char c : str){
            if(c != ' ' || !in_space){
                if(c == ' ') in_space = true; else in_space = false;
                result += c;
            }
        }
        if(!result.empty() && result.back() == ' ') result.pop_back();
        return result;
    }
    vector<string> singleDigits = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                                   "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", 
                                   "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
};