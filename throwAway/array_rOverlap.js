/*

Find if two rectangles overlap
l1, r1 -> [x,y] 
l1, r1 - > rect1_coords = [l1,r1, l2,r2]


*/

var isRectangleOverlap = function(l1,r1,l2,r2) {

var x1 = l1[0];
var y1 = l1[1];

var x2 = r1[0];
var y2 = r1[1];

var x3 = l2[0];
var y3 = l2[1];

var x4 = r2[0];
var y4 = r2[1];

	if(x3 > x2 || x1 > x4) {
		console.log("x false");
		return false;
	}

	if(y4 > y1 || y2 > y3) {
				console.log("y false");
		return false;
	}

	return true;

}

//Test case 1

console.log(isRectangleOverlap([0,10], [10,0], [5,5], [15,0]));




