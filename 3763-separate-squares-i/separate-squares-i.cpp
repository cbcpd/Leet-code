
class Solution {
public:
    double getMinY(const vector<vector<int>>& squares) {
        double minY = squares[0][1];
        for (const auto& square : squares) {
            minY = min(minY, square[1]*1.0);
        }
        return minY;
    }

    double getMaxY(const vector<vector<int>>& squares) {
        double maxY = squares[0][1] + squares[0][2];
        for (const auto& square : squares) {
            maxY = max(maxY, (square[1] + square[2])*1.0);
        }
        return maxY;
    }

    bool isLowerHalfLarger(const vector<vector<int>>& squares, double midY) {
        double lowerArea = 0, upperArea = 0;

        for (const auto& square : squares) {
        double bottomY = square[1], side = square[2], topY = bottomY + side;

            if (topY <= midY) {
                lowerArea += side * side;
            } else if (bottomY >= midY) {
                upperArea += side * side;
            } else {
                double below = midY - bottomY, above = topY - midY;
                lowerArea += below * side;
                upperArea += above * side;
            }
        }

        return lowerArea >= upperArea;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double minY = getMinY(squares);
        double maxY = getMaxY(squares);
        double precision = 1e-5;

        while (maxY - minY > precision) {
        double midY = (minY + maxY) / 2;
            if (isLowerHalfLarger(squares, midY)) {
                maxY = midY;
            } else {
                minY = midY;
            }
        }
        
        return minY;
    }
};