class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area_a = (ax2 - ax1) * (ay2 - ay1);
        int area_b = (bx2 - bx1) * (by2 - by1);
        
        int total = area_a + area_b;
        
        int lft = max(ax1, bx1);
        int rgt = min(ax2, bx2);
        int vertical_overlap = rgt - lft;
        
        int dwn = max(ay1, by1);
        int top = min(ay2, by2);
        int hori_overlap = top - dwn;
        
        
        if( vertical_overlap > 0 && hori_overlap > 0 )
            total -= ( vertical_overlap * hori_overlap);
        
        
        
        return total;
        
    }
};