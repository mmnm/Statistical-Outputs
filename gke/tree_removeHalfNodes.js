/*
Given a binary tree, how do you remove all the half nodes?
Given A binary Tree, how do you remove all the half nodes (which has only one child)? Implement a method
Note leaves should not be touched as they have both children as NULL.
//Assume no duplicates
*/


var Node = function(val) {

	this.value = val;
	this.left = null;
	this.right = null;

};

Node.prototype.isLeftChild = function(parent) {
	var root = this;
	if(parent === null) {
		return -1;
	} else if (parent.left.value === root.value) {
		return true;
	} else if(parent.right.value === root.value) {
		return false;
	} else {
		console.log("Debug this no match isLeftChild");
		return -1;
	}

}

Node.prototype.removeHalfNodes = function() {
	// Algo:
	// Use post order traversal
	// 	for each node replace with child if Half node

	var root = this;
	if(root === null || root === undefined) {
		return root;
	}

	if(root.left) {
		root.left = root.left.removeHalfNodes();
	}

	if(root.right) {
		root.right = root.right.removeHalfNodes();
	}

	//Check if this is half node
	if(root.left === null && root.right === null) {
		//Do nothing
		return root;

	} else if(root.left === null) {
		// This is a half node, take action
		return root.right;
		
	} else if(root.right === null) {
		// This is a half node, take action
		return root.left;

	} else {
		console.log("Debug non-matching case");
	}

	return root;

}

Node.prototype.printInorder = function() {
	var root = this;

	if(root === null || root === undefined) {
		return;
	}

	if(root.left) {
		root.left.printInorder();
	}

	console.log(" ", root.value);
	
	if(root.right) {
		root.right.printInorder();
	}
}

// Driver program
var main = function() {

	var NewRoot = null;
	var root = new Node(2);
	root.left        = new Node(7);
	root.right       = new Node(5);
	root.left.right = new Node(6);
	root.left.right.left= new Node(1);
	root.left.right.right = new Node(11);
	root.right.right = new Node(9);
	root.right.right.left = new Node(4);

	console.log("Inorder traversal of given tree \n");
	root.printInorder();

	NewRoot = root.removeHalfNodes();

	console.log("\nInorder traversal of the modified tree \n");
	NewRoot.printInorder();
	
}

main();
