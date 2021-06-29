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
 * @param {number} val
 * @return {TreeNode}
 */
var searchBST = function(root, val) {
    if(root.val == val) {
        return root;
    }
    else if(root.left || root.right) {
        var left = root;
        var right = root;
        if(root.left) {
            left = searchBST(root.left, val);
            if(left && left.val == val) return left;
        }
        if(root.right) {
            right = searchBST(root.right, val);
            if(right && right.val == val) return right;
        }
        if(!left && !right) {
            root = null;
            return root;
        }
    }
    else {
        root = null;
        return root;
    }
};