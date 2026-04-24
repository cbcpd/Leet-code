

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0;
        int countR = 0;
        int count_ = 0;
        for(int i=0; i<moves[i]; i++){
            if(moves[i] == 'L') countL++;
            else if(moves[i] == 'R') countR++;
            else count_++;
        }
        return abs(countL - countR) + count_;     
    }
};