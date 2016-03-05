	/*
	Given an arrayOfInts, find the highestProduct you can get from three of the integers.
	The input arrayOfInts will always have at least three integers.

	*/




	var highestProduct = function(sub_array) {

		if(sub_array === null || sub_array === undefined || sub_array.length < 3) {
			return;
		}


		//Logic: Keep track of 1st_high , 2nd_high, 1st_neg_high, 2nd_neg_high, maxProdSeen so far and return that at the end



		var first_high = Number.MIN_VALUE;
		var second_high = Number.MIN_VALUE;
		var first_neg_high = Number.MAX_VALUE;
		var second_neg_high = Number.MAX_VALUE;
		var maxProdSeen = Number.MIN_VALUE;;


		for(var i = 0; i < sub_array.length; i++) {

			var cur = sub_array[i];
			var cur_prod_pos;
			var cur_prod_neg;
			var cur_prod_max;

			if(first_high !== Number.MIN_VALUE && second_high !== Number.MIN_VALUE) {
				cur_prod_pos = first_high * second_high * cur;
			}
			if(first_neg_high !== Number.MAX_VALUE && first_high !== Number.MIN_VALUE) {
				cur_prod_neg = first_neg_high * first_high * cur;
			}

			if(first_neg_high !== Number.MAX_VALUE && second_neg_high !== Number.MAX_VALUE) {

				cur_prod_neg = Math.max((first_neg_high * second_neg_high * cur), cur_prod_neg);
			}

			if (!(cur_prod_pos === undefined) && !(cur_prod_neg === undefined)) {
				
				cur_prod_max = Math.max(cur_prod_pos, cur_prod_neg)

			} else if(!(cur_prod_pos === undefined)) {

				cur_prod_max = cur_prod_pos;

			} else if(!(cur_prod_neg === undefined)) {
				
				cur_prod_max = cur_prod_neg;
			}

			if(maxProdSeen < cur_prod_max) {
				maxProdSeen = cur_prod_max;
			}




			if(cur < 0) {
				if(first_neg_high >= cur) {
					second_neg_high = first_neg_high;
					first_neg_high = cur;
				}

			} else if(cur > 0) {
				if(first_high <= cur) {
					second_high = first_high;
					first_high = cur;
				}
			}


		}

		return maxProdSeen;


	}



	  var arrayOfInts = [1, 10, -5, 1, -100];
	var array2 = [-10, -10, 1, 3, 2];



	  console.log(highestProduct(arrayOfInts));
	  console.log(highestProduct(array2));