/* Find a pair with given sum in a Balanced BST */


var BST = function(val) {
	this.value = val;
	this.left = null;
	this.right = null;
}

BST.prototype.constructor = BST;

BST.prototype.insert = function(val) {

	var temp = root = this;

	if(root === null) {
		//Empty root
		var root = new BST(val); 
	} else {
		//Find the position to insert
		var prev;

		while(temp !== null) {
			prev = temp;

			if(temp.value > val) {
				temp =  temp.left;
			} else {
				temp = temp.right;
			}
		}
		//We found the leaf node, insert properly
		if(prev.value > val) {
			prev.right = new BST(val);
		} else {
			prev.left = new BST(val);
		}

	}
	return root;

}

BST.prototype.printInorderTree = function() {
	var cur = this;

	if(cur === null) {
		return;
	}
	cur.left.printInorderTree();
	console.log(root.value + " ");
	cur.right.printInorderTree();

}


BST.prototype.pairSum = function(target) {

	var root = this;
	if(root === null) {
		return -1;
	}

	//For O(n) algo, we can do inorder traversal and save the elems in an array
	var array = [];

	var copyElems = function(root) {
		if(root === null) {
			return;
		}

		copyElems(root.left);
		array.push(root.value);
		copyElems(root.right);
	}

	copyElems(root);
	//At this point we have all the elems in array
	//Now there are two methods to solve this in O(n) Time
	//Lets use Hash, remember Hash will take O(n) Space

	var hashSumPair = {};
	for (var i = 0; i < array.length; i++) {
		var key = array[i];
		if(key in hashSumPair) {
			var output = [];
			output.push(hashSumPair[key]);
			output.push(i);
			break;
		}
		hashSumPair[target - key] = i;
	};
	return output;

}

var main = function() {
	    /*
                   15
                /     \
              10      20
             / \     /  \
            8  12   16  25    */
    var root = new BST(15);
    root.left = new BST(10);
    root.right = new BST(20);
    root.left.left = new BST(8);
    root.left.right = new BST(12);
    root.right.left = new BST(16);
    root.right.right = new BST(25);



    var target = 33;
    var ret = root.pairSum(target));
		if(ret.length === 0) {
			console.log("Pair not found with target");
		}
	
 
}

main();


