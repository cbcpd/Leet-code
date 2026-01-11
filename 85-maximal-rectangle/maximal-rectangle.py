
class Solution:
    def maximalRectangle(self, binaryMatrix: List[List[str]]) -> int:
        totalRows, totalCols = len(binaryMatrix), len(binaryMatrix[0])
        # Edge case: single cell matrix
        if totalRows == 1 and totalCols == 1:
            return 1 if binaryMatrix[0][0] == '1' else 0
        # heightsHistogram stores heights of consecutive 1s column-wise
        heightsHistogram = [0] * (totalCols + 1)
        maximumRectangleArea = 0
        for rowIndex, currentRow in enumerate(binaryMatrix):
            indexStack = [-1]   # Monotonic increasing stack (stores indices)
            # Append a sentinel '0' to flush remaining stack
            currentRow.append('0')
            for colIndex, cellValue in enumerate(currentRow):
                # Build histogram heights
                if cellValue == '1':
                    heightsHistogram[colIndex] += 1
                else:
                    heightsHistogram[colIndex] = 0
                # Process decreasing heights
                while (
                    len(indexStack) > 1
                    and (colIndex == totalCols or
                         heightsHistogram[colIndex] < heightsHistogram[indexStack[-1]])
                ):
                    heightIndex = indexStack.pop()
                    width = colIndex - indexStack[-1] - 1
                    area = heightsHistogram[heightIndex] * width
                    maximumRectangleArea = max(maximumRectangleArea, area)

                indexStack.append(colIndex)

        return maximumRectangleArea        