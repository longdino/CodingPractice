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

var isValidBST = function(root) {
    
    if (!root) return true;
    if (root.left) {
        if (root.left.val >= root.val) return false;
    }
    if (root.right) {
        if (root.right.val <= root.val) return false;
    }
    var left = isValidBST(root.left);
    var right = isValidBST(root.right);
    if (left && root.left.val.left) {
        left = isValidBST(root.left.left);
    }
    if (right && root.right.right) {
        right = isValidBST(root.right.right);
    }
    return left && right;
};