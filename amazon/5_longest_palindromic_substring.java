
class Solution{
    int len ;
    int star;

    public String longestPalindrome(String s){
        len = 0;
        start = 0;
        for(int i =0; i < s.length();i++){
            helper(s,i-1,i+1);
            helper(s,i,i+1);
            if(s.length() - i < len / 2){
                break;
            }
        }
        return s.substring(start, start + len);
    }
    private void helper(String s, int low, int high){
        while(low >= 0 && high < s.length() && s.charAt(low) == s.charAt(high)){
            low--;
            high++;
        }
        if(high - low - 1 > len){
            len = high - low - 1;
            start = low + 1;
        }
    }
}