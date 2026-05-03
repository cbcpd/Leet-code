/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
var rotateString = function (A, B) {
    if (A.length !== B.length) {
        return false;
    }
    return ((A + A).indexOf(B) !== -1)
};

module.exports = rotateString;