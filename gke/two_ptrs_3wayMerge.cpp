#include <iostream>
#include <vector>
#include <cassert>


class Solution {

public:


std::vector<int> SortColors(std::vector<int> colors) {

    /*  Trace & test your code with multiple examples
        0, 0, 0, 1, 1, 1, 2, 2, 2, 2
              s
                       e
                          c
        c = 3
        0, 1, 1, 2, 0, 2, 0, 2, 1, 2    

    */
    // Initialize start, end and current 
    int start = 0;
    int end = colors.size() - 1;

    //Do this in loop
    for(int current = 0; (current < colors.size()) && (current <= end);) {
        //if current is 0 swap left, if current is 1 skip
        // if current is 2 then swap right
        if(colors[current] == 0) {
            int temp = colors[start];
            colors[start++] = colors[current];
            colors[current] = temp;

            if (colors[current] == 0) {
                current++;
            }
        } else if (colors[current]== 2) {
            int temp = colors[end];
            colors[end--] = colors[current];
            colors[current] = temp;
        } else if(colors[current] == 1){
                current++;
            
        }
    }
    
    
    return colors;
}

};

void runTest(std::vector<int> test, std::vector<int> expected, const std::string& testName) {
    Solution solution;
    std::vector<int> result = solution.SortColors(test);
    assert(result == expected);
    std::cout << testName << " Passed\n";
}

int main() {
    runTest({2, 0, 2, 1, 1, 0}, {0, 0, 1, 1, 2, 2}, "Test Mixed Order");
    runTest({2, 2, 0, 0}, {0, 0, 2, 2}, "Test Two Colors");
    runTest({0, 0, 0}, {0, 0, 0}, "Test Only Zeros");
    runTest({1, 1, 1}, {1, 1, 1}, "Test Only Ones");
    runTest({2, 2, 2}, {2, 2, 2}, "Test Only Twos");
    runTest({}, {}, "Test Empty Vector");
    runTest({0, 1, 2}, {0, 1, 2}, "Test Sorted Input");
    runTest({2, 1, 0}, {0, 1, 2}, "Test Reverse Sorted Input");

    // Large input test
    std::vector<int> largeInput(30000, 0);
    largeInput.insert(largeInput.end(), 30000, 1);
    largeInput.insert(largeInput.end(), 30000, 2);
    std::vector<int> largeExpected(30000, 0);
    largeExpected.insert(largeExpected.end(), 30000, 1);
    largeExpected.insert(largeExpected.end(), 30000, 2);
    runTest(largeInput, largeExpected, "Test Large Random Input");

    std::cout << "All tests passed successfully.\n";
    
    return 0;
}

