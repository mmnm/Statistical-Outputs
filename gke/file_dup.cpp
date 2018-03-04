/* 
Input:
["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
Output:  
[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
//root/a/2.txtroot/c/d/4.txtroot/4.txtroot/a/1.txtroot/c/3.txt
1. 
Process the input to point like below

abcd: path1, path3
efgh: path4

2. Return output by groups

*/

/* Debugging Learnings
1. Be vary of variable names and spelling mistakes.
E.g, use "filePath" throughout instead of "filepath" for "string filePath" declaration
2. Always validate the extraction example of your word.substr usage
E.g, extracted "abcd)" is wrong extraction and "abcd" is right from "2.txt(efgh)"

1. Imagine you are given a real file system, how will you search files? DFS or BFS ?
In general, BFS will use more memory then DFS. However BFS can take advantage of the locality of files in inside directories, and therefore will probably be faster

2. If the file content is very large (GB level), how will you modify your solution?
In a real life solution we will not hash the entire file content, since it’s not practical. Instead we will first map all the files according to size. Files with different sizes are guaranteed to be different. We will than hash a small part of the files with equal sizes (using MD5 for example). Only if the md5 is the same, we will compare the files byte by byte

3. If you can only read the file by 1kb each time, how will you modify your solution?
This won’t change the solution. We can create the hash from the 1kb chunks, and then read the entire file if a full byte by byte comparison is required.

What is the time complexity of your modified solution? What is the most time consuming part and memory consuming part of it? How to optimize?
Time complexity is O(n^2 * k) since in worse case we might need to compare every file to all others. k is the file size

How to make sure the duplicated files you find are not false positive?
We will use several filters to compare: File size, Hash and byte by byte comparisons.


*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <string> 


using namespace std;

class Solution {
public:
    vector<vector<string> > findDuplicate(vector<string>& paths) {
        
        std::unordered_map<string, vector<string> > contentHash;
        std::unordered_map<string, vector<string> >::iterator it;
        vector<vector<string> > results;
        
        for(int i = 0; i < paths.size(); i++) 
        {
            string curElem = paths[i];
            stringstream ss(curElem);
            
            string filePath;
            string word;
            
            //Process each path string 
            while(ss >> word)
            {
                if(filePath.length() == 0) 
                {
                    //filepath = "root/a"
                    filePath = word;
                    continue;
                }
                
                //word = 2.txt(efgh)
                int index_c = word.find('(');
                
                //content = "efgh"
                string content = word.substr(index_c + 1);
                //Remove last ")"
                content = content.substr(0, content.size() - 1);
                //curFileName = "2.txt"
                string curFileName = word.substr(0, index_c);
                //Process hash now
                string curFilePath = filePath + "/" + curFileName;
                contentHash[content].push_back(curFilePath);
            }
        }
        //abcd: path1, path3
        for(it = contentHash.begin(); it != contentHash.end(); it++)
        {
            if((it->second).size() > 1)
            {
                results.push_back(it->second);
            }
        }
        return results;

    }
};

void printStringVector(vector<string> input)
{
    vector<string>::iterator it;
    cout<<endl;
    for(it = input.begin(); it != input.end(); it++)
    {
        cout<<" "<<*it;
    }

    cout<<endl;
}
void printOutputVector(vector<vector<string> > output)
{
    vector<vector<string> >::iterator it;

    for(it = output.begin(); it != output.end(); it++)
    {
        cout<<endl;
        printStringVector(*it);
        cout<<endl;
    }


}

int main(int argc, char const *argv[])
{
    //Test case 1
    vector<string> input1;
    input1.push_back("root/a 1.txt(abcd) 2.txt(efgh)");
    input1.push_back("root/c 3.txt(abcd)");
    input1.push_back("root/c/d 4.txt(efgh)");
    input1.push_back("root 4.txt(efgh)");
    Solution moduleA;

    vector<vector<string> > output = moduleA.findDuplicate(input1);
    printOutputVector(output);

    return 0;
}
