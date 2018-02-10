/**
 * @param {string[]} paths
 * @return {string[][]}
 */

/*
What will hash look like 

abcd: ["root/a/1.txt", "root/c/3.txt"]
fghi: []

*/


//"root/a 1.txt(abcd) 2.txt(efgh)"
//Deubugging mistake: Make sure any “prev” values in general are updated correctly in the loop

var extractElemsWithSpace = function(curElem) {
    var output = [];
    
    var prev_space_index = -1;
    
    for(var i = 0; i < curElem.length; i++) {
        
            //Last element
        if(i === curElem.length - 1) {
            var cur = curElem.substr(prev_space_index + 1);
            output.push(cur);
            
        } else if(curElem[i] === " ") {
            
            if(prev_space_index === -1) {
                var cur = curElem.substr(0, i)
            } else {
                var cur = curElem.substr(prev_space_index + 1, i - 1 - prev_space_index);
            }
            prev_space_index = i;
            output.push(cur);
        }
        
    }
    
    return output;
}
//input params: ["abcd", "1.txt"], {}, "root/a"
var processHash = function(cur, hash, dir_name) {
    //hash, value
    //Error checks
    
    var curKey = cur[0];
    var curVal = cur[1];
    curVal = dir_name + "/" + curVal;
    
    var values = [];
    if(curKey in hash) {
        values = hash[curKey];
    }
    values.push(curVal);
    hash[curKey] = values;
 
};
//Output: ["abcd", "1.txt"]
//Input: 1.txt(abcd)
var splitHash = function(elem) {
    
    var output = [];
    for(var i = 0; i < elem.length; i++) {
        
        if(elem[i] === "(") {
            //hash begins
            break;
        }
    }
    var len = elem.length;
    var hash = elem.substr(i + 1, len - 1 - i);
    var value = elem.substr(0, i);
    output.push(hash);
    output.push(value);
    return output;
    
}

var processHashFiles = function(input, hash) {
    
    if(input.length === 0) {
        return;
    }
    
    var process_elems = extractElemsWithSpace(input);
    
    //Dir name will be the first placed
    var dir_name = process_elems[0];
    //Delete Dir name from array
    process_elems.splice(0, 1);

    for(var i = 0; i < process_elems.length; i++) {
        //1.txt(abcd)
        var curElem = process_elems[i];
        curElem = splitHash(curElem);
        processHash(curElem, hash, dir_name);
    }  
};

var groupHashElems = function(hashDir) {
    
    var output = [];
    
    for(var key in hashDir) {
        var values = hashDir[key];
        if(values.length > 1) {
            output.push(values);
        }
    }
    return output;
}

var findDuplicate = function(paths) {
    
    //Process all files as hashes
    //Group the files together
    if(paths.length === 0) {
        return [];
    }
    var hashDir = {};
    for(var i = 0; i < paths.length; i++) {
        
        var curElem = paths[i];
        processHashFiles(curElem, hashDir);    
    }

    return groupHashElems(hashDir);
    
};

console.log(findDuplicate(["root/a 1.txt(abcd) 2.txt(efgh)", 
    "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]));