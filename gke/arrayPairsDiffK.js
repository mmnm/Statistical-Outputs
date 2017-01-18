/* Given a pair of distinct integer values, count the 
number of pairs that have difference k

e.g, 
Input: [1,7,5,9,2,12,3], 2
Output: 4

Soln 1: The simple naive soln is to traverse each elem and check all other
elems for cur + k being equal to them and incrementing count
T = O(n*n)

Soln 2: If we sort, then can make the soln O(nlogn) + O(1)

Soln 3: If we use hash
    a) In two passes: First pass create hash, 2nd pass traverse and check 
    curElem + k already in hash , then increment count
    b) In one pass: For each elem, check if elem + k and elem - k  
     exists in hash
    If yes, increase count. Put elem in hash 
*/



var countNumberOfPairsOnePass = function(sub_arr, k) {

	if(sub_arr === undefined || sub_arr === null || k <= 0) {
		return null;
	}
	

	var hashPairSeen = {};

	var pairs = 0;

	for(var i = 0; i < sub_arr.length; i++) {

		var curElem = sub_arr[i];

		if((curElem + k) in hashPairSeen) {
			pairs++;
		}

		if((curElem - k) in hashPairSeen) {
			pairs++;
		}

		if(!(curElem in hashPairSeen)) {
			hashPairSeen[curElem] = true
		}

	}

	return pairs;

}

console.log(countNumberOfPairsOnePass([1,7,5,9,2,12,3], 2));

