        /*

        Write a function condenseMeetingTimes() that takes an array of meeting time ranges and returns an array of condensed ranges.

        For example, given:

          [
            {startTime: 0,  endTime: 1},
            {startTime: 3,  endTime: 5},
            {startTime: 4,  endTime: 8},
            {startTime: 10, endTime: 12},
            {startTime: 9,  endTime: 10},
        ]

        your function would return:

          [
            {startTime: 0, endTime: 1},
            {startTime: 3, endTime: 8},
            {startTime: 9, endTime: 12},
        ]



        */


        //Expects array intervals as input of format [x1, x2]
        var mergeOverlaps = function(interval1, interval2) {

            if(interval1 === undefined || interval2 === undefined) {
                return;
            }

            var mergedInterval = [];
            var low = Math.min(interval1[0], interval1[1], interval2[0], interval2[1]);
            var high = Math.max(interval1[0], interval1[1], interval2[0], interval2[1]);
            mergedInterval.push(low, high);

            return mergedInterval;

        }

        var condenseMeetingTimes = function(time_objects) {


            if(time_objects === null || time_objects === undefined) {
                
                return time_objects;
            }

            //If there is only 1 interval, return as is
            if(time_objects.length === 1) {
                return time_objects;
            }


            //Reduce the object to interval_array
            var interval_array = [];


            for(var i = 0; i < time_objects.length; i++) {
                var curElem = time_objects[i];

                var curInterval = [];
                curInterval.push(curElem["startTime"], curElem["endTime"]);
                interval_array.push(curInterval);

            }

            //Now we merge all overlapping intervals after sorting it based on the start time

            interval_array.sort(function(interval1, interval2) {
                return interval1[0] - interval2[0];
            });


            

            //Algo: (x1, x2); (x3, x4) :   if(x2 < x3) //no overlap possible , else merge

            var prev_elem = interval_array[0];
            var mergedArray = [];

            for(var i = 1; i < interval_array.length; i++) {

                var curElem = interval_array[i];

                //Merge this interval if overlap possible
                if(prev_elem[1] >= curElem[0]) {
                    prev_elem = mergeOverlaps(prev_elem, curElem);
                    
                    //Edge case - Last elem
                    if(i === interval_array.length - 1) {
                        mergedArray.push(prev_elem);
                    }

                } else {
                    mergedArray.push(prev_elem);
                    prev_elem = curElem;

                }

            }   
            

            //Now output in the interval format of objects
            var outputObj = [];
            for(var i = 0; i < mergedArray.length; i++) {
                var curElem = mergedArray[i];
                var curObj = {};
                curObj["startTime"] = curElem[0];
                curObj["endTime"] = curElem[1];
                
                outputObj.push(curObj);

            }


            return outputObj;


        }



//Test cases
var testArr =   [
{startTime: 0,  endTime: 1},
{startTime: 3,  endTime: 5},
{startTime: 4,  endTime: 8},
{startTime: 10, endTime: 12},
{startTime: 9,  endTime: 10},
];

var testArr2 =   [{startTime: 1, endTime: 2}, {startTime: 2, endTime: 3}];
var testArr3 =   [{startTime: 1, endTime: 5}, {startTime: 2, endTime: 3}];
var testArr4 =   [
{startTime: 1, endTime: 10},
{startTime: 2, endTime: 6},
{startTime: 3, endTime: 5},
{startTime: 7, endTime: 9},
];

console.log(condenseMeetingTimes(testArr));
console.log(condenseMeetingTimes(testArr2));
console.log(condenseMeetingTimes(testArr3));
console.log(condenseMeetingTimes(testArr4));

