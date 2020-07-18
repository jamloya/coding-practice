/*
	An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:
	
	a) it                      --> it    (no abbreviation)
	
	     1
	b) d|o|g                   --> d1g
	
	              1    1  1
	     1---5----0----5--8
	c) i|nternationalizatio|n  --> i18n
	
	              1
	     1---5----0
	d) l|ocalizatio|n          --> l10n
	Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
	
	Example: 
	
	Given dictionary = [ "deer", "door", "cake", "card" ]
	
	isUnique("dear") -> false
	isUnique("cart") -> true
	isUnique("cane") -> false
	isUnique("make") -> true
*/

#include<bits/stdc++.h>

using namespace std;

class TreeNode
{
 public:
	  int val;
	  TreeNode *left,*right;

 TreeNode(int value) : val(value),left(nullptr),right(nullptr){}
};

class Solution{
public:
	   Solution(vector<string> words){
	   		for(auto word:words)
	   			if(word.size()<3)
	   				abbreviations.insert(word);
	   			else
	   				abbreviations.insert(getAbbreviation(word));
	   }
	   
	   string getAbbreviation(string word)
	   {
	   		return word[0]+to_string(word.size()-2)+word.back();
	   }
	   
	   //function prototype here
	   bool isUnique(string word)
	   {
	   		return word.size()<3?abbreviations.find(word)==abbreviations.end():abbreviations.find(getAbbreviation(word))==abbreviations.end();
	   }
	   
private:
	unordered_set<string> abbreviations;
};

int main()
{
	 vector<string> words{ "deer", "door", "cake", "card"};
	 Solution s(words);
	 clock_t t;
	 t=clock();
	 cout<<s.isUnique("dear")<<endl;
	 cout<<s.isUnique("cart")<<endl;
	 cout<<s.isUnique("cane")<<endl;
	 cout<<s.isUnique("mane")<<endl;
	 
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

