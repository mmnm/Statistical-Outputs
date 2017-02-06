/* 

Suppose we could access yesterday's stock prices as an array, where:

The indices are the time in minutes past trade opening time, 
which was 9:30am local time.
The values are the price in dollars of Apple stock at that time.
So if the stock cost $500 at 10:30am, stockPricesYesterday[60] = 500;.

Write an efficient function that takes stockPricesYesterday 
and returns the best profit I could have made from 1 purchase 
and 1 sale of 1 Apple stock yesterday.

For example:

  var stockPricesYesterday = [10, 7, 5, 8, 11, 9];
                                                
                maxSeen = -1;


In O(n) time 

[10, 7, 5, 8, 11, 9];

minSeenTillNow 
maxSeen

getMaxProfit(stockPricesYesterday);
// returns 6 (buying for $5 and selling for $11)

*/



/* The below solution is O(n*n)*/

var maxProfit = function(stockPricesYesterday) {

	if(stockPricesYesterday === null) {
		return;
	}

	if(stockPricesYesterday.length <= 1) {
		return -1;
	}
	var maxSeen = Number.MIN_SAFE_INTEGER;

	for(var i = 0; i < stockPricesYesterday.length - 1; i++) {
		for(var j = i + 1; j < stockPricesYesterday.length; j++) {

				var curProfit = stockPricesYesterday[j] - stockPricesYesterday[i];

			if(maxSeen < curProfit) {

				maxSeen = curProfit;
			}
		}
	}

	return maxSeen;



}



/* The below solution is O(n*n)*/

var maxProfitOptimized = function(stockPricesYesterday) {

	if(stockPricesYesterday === null) {
		return null;
	}
	if(stockPricesYesterday.length <= 1) {
		return -1;
	}

	var minSeenTillNow = stockPricesYesterday[0];
	var globalMax = Number.MIN_SAFE_INTEGER;

	for(var i = 1; i < stockPricesYesterday.length; i++) {
		var curProfit = stockPricesYesterday[i] - minSeenTillNow;

		if(globalMax < curProfit) {
			globalMax = curProfit;
		}
		if(minSeenTillNow > stockPricesYesterday[i]) {
			minSeenTillNow = stockPricesYesterday[i];
		}

	}

	return globalMax;

}



//Test cases
console.log(maxProfit([10, 7, 5, 8, 11, 9]));
console.log(maxProfit([10, 7, 5, 3, 2, 0]));




//Test cases
console.log(maxProfitOptimized([10, 7, 5, 8, 11, 9]));
console.log(maxProfitOptimized([10, 7, 5, 3, 2, 0]));




