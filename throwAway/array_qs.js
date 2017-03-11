/* Implement randomized quicksort to sort an array 

[10,1,5,2,8,6,9,3,2,4]  -> [1,2,3,4,5,6,7,8,9,10]

Average case T(N) -> 2(T(n/2)) + Theta(n) -> nlogn

*/

var randomized_quicksort = function(sub_array) {


	if(sub_array === null || sub_array.length <= 1) {

		return sub_array;
	}


	return randomized_quicksort_util(sub_array, 0, sub_array.length - 1);


}

var randomized_quicksort_util = function(sub_array, start, end) {

	if(start > end) {
		return sub_array;	
	}

	if(sub_array === null || sub_array.length <= 1) {
		return sub_array;
	}

	var part_rank = partition(sub_array, start, end);

	if(part_rank == -1) {
		return sub_array;
	}

	randomized_quicksort_util(sub_array, start, part_rank - 1);
	randomized_quicksort_util(sub_array, part_rank + 1, end);
	return sub_array;

}

var getRandomInt = function(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

var partition = function(sub_array, start, end) {
	
	if(sub_array === null || start > end) {
		return -1;
	}

	var part_index = getRandomInt(start, end);
	//Swap this index with first 
	if(part_index > end || part_index < start) {
		part_index = start;
	}

	var temp = sub_array[start];
	sub_array[start] = sub_array[part_index];
	sub_array[part_index] = temp;


	//Now partition the array based on part_index elem
	var part_elem = sub_array[start];
	var i = start;
	var j = i + 1;

	for(; j <= end; j++) {
		if(sub_array[j] < part_elem) {
			//Swap ith + 1 and cur_elem
			var temp = sub_array[i + 1];
			sub_array[i + 1] = sub_array[j];
			sub_array[j] = temp;
			i++; 
		}
	}

	//Do the last swap
	sub_array[start] = sub_array[i];
	sub_array[i] = part_elem;

	return i;

}


console.log(randomized_quicksort([10,1,5,2,8,6,9,3,7,4]));
console.log(randomized_quicksort([1,2,3,4,5]));
console.log(randomized_quicksort([5,4,3,2,1]));
console.log(randomized_quicksort([5,4,3,2]));
console.log(randomized_quicksort([5,3]));
console.log(randomized_quicksort([5]));

