/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */

var _isValidBST = function(root, min, max) {
    if (!root) return true;
    if (root.val <= min || root.val >= max) return false;
    var left = _isValidBST(root.left, min, root.val);
    var right = _isValidBST(root.right, root.val, max);
    return left && right;

};
var isValidBST = function(root) {
    return _isValidBST(root, -Infinity, Infinity);
};

console.log("Hello World");
