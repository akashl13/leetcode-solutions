
/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {number[][]}
 */
Array.prototype.snail = function(rowsCount, colsCount) {
    const nums = this;

    if (rowsCount * colsCount !== nums.length) {
        return [];
    }

    const result = Array.from(
        { length: rowsCount },
        () => Array(colsCount).fill(0)
    );

    for (let col = 0; col < colsCount; col++) {
        for (let row = 0; row < rowsCount; row++) {

            if (col % 2 === 0) {
                result[row][col] = nums[col * rowsCount + row];
            } else {
                result[row][col] = nums[col * rowsCount + (rowsCount - 1 - row)];
            }

        }
    }

    return result;
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna