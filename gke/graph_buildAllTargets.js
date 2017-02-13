// each key is a build target
// each value is the list of other targets that this target depends on
//if target doesnt exist in depMap, then there is no depedency to build it
var depMap = { 
              "a" : [ "b", "c"],
              "b" : [ "c", "d"],
             "c" : [ "d", "e", "f"],
              "j" : [ "k" ],
              "m": ["l", "o"],
              "o": ["p","q"],
              "q": ["s"]
             }


//Valid build order

/* 
Given list should build for all
The below algo does dfs traversal and creates a list of resolves
Since it is put in the key - value it has to go through the list 
to check if all targets are resolved


*/




var validBuildOrderUtil = function(depMap, startPoint, isVisited) {

	if(depMap === null) {
		return null;
	}
	if(startPoint === null) {
		return [];
	}


	//Remember to remove duplicate entries

	var answer = [];
	if(startPoint in isVisited) {
		//Skip this entry
		return answer;
	}
	answer.push(startPoint);
	isVisited[startPoint] = true;

	//Traverse the dependecy chain starting with first key itself

	
	if(!(startPoint in depMap)) {
		return answer;
	}

	//Follow startPoint dependency chain 
	var startPointChain = depMap[startPoint];

	for(var i = 0; i < startPointChain.length; i++) {
		answer = answer.concat(
			validBuildOrderUtil(depMap, startPointChain[i], isVisited));
	}

	return answer;

}

var validBuildOrder = function(depMap, startPoint, isVisited) {

	var valid_order = validBuildOrderUtil(depMap, startPoint, isVisited);
	return reverseOrder(valid_order);


}



var buildAllTargets = function(depMap) {

		if(depMap === null) {
			return null;
		}

		var unbuiltTargets = {};

		//Create a hash for unbuilt target
		for(var key in depMap) {
			unbuiltTargets[key] = true;
		}



		if(Object.keys(unbuiltTargets).length === 0) {
			return [];
		}

		var isVisited = {};
		var builtTargets = [];
		while(Object.keys(unbuiltTargets).length > 0) {
			//Getting first entry
		var start = Object.keys(unbuiltTargets)[0];

		builtTargets = builtTargets.concat(
										(validBuildOrder(depMap, start, isVisited)));
		//Update unbuilt targets to reflect the remaining unbuilt
		unbuiltTargets = updateUnbuiltTargets(unbuiltTargets, builtTargets);

 
 		}

 		return builtTargets;
 	
};


var updateUnbuiltTargets = function(unbuiltTargets, builtTargets) {

	//unbuiltTargets is a hash Object and builtTargets is an array

	if(unbuiltTargets === null || builtTargets === null) {
		return unbuiltTargets;
	}

	for(var i = 0; i < builtTargets.length; i++) {
		var curElem = builtTargets[i];
		if(curElem in unbuiltTargets) {
			delete unbuiltTargets[curElem];
		}
	}

	return unbuiltTargets;

}


var reverseOrder = function(sub_arr) {

	if(sub_arr === null) {
		return 0;
	}

	var output_arr = [];
	for(var i = 0; i < sub_arr.length; i++) {
		output_arr[sub_arr.length - 1 - i] = sub_arr[i];
	}

	return output_arr;

}

var isVisited = {};
console.log(validBuildOrder(depMap, "a", isVisited));

console.log(buildAllTargets(depMap));














