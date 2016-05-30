
/*
Find rectangle overlaps
var myRectangle = {

// coordinates of bottom-left corner
leftX: 1,
bottomY: 5,

// width and height
width: 10,
height: 4,

};

Case1 : if they dont overlap then return LeftX, leftY, 
width, height as null

Case 2: Return engulfed rectangle if that is the case
Case 3: Return actual rectangle overlap
*/

var findRectOverlap = function(rect1, rect2) {


	debugger;
	var overlapStartX = Math.max(rect1.leftX, rect2.leftX);
	var overlapEndX = Math.min( (rect1.leftX + rect2.width), 
		(rect2.leftX + rect2.width) );

	var overlapStartY = Math.max(rect1.bottomY, rect2.bottomY);
	var overlapEndY = Math.min( (rect1.bottomY + rect2.height), 
		(rect2.bottomY + rect2.height) );



// Case 1
// If they dont overlap at all

var resultRect = {};
resultRect.leftX = null;
resultRect.bottomY = null;
resultRect.width = null;
resultRect.height = null;

if( (overlapStartX > overlapEndX) || 
	(overlapStartY > overlapEndY) ) {
	return resultRect;
}

resultRect.leftX = overlapStartX;
resultRect.bottomY = overlapStartY;
resultRect.width = overlapEndX - overlapStartX;
resultRect.height = overlapEndY - overlapStartY;

return resultRect;


}


//Test cases

var myRectangle1 = {

// coordinates of bottom-left corner
leftX: 1,
bottomY: 5,

// width and height
width: 10,
height: 4,

};

var myRectangle2 = {

// coordinates of bottom-left corner
leftX: 3,
bottomY: 5,

// width and height
width: 10,
height: 4,

};

console.log("Laps: ", findRectOverlap(myRectangle1, myRectangle2));
