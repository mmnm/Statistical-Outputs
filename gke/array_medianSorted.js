/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
//  debugger;
    if(nums1 === null && nums2 === null) {
        return null;
    }
        
    
    var total_len = nums1.length + nums2.length;
    var median_index = [];
    if(total_len % 2 === 0) {
        var index1 = parseInt((total_len / 2) - 1);
        var index2 = index1 + 1;
        median_index.push(index1, index2);
    } else {
        median_index.push(parseInt(total_len / 2));
    }
    var median = null;
    if(nums1.length === 0) { 
        if(median_index.length === 1) {
            return nums2[median_index[0]];
        } else {
            median = (nums2[median_index[0]] + nums2[median_index[1]]) / 2;
        }
    }

    if(nums2.length === 0) { 
        if(median_index.length === 1) {
            return nums1[median_index[0]];
        } else {
            median = (nums1[median_index[0]] + nums1[median_index[1]]) / 2;
        }
    }
    
    if(median !== null) { 
        return median;
    }
    
    return mergedListsMedian(nums1, nums2, median_index);

};

var mergedListsMedian = function(nums1, nums2, median_index) {
    
    var output_arr = [];
    var last_index_needed = median_index[median_index.length - 1];
    
    for(var i = 0, j = 0; i < nums1.length || j < nums2.length;) {
        
        if(i < nums1.length && j < nums2.length) {
            if(nums1[i] < nums2[j]) {
                output_arr.push(nums1[i++]);
            } else {
                output_arr.push(nums2[j++]);
            }
        } else if(i < nums1.length) {
            output_arr.push(nums1[i++]);
        } else if(j < nums2.length) {
            output_arr.push(nums2[j++]);
        }
    
        if(output_arr.length - 1 >= last_index_needed) {
            break;
        }
    }
    
    var median = 0;
    
    if(median_index.length === 1) {
            return output_arr[median_index[0]];
        } else {
            // debugger;
            var index1_elem = output_arr[median_index[0]];
            var index2_elem = output_arr[median_index[1]];
            median = (index1_elem + index2_elem) / 2;
            return median;
        }
   
    
}

nums1 = [1, 2]
nums2 = [3, 4]

console.log(findMedianSortedArrays(nums1, nums2));

nums1 = [1, 3]
nums2 = [2]

console.log(findMedianSortedArrays(nums1, nums2));

