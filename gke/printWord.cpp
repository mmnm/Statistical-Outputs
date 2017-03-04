#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

/*

Debugging tips:

1. Please ensure that while in recursion, you should take care of empty 
	inputs and what it characterizes for your algo
 E.g, 

 Ln96   if(orig.length() == 0)
        {
                return true;
        }

Consider the following dictionary 
{ i, like, sam, sung, samsung, mobile, ice, 
  cream, icecream, man, go, mango};

*/



bool is_in_dictionary(string test, std::map<string, bool> &hash)
{
	if(hash.size() == 0)
	{
		return false;
	}

	std::map<string, bool>::iterator it;

	it = hash.find(test);
	
	if(it != hash.end())
	{
		//Found entry in dictionary
		return true;
	}
	else 
	{
		return false;
	}

}	



void initialize_dictionary(std::map<string, bool> &dict)
{
	dict["i"] = true;
	dict["love"] = true;
	dict["like"] = true;
	dict["sam"] = true;
	dict["and"] = true;
	dict["sung"] = true;
	dict["samsung"] = true;
	dict["mobile"] = true;
	dict["ice"] = true;
	dict["cream"] = true;
	dict["icecream"] = true;
	dict["man"] = true;
	dict["go"] = true;
	dict["mango"] = true;



}

void print_vector(std::vector<string> &words)
{
	std::vector<string>::iterator it;

	cout<<endl;
	for(it = words.begin(); it != words.end(); it++)
	{
		cout<<" "<<*it;
	}
	cout<<endl;
}

bool word_break(std::map<string, bool> &dict, 
		std::vector<string> &words, string orig)
{
	
	if(dict.size() == 0)
	{
		return false;
	}

	if(orig.length() == 0)
	{
		return true;
	}	

	for(int i = 0; i < orig.length(); i++)
	{
		std::string prefix = orig.substr(0, i + 1);
		std::string suffix = orig.substr(i + 1);
		//cout<<"prefix and suffix: "<<prefix<<"+ "<<suffix<<endl; 		

		if(is_in_dictionary(prefix, dict))
		{	

			cout<<"Prefix is in dict: " <<prefix<<endl;
			if(word_break(dict, words, suffix))
			{
				cout<<"Finally"<<endl;
				words.push_back(prefix);
				return true;
			}
		}
	}

	return false;
}

	

int main()
{
	std::map<string, bool> dict;
	std::vector<string> words;

	//Initialize dictionary

	initialize_dictionary(dict);

	word_break(dict, words, "iloveicecreamandmango");

	print_vector(words);

	return 0;
}
	






