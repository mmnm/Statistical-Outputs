  
  /* 
  Write a function to find the rectangular intersection 
  of two given rectangles.


Format

  var myRectangle = {

    // coordinates of bottom-left corner
    leftX: 1,
    bottomY: 5,

    // width and height
    width: 10,
    height: 4,

};


  x1----x3---x2---x4  

*/


var findIntersectionRectangle = function(myRectangle1, myRectangle2) {

	if(myRectangle1 === null || myRectangle2 === null) {
		return null;
	}

	var x1 = myRectangle1.leftX;
	var x2 = myRectangle1.leftX + myRectangle1.width;
	var x3 = myRectangle2.leftX;
	var x4 = myRectangle2.leftX + myRectangle2.width;


	var y1 = myRectangle1.bottomY;
	var y2 = myRectangle1.bottomY + myRectangle1.height;
	var y3 = myRectangle2.bottomY;
	var y4 = myRectangle2.bottomY + myRectangle2.height;

	//Find overlapped Rectangle coords
	var res_x1 = 0;
	var res_x2 = 0;
	var res_y1 = 0;
	var res_y2 = 0;

	var sample_width = 0;

	if(x4 > x2) {
		sample_width = x4 - (x4 - x2);

	} else {
		sample_width = x2 - (x2 - x4);
	}

	if(x3 > x1) {
		res_x1 = x3;
		res_x2 = x3 + (sample_width - x3);
	} else {
		res_x1 = x1;
		res_x2 = x1 + (sample_width - x1);
	};

	if(y4 > y2) {
		sample_width = y4 - (y4 - y2);

	} else {
		sample_width = y2 - (y2 - y4);
	}

	if(y3 > y1) {
		res_y1 = y3;
		res_y2 = y3 + (sample_width - y3);
	} else {
		res_y1 = y1;
		res_y2 = y1 + (sample_width - y1);
	};

	if((res_x2 - res_x1 <= 0) || (res_y2 - res_y1 <= 0)) {
		return null;
	}

	var myRectangleAnswer = {};
	myRectangleAnswer.leftX = res_x1;
	myRectangleAnswer.bottomY = res_y1;
	myRectangleAnswer.width = res_x2 - res_x1;
	myRectangleAnswer.height = res_y2 - res_y1;

	return myRectangleAnswer;


}


var findIntersectionRectangleOptimized = function(myRectangle1, myRectangle2) {

	if(myRectangle1 === null || myRectangle2 === null) {
		return null;
	}

	var x1 = myRectangle1.leftX;
	var x2 = myRectangle1.leftX + myRectangle1.width;
	var x3 = myRectangle2.leftX;
	var x4 = myRectangle2.leftX + myRectangle2.width;


	var y1 = myRectangle1.bottomY;
	var y2 = myRectangle1.bottomY + myRectangle1.height;
	var y3 = myRectangle2.bottomY;
	var y4 = myRectangle2.bottomY + myRectangle2.height;

	//Find overlapped Rectangle coords
	var startX = [0,0];
	var startY = [0,0];

	var startX = overlapPoints(x1,x2,x3,x4);
	var startY = overlapPoints(y1,y2,y3,y4);

	if(startX === null || startY === null) {
		// console.log("Optimized: No overlap;")
		return null;
	}

	var myRectangleAnswer = {};
	myRectangleAnswer.leftX = startX[0];
	myRectangleAnswer.bottomY = startY[0];
	myRectangleAnswer.width = startX[1] - startX[0];
	myRectangleAnswer.height = startY[1] - startY[0];

	return myRectangleAnswer;


}


var overlapPoints = function(t1, t2, t3, t4) {

	var startOverlapT1 = Math.max(t1, t3);
	var endOverlapT1 = Math.min(t2, t4);

	if(endOverlapT1 - startOverlapT1 <= 0) {
		return null;
	}

	return [startOverlapT1, endOverlapT1];

}



console.log(findIntersectionRectangle({"leftX": 0, "bottomY": 0, "width": 10,
																			"height": 10}, 
																			{"leftX": 5, "bottomY": 0, "width": 10,
																			"height": 5}));

console.log(findIntersectionRectangle({"leftX": 0, "bottomY": 0, "width": 10,
																			"height": 10}, 
																			{"leftX": 11, "bottomY": 0, "width": 10,
																			"height": 5}));

console.log(findIntersectionRectangle({"leftX": 0, "bottomY": 0, "width": 10,
																			"height": 10}, 
																			{"leftX": 11, "bottomY": 12, "width": 10,
																			"height": 5}));

console.log(findIntersectionRectangle({"leftX": 0, "bottomY": 0, "width": 10,
																			"height": 10}, 
																			{"leftX": 1, "bottomY": 1, "width": 4,
																			"height": 5}));

console.log("Optimized test function");

console.log(findIntersectionRectangleOptimized({"leftX": 0, "bottomY": 0, "width": 10,
																			"height": 10}, 
																			{"leftX": 5, "bottomY": 0, "width": 10,
																			"height": 5}));

console.log(findIntersectionRectangleOptimized({"leftX": 0, "bottomY": 0, "width": 10,
																			"height": 10}, 
																			{"leftX": 11, "bottomY": 0, "width": 10,
																			"height": 5}));

console.log(findIntersectionRectangleOptimized({"leftX": 0, "bottomY": 0, "width": 10,
																			"height": 10}, 
																			{"leftX": 11, "bottomY": 12, "width": 10,
																			"height": 5}));

console.log(findIntersectionRectangleOptimized({"leftX": 0, "bottomY": 0, "width": 10,
																			"height": 10}, 
																			{"leftX": 1, "bottomY": 1, "width": 4,
																			"height": 5}));


