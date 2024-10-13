class Solution {
public:
    bool isPalindrome(string s) {
        string str = ""; 

        
        for(const auto & c : s) {
            if (c >= 'a' && c <= 'z') 
                str += c; 
            else if (c >= 'A' && c <= 'Z') 
                str += 'a' + (c - 'A'); 
            else if(c >= '0' && c <= '9')
                 str += c ;
        }
        cout<< str; 
        int i = 0, j = str.size() - 1; 

        
        while (i <= j) {
            if (str[i++] != str[j--]) 
                return false;  
        }

        return true;  
    }
};
