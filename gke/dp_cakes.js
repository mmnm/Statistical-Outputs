//Cake problem
// /  var cakeTypes = [
//     {weight: 7, value: 160},
//     {weight: 3, value: 90},
//     {weight: 2, value: 15},
// ];

// var capacity = 20;

// maxDuffelBagValue(cakeTypes, capacity);
// // returns 555 (6 of the middle type of cake and 1 of the last type of cake)






var maxDuffelBagValue = function(cakeTypes, capacity) {


	if(cakeTypes === null || cakeTypes === undefined) {
		return;
	}

	if(capacity <= 0) {
		return 0;
	}


	var capacity_arr_value = [];



	for(var i = 0; i <= capacity; i++) {

		capacity_arr_value[i] = 0;

	}

	// debugger;
	for(var i = 0; i <= capacity; i++) {

		var curMaxValue = 0;

		for(var j = 0; j < cakeTypes.length; j++) {

			
			var curWeight = i - cakeTypes[j]["weight"];
			var curCakeValue = 0;
			if(curWeight >= 0) {
					//It is possible to take the current cake

					curCakeValue = cakeTypes[j]["value"] + capacity_arr_value[i - cakeTypes[j]["weight"]];

				}

				curMaxValue = Math.max(curMaxValue, curCakeValue);
			}

			capacity_arr_value[i] = curMaxValue;


		}


		return capacity_arr_value[capacity];

	}



	var cakeTypes = [
	{weight: 7, value: 160},
	{weight: 3, value: 90},
	{weight: 2, value: 15},
	]; 
	var capacity = 20;


	console.log(maxDuffelBagValue(cakeTypes, capacity));


