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
 * @return {number}
 */

var _max  = function(root, level) {
    if(!root) return level;
    else {
        level++;
        var left = 0;
        var right = 0;
        if (root.left) left = _max(root.left, level);
        if (root.right) right = _max(root.right, level);
        
        var max = left;
        if (right > max) max = right;
        if (level > max) max = level;
        
        return max;
    }
    
}

var maxDepth = function(root) {
    var level = 0;
    return _max(root, level);
};