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

var _isValid = function (key, root) {
    /*console.log("========================");
    console.log("key = " + key);
    console.log("root: " + root.val);*/
    if (root.right) {
        //console.log("right: " + root.right.val);
        if (root.right.val <= root.val) return false;
        if (root.val < key && root.right.val >= key) {
            return false;
        }
        else {
            if (!_isValid(root.val, root.right)) return false;
        }
        if (!_isValid(key, root.right)) {
            return false;
        }
    }
    /*console.log("========================");
    console.log("root: " + root.val);*/
    if (root.left) {
        //console.log("left: " + root.left.val);
        if (root.left.val >= root.val) return false;
        if (root.val > key && root.left.val <= key) {
            return false;
        }
        else {
            if (!_isValid(root.val, root.left)) return false;
        }
        if (!_isValid(key, root.left)) {
            return false;
        }
    }

    return true;
};

var isValidBST = function (root) {
    return _isValid(root.val, root);
};