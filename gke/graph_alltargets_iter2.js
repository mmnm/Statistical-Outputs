// each key is a build target
// each value is the list of other targets that this target depends on
//if target doesnt exist in depMap, then there is no depedency to build it



//Valid build order

/* 
Given list should build for all
The below algo does dfs traversal and creates a list of resolves
Since it is put in the key - value it has to go through the list 
to check if all targets are resolved


*/


var depMap = { 
							"j" : [ "k" ],
              "a" : [ "b", "c"],
              "b" : [ "c", "d"],
             "c" : [ "d", "e", "f"],
              "m": ["l", "o","j"],
              "o": ["p","q"],
              "q": ["s"]
             }




var buildTarget = function(depMap, target, isVisited) {

var build_arr = [];

	if(target === null || depMap === null || isVisited === null) {
		return build_arr;
	}

	if(target in isVisited) {
		if(isVisited[target] === true) {
			return build_arr;
		}
	} else {
		isVisited[target] = true;
	}

	var target_list = [];

	if(target in depMap) {
		target_list = depMap[target];
	}

	for(var i = 0; i < target_list.length; i++) {
		build_arr = build_arr.concat
		(buildTarget(depMap, target_list[i], isVisited));
	}

	build_arr.push(target);
	return build_arr;


}




var buildTarget_0331 = function(depMap, target, isVisited) {

	var dep_list = [];
	var built_order = [];


	if(depMap === null || target === null) {
		return dep_list;
	}

	if(target in isVisited) {
		if(isVisited[target] === true) {
			return built_order;
		}
	} else {
		isVisited[target] = true;
	}


	if(target in depMap) {
		dep_list = depMap[target];
	}

	for(var i = 0; i < dep_list.length; i++) {
		var curElem = dep_list[i];
		built_order = built_order.concat(buildTarget_0331(depMap, curElem, isVisited))
		
	}

	built_order.push(target);
	return built_order;
}


var buildAllTargets = function(depMap) {

	var isVisited = {};

	//Process depMap targets

	var allBuiltOrder = [];

	for(var key in depMap) {
		console.log("Cur processing key: ", key);
		
		if(key in isVisited) {
			if(isVisited[key] === true) {
				
				//Skip this target
				continue;
			}
		} 
    
    allBuiltOrder = allBuiltOrder.concat
    											(buildTarget_0331(depMap, key, isVisited));

	}

	return allBuiltOrder;

}


console.log(buildTarget(depMap, "a", {}));
console.log(buildTarget_0331(depMap, "a", {}));
console.log(buildAllTargets(depMap));














