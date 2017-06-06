/**
 * @param {character[][]} board
 * @return {boolean}
 */

/**
 * @param {character[][]} board
 * @return {boolean}
 */

    
  var isValidSudoku = function(board) {
    
    if(board === null) {
        return false;
    }
    
    var rows = board.length;
    var cols = board[0].length;

    
    //Rows hash
    var hashRows = [];
    for(var i = 0; i < rows; i++) {
        hashRows[i] = {};
    }
       //Cols hash
    var hashCols = [];
    for(var i = 0; i < cols; i++) {
        hashCols[i] = {};
    }
    //Grid hash
    var gridHash = [[]];
    for(var i = 0; i < 3; i++) {
        gridHash[i] = [];
        for(var j = 0; j < 3; j++) {
            gridHash[i][j] = {};
        }
    }
    
    // gridHash[0][0]['6'] = true;
    // if('8' in gridHash[0][0])
    //     {console.log("Yayyy");}

    var isValid = true;
    
    for(var i = 0; i < rows; i++) {
        
        for(var j = 0; j < cols; j++) {
            var curElem = board[i][j];
            
            if(curElem === '.') {
                //Skip
                continue;
            }
            
            //Check in rows
            if(curElem in hashRows[i]) {
                isValid = false;
                break;
            } 
            //Check in cols
            if(curElem in hashCols[j]) {
                isValid = false;
                break;
            }

            var gridRow = parseInt(i / 3);
            var gridCol = parseInt(j / 3);
            
            if(gridHash[gridRow][gridCol][curElem]) {
                isValid = false;
                break;
            }
         
            //Now put the elem in rowHash, colHash, gridHash
            hashRows[i][curElem] = true;
            hashCols[j][curElem] = true;
            gridHash[gridRow][gridCol][curElem] = true;
        }
   
    }
    
    return isValid;
    
    
    
    
};




var sudokuboard = 
[".87654321","2........","3........",
"4........","5........","6........",
"7........","8........","9........"];


console.log(isValidSudoku(sudokuboard));


var sudokuboard1 = 
[".87854321","2........","3........",
"4........","5........","6........",
"7........","8........","9........"];


console.log(isValidSudoku(sudokuboard1));

var sudokuboard2 = 
[".87854321","2........","3........",
"4........","5........","6........",
"7........","8........","9........"];


console.log(isValidSudoku(sudokuboard2));

