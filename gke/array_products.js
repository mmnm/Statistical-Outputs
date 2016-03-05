/*

You have an array of integers, and for each index you want to find the product of every integer except the integer at that index.
Write a function getProductsOfAllIntsExceptAtIndex() that takes an array of integers and returns an array of the products.

For example, given:

  [1, 7, 3, 4]

your function would return:

  [84, 12, 28, 21]

by calculating:

  [7*3*4, 1*3*4, 1*7*4, 1*7*3]

Do not use division in your solution.
*/





var getProductsOfAllIntsExceptAtIndex = function(sub_array) {

	var output_array = [];

	if(sub_array === null || sub_array === undefined) {

		return;

	}


	if(sub_array.length === 0) {
		return output_array;
	}


	//Build product array till before index
	var product_arr = [];

	for(var i = 0; i < sub_array.length; i++) {

		if(i === 0) {
			product_arr[i] = 1;
		} else {

			product_arr[i] = product_arr[i - 1] * sub_array[i - 1];
		}
	}


	var prod_backwards = 1;
	//Now build the result array from backwards
	for(var i = sub_array.length - 1; i >= 0; i--) {

		output_array[i] = prod_backwards * product_arr[i];

			//Prepare product_backwards for next iteration 
			prod_backwards *= sub_array[i];

		}


		return output_array;


	}


// Test cases
console.log(getProductsOfAllIntsExceptAtIndex([1, 7, 3, 4]));
console.log(getProductsOfAllIntsExceptAtIndex([]));
console.log(getProductsOfAllIntsExceptAtIndex([1]));
console.log(getProductsOfAllIntsExceptAtIndex([1, 3]));
console.log(getProductsOfAllIntsExceptAtIndex([1, 3, 5]));


