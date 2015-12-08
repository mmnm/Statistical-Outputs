/*
Find Minimum Depth of a Binary Tree
Given a binary tree, find its minimum depth. The minimum depth is the number of BTs 
along the shortest path from root BT down to the nearest leaf BT.

For example, minimum height of below Binary Tree is 2.

*/

//Algo minPath:
//if root is null
	//return 0

//Calculate leftheight = minPath(root.left)
//Calculate rightheight = minPath(root.right)
//return min(leftheight + rightheight) + 1




var BT = function(val) {
	this.value = val;
	this.left = null;
	this.right = null;
};

BT.prototype.constructor = BT;

BT.prototype.minPath = function() {
	var cur = this;

	if((cur === undefined) || 
		(cur === null)) {
		return 0;
}
var leftHeight = 0;
var rightHeight = 0;

if(cur.left) {
	leftHeight = cur.left.minPath();
}
if(cur.right) {
	rightHeight = cur.right.minPath();
}

return Math.min(leftHeight, rightHeight) + 1;

};

var main = function() {
    // Let us construct the Tree shown in the above figure
    var root        = new BT(1);
    root.left        = new BT(2);
    root.right       = new BT(3);
    root.left.left  = new BT(4);
    root.left.right = new BT(5);
    // debugger;
    console.log(root.minPath());
 
  }

  main();





