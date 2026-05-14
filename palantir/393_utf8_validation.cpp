class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int still_left = 0;
        for(int i = 0; i < data.size(); i++){
          int x = data[i];

          if(!still_left){
            if((x >> 5) == 0b110) still_left = 1; //shifting 5 bits
            else if((x >> 4) == 0b1110) still_left = 2; //shifting 4 bits
            else if((x >> 3) == 0b11110) still_left = 3; //shifting 3 bits
            else if((x >> 7) != 0) return false; //shifting 7 bits
          }
          else {
            if((x >> 6) != ob10) return false;
            still_left--;
          }
        }
        return (still_left == 0);
    }
};
