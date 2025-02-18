class Solution {
public:

    string transform(string s){                                                                                     
    string temp="#";                                                                                            
    for(char ch:s){                                                                                             
        temp+=ch;                                                                                               
        temp+="#";                                                                                              
    }                                                                                                           
    return temp;                                                                                                
}                                                                                                               
                                                                                                                
string longestpalindrome(string s){                                                                             
    string t= transform(s);                                                                                     
    int n=t.size();                                                                                             
    int l=0;   //to check the left boundary of the right most palindrome found so far                           
    int r=0;   //to check the right boundary of the right most palindrome found so far                          
    int center;  //to track the index of the longest palindrome                                                 
    int maxlen=0;  //to track the longest palindrome                                                            
    vector<int>p(n);                                                                                            
    p[0]=0;                                                                                                     
    for(int i=1;i<n;i++){                                                                                       
        int k;                                                                                                  
        //Expand around the ith index to compute p[i]                                                           
        if(i>r){                                                                                                
           k=0;                                                                                                 
        }                                                                                                       
        else{                                                                                                   
            int j=l+(r-i);                                                                                      
            if(j-p[j]>l){                                                                                       
                p[i]=p[j];                                                                                      
                continue;                                                                                       
            }                                                                                                   
            else{                                                                                               
                k=r-i;                                                                                          
            }                                                                                                   
        }                                                                                                       
        while (i-k>=0 && i+k<n && t[i-k]==t[i+k]){                                                              
            k++;                                                                                                
        }                                                                                                       
        k--;                                                                                                    
        p[i]=k;                                                                                                 
        if(p[i]>maxlen){                                                                                        
            maxlen=p[i];                                                                                        
            center=i/2;                                                                                         
        }                                                                                                       
        if(i+k>r){                                                                                              
            l=i-k;                                                                                              
            r=i+k;                                                                                              
        }                                                                                                       
    }                                                                                                           
    return s.substr(center-(maxlen/2),maxlen);                                                                  
}                                                                                                               
                                                                                                                

    string longestPalindrome(string s) {
        return longestpalindrome(s);
    }
};