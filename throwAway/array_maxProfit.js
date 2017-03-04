/* 
Write an stockPricesYesterday and returns the best profit 

For example:

  var stockPricesYesterday = [10, 7, 5, 8, 11, 9];

getMaxProfit(stockPricesYesterday);
// returns 6 (buying for $5 and selling for $11)

minseen = 5

[10, 7, 5, 8, 11, 9]
                  i  
	maxS = 6


*/


var getMaxProfit = function(sub_arr) {

	if(sub_arr === null) {
		return 0;
	}

	if(sub_arr.length <= 1) {
		return 0;
	}

	var maxSum = Number.MIN_SAFE_INTEGER;
	var minSeen = sub_arr[0];

	for(var i = 1; i < sub_arr.length; i++) {

		var curProfit = sub_arr[i] - minSeen;

		if(maxSum < curProfit) {
			maxSum = curProfit;
		} 

		//Update minSeen
		if(sub_arr[i] < minSeen) {
			minSeen = sub_arr[i];
		}

	}

	return maxSum;

}

console.log(getMaxProfit([10, 7, 5, 8, 11, 9]));
console.log(getMaxProfit([10, 7, 5, 3, 1]));

