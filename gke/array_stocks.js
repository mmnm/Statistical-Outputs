/*
Write an efficient function that takes stockPricesYesterday and returns the best profit I could have made from 1 purchase and 1 sale of 1 Apple 
stock yesterday.

For example:

  var stockPricesYesterday = [10, 7, 5, 8, 11, 9];
                                            i                                 
   
                   lsf - 5
                   maxP - 6
                   locS - 


															                            
     O(n2) - Traverse two for loops and update the max_profit with local minima
															 maxProfit

		 Keep track of min seen so far and updateMaxProfit at eqacxh step O(n)




getMaxProfit(stockPricesYesterday);
// returns 6 (buying for $5 and selling for $11)
*/


var getMaxProfit = function(stockPricesYesterday) {

	if(stockPricesYesterday === null) {
		return null;
	}

	var maxProfit = 0;
	var lowestSeenSoFar = stockPricesYesterday[0];
	
	for(var i = 1; i < stockPricesYesterday.length; i++) {

		var curElem = stockPricesYesterday[i];
		if(lowestSeenSoFar > curElem) {
			lowestSeenSoFar = curElem;
		}

		var localMaxSum = curElem - lowestSeenSoFar;

		if(localMaxSum > maxProfit) {
			maxProfit = localMaxSum;
		}

	}

	return maxProfit;

}

// Test cases
var stockPricesYesterday1 = [10, 7, 5, 8, 11, 9];
var stockPricesYesterday2 = [10, 7, 5, 4, 3, 1];
var stockPricesYesterday3 = [1, 5, 7, 8, 9, 11];
console.log(getMaxProfit(stockPricesYesterday1));
console.log(getMaxProfit(stockPricesYesterday2));
console.log(getMaxProfit(stockPricesYesterday3));


