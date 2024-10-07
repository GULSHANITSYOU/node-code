class Solution {
public:
    int minLength(string s) {

        auto nop = s.find(":"); 
        auto posab = nop , poscd = nop ; 

        while((posab = s.find("AB")) != nop || (poscd = s.find("CD")) != nop){
            if(posab != nop )
            s.erase(posab,2); 
            else if (poscd != nop)
            s.erase(poscd,2);
        }
        
        return s.size(); 
    }
};