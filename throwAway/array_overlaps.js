
/* Merge overlaps */
//[] [6,8], [1,9], [2,4], [4,7] ];
/*

Debuggig mistake: 
1. Please remember to watch out for any typos that makes array out of bound 
E.g., 
var new_min = Math.min(elem1[0], elem1[1], elem2[0], elem2[2]);
Look at the last element, by mistake it is pointing to out of bound array
hence was returning NaN in outputs
Correction below:
var new_min = Math.min(elem1[0], elem1[1], elem2[0], elem2[1]);

*/

var mergeOverlapUnits = function(elem1, elem2) {

	var new_max = Math.max(elem1[0], elem1[1], elem2[0], elem2[1]);
	var new_min = Math.min(elem1[0], elem1[1], elem2[0], elem2[1]);
	return [new_min, new_max];

}

var mergeOverlaps = function(sub_arr) {

	if(sub_arr === null || sub_arr.length <= 1) {
		return sub_arr;
	}


	//Make sure the intervals are sorted w.r.t first element

	sub_arr.sort(function(a, b) {
		return a[0] - b[0];
	});

	//Modify the same array

	//Now merge the overlaps
	var prev_elem = sub_arr[0];
	var i = 0;
	for(var j = 1; j < sub_arr.length; j++) {

		var cur_elem = sub_arr[j];
		//Find if overlap or not
		if(prev_elem[1] >= cur_elem[0]) {
			prev_elem = mergeOverlapUnits(prev_elem, cur_elem);
		} else {
			//Put this element in the array
			sub_arr[i++] = prev_elem;
			prev_elem = cur_elem;
		}

		if(sub_arr.length - 1 === j) {
			//Last element
			sub_arr[i++] = prev_elem;
		}

	}
	// Now delete the remaining elements at the end
	var len = sub_arr.length;
	for(; i < sub_arr.length; i++) {
		delete sub_arr[i];
	}

return sub_arr;

};


console.log(mergeOverlaps([[6,8],[1,9],[2,4],[4,7]]));




