// Overlapping intervals
                                                                  
// // [[1, 3], [2, 9], [10, 11]] => [[1, 9], [10, 11]] => 
//      i  j    k l     m n 
//      1 - 3   2 - 9   1  9  10 11 
//      2 - 3   2 - 9    
//      3 - 5   2 -9    2 - 9
     
     

    
var mergeOverlapPoints = function(x1,y1,x2,y2) {
    

    var max = Math.max(x1,y1,x2,y2);
    var min = Math.min(x1,y1,x2,y2);
    var out_inter = [];
    out_inter.push(min,max);
    return out_inter;

}

var merge_overlap_possible = function(array1, array2) {
    
    var x1 = array1[0];
    var x2 = array1[1];
    var x3 = array2[0];
    var x4 = array2[1];
    
    if( (x1 < x3) && (x2 < x3) ) {
        return false;
    } 
    return true;
}




var returnMeMergedIntervals = function(input_array) {
    
    if(input_array === null) {
        return;
    }

    
    //Assume sorted
    input_array.sort(function(interval1, interval2) { return interval1[0] - interval2[0];});

    for(var i = 0; i < input_array.length - 1; i++) {
        
        var cur_set = input_array[i];
        
        for(var j = i + 1; j < input_array.length; j++) {
        
            var try_set = input_array[j];
            if(!merge_overlap_possible(cur_set, try_set)) {
                break;
            }
            cur_set = input_array[i] = mergeOverlapPoints(cur_set[0], cur_set[1], try_set[0], try_set[1]);
            input_array.splice(j,1);
            j = j - 1;

        }
        
    }

    return input_array;
    
    
}

console.log(returnMeMergedIntervals([[1, 3], [2, 9], [2, 7],  [10, 11]]));
console.log(returnMeMergedIntervals([[1, 3], [2, 9], [10, 11]]));


