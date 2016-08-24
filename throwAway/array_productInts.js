/*
Write a function getProductsOfAllIntsExceptAtIndex() that takes an array 
of integers and returns an array of the products.

For example, given:

[1, 7, 3, 4] --->   [84, 12, 28, 21]

*/


var getProductsOfAllIntsExceptAtIndex = function(sub_arr) {

	if(sub_arr === null) {

		return null;

	}


	var product_on_right = [];
	product_on_right[sub_arr.length - 1] = 1;

	for (var i = sub_arr.length - 2; i >= 0; i--) {
		product_on_right[i] = product_on_right[i + 1] * sub_arr[i + 1];
	};

	var product_on_left = 1;

	var output_arr = [];
	for(var i = 0; i < sub_arr.length; i++) {
		output_arr.push(product_on_left * product_on_right[i]);
		product_on_left = product_on_left * sub_arr[i];
	}

	return output_arr;


}

var arr1 =  [1, 7, 3, 4];
console.log(getProductsOfAllIntsExceptAtIndex(arr1));



