var LinkedListNode = function(value) {


this.value = value;
this.next = null;

};



var a = new LinkedListNode('A');
var b = new LinkedListNode('B');
var c = new LinkedListNode('C');

a.next = b;
b.next = c;



var deleteNode = function(nodeToDelete) {

	var nextNode = nodeToDelete.next;

	if(nextNode) {

		console.log("Successfully deleted node with value: ", nodeToDelete.value);
		nodeToDelete.value = nextNode.value;
		nodeToDelete.next = nextNode.next;

	} else {
		throw new Error("Can't delete last node with this method");
	}

};

deleteNode(b);
deleteNode(c);