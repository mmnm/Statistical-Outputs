/*
Reverse alternate K nodes in a Singly Linked List
Given a linked list, write a function to reverse every alternate k nodes (where k is an input to the function) in an efficient way. Give the complexity of your algorithm.

Example:
Inputs:   1->2->3->4->5->6->7->8->9->NULL and k = 3
Output:   3->2->1->4->5->6->9->8->7->NULL. 

*/


var Node = function(value) {
	this.value = value;
	this.next = null;
};

Node.prototype.constructor = Node;

Node.prototype.insertFront = function(value) {
	var temp = new Node(value);
	temp.next = this;
	return temp;
}

Node.prototype.reverseAltKnodes = function(k) {
	// if K is greater than ll length, then reverse the entire list. 

	var cur = this;
	var count = 0;
	var reverseFlag = true;
	var startNode = cur;
	var newStartNode = null;
	var prev = null;

	while(cur !== null) {

		if(reverseFlag === true) {
			//Continue reversing
			if(count < k) {
				var temp = cur;
				cur = cur.next;
				temp.next = prev;
				prev = temp;
				count++;

			} else if(count === k) {

				if(newStartNode === null) {
					newStartNode = prev;
				}

				count = 1;
				startNode.next = cur;
				startNode = null;
				reverseFlag = false;
				cur = cur.next;

			} else {
				console.log("why we are here: Debug");
			}

		} else {
			if(count < k) {
				count++;
			} else if(count === k){
				startNode = cur;
				count = 1;
				reverseFlag = false;

			} else {
				console.log("Hey are we here :::Debug");
			}
			
			cur = cur.next;
		}

	}
	return newStartNode;

}


Node.prototype.printList = function() {
	var cur = this;
	while(cur !== null) {
		console.log(' ', cur.value);
		cur = cur.next;
	}

}

var main = function() {


	var head = new Node(9);
	head = head.insertFront(8);
	head = head.insertFront(7);
	head = head.insertFront(6);
	head = head.insertFront(5);
	head = head.insertFront(4);
	head = head.insertFront(3);
	head = head.insertFront(2);
	head = head.insertFront(1);
	head.printList();
	head.reverseAltKnodes();
	head.printList();

}

main();


