			// Find kth smallest element in the array
			// Input: [2,5,1,9,6,3,8,10,4,7], 4
			// Output: 4


			// My algo is to do randomized Quicksort partioning routine
			// Time complexity O(n)


			var swap = function(arr, index1, index2) {

				var temp = arr[index1];
				arr[index1] = arr[index2];
				arr[index2] = temp;

			}

			var randomizePivot = function(arr, start , end) {

				var index = Math.floor((Math.random() * end) + start);
				if(index > end || index < start) {
					return;
				}
				swap(arr, start, index);

			}


			var partition = function(arr, start, end) {

				
				if(start >= end) {
					return;
				}

				randomizePivot(arr, start, end);

				var pivotElem = arr[start];

				var i = start;
				for(var j = start + 1; j <= end; j++) {

					if(arr[j] < pivotElem) {
						swap(arr, i + 1, j);
						i++;
					}

				}

				//Last swap is with pivot
				swap(arr, i, start);
				return i;

			}



			var QuickSelectUtil = function(arr, k, start, end) {

				if(start > end || arr === null) {
					return NaN;
				}

				var pivotIndex = partition(arr, start, end);
				if(pivotIndex === (k - 1)) {
					return arr[pivotIndex];

				} else if( pivotIndex > (k - 1)) {
					
					return QuickSelectUtil(arr, k, start, pivotIndex - 1);

				} else {
					
					return QuickSelectUtil(arr, k, pivotIndex + 1, end);
				}


			}

			var QuickSelect = function(arr, k) {

				if(arr === null || k > arr.length) {
					return NaN;
				}


				return QuickSelectUtil(arr, k , 0, arr.length - 1);

			}

			//Tests 
			// console.log(QuickSelect([2,5,1,9,6,3,8,10,4,7], 1));
			// console.log(QuickSelect([2,5,1,9,6,3,8,10,4,7], 2));
			// console.log(QuickSelect([2,5,1,9,6,3,8,10,4,7], 3));
			// console.log(QuickSelect([2,5,1,9,6,3,8,10,4,7], 4));
			// console.log(QuickSelect([2,5,1,9,6,3,8,10,4,7], 5));
			// console.log(QuickSelect([2,5,1,9,6,3,8,10,4,7], 6));
			// // console.log(QuickSelect([2,5,1,9,6,3,8,10,4,7], 7));
			// // console.log(QuickSelect([2,5,1,9,6,3,8,10,4,7], 8));
			// // console.log(QuickSelect([2,5,1,9,6,3,8,10,4,7], 9));
			console.log(QuickSelect([2,5,1,9,6,3,8,10,4,7], 10));
			// console.log(QuickSelect([2,5,1,9,6,3,8,10,4,7], 11));




