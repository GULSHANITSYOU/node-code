class Solution {
public:
    int maxArea(vector<int>& height) {

        int s = 0;
        int size = height.size();  
        int e = size-1; 
        int res = INT_MIN ;

        while( s < e){
            int x = e-s; 
            int y = min(height[s],height[e]); 
            int area = x*y;

            res = max(res,area);

            if(height[s] > height[e])
            e--; 
            else s++ ;  

        }

        return res; 

        
    }
};