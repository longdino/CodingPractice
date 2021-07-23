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
 * @return {number[]}
 */
var _inorder = function(root, order) {
    if(root) {
        if(root.left) _inorder(root.left, order);
        order.push(root.val);
        if(root.right) _inorder(root.right, order);
    }
    return order;
}

var inorderTraversal = function(root) {
    var output = [];
    return _inorder(root, output);
};