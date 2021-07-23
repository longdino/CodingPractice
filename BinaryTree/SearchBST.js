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
    if(!root) {
        root = null;
        return root;
    }
    
    if(root.val == val) {
        return root;
    }
    
    var tree = root;
    
    if(root.val > val) {
        tree = searchBST(root.left, val);
        if(tree && tree.val == val) return tree;
    }
    else if(root.val < val) {
        tree = searchBST(root.right, val);
        if(tree && tree.val == val) return tree;
    }
    
    if(!tree) {
        root = null;
        return root;
    }
};