#include "grammar_processor.h"
#include <stdexcept>
#include <map>
#include "my_string_lib.h"
#include <cstdlib>
#include <ctime>

using std::vector;
using std::string;
using std::map;
using std::istream;
using std::domain_error;
using std::logic_error;

typedef vector<string> Rule_Body;
typedef vector<Rule_Body> Rule_Body_Collection;
typedef map<string, Rule_Body_Collection > Grammar;

vector<string> generate_sentence(const Grammar &, const string &);


//this function reads in a grammar from the istream as well as the start_tag (eg. <sentence>).  See grammar.txt for example grammar.
//
//This function outputs a vector<string> that represents the random sentenct
vector<string> create_sentence_from_grammar(istream & in, const string & start_tag){
	std::srand(time(NULL));

	if(!in)
		throw domain_error("Unable to read from input stream.");

	string line;
	Grammar g;

	while(std::getline(in, line)){
		vector<string> split_line = split_string_to_words(line);


		//There should be at least two words per line.  an empty line is fine and will be ignored.
		if(!split_line.empty()){
			if(split_line.size() == 1)
				throw domain_error("Rule " + split_line[0] + " does not have a definition!");

			//add the new rule to the grammar
			g[split_line[0]].push_back(vector<string>(split_line.begin() + 1, split_line.end()));
		}
	}

	in.clear();

	vector<string> resulting_sentence = generate_sentence(g, start_tag);
	return resulting_sentence;
}

//pseudo random number generator that will return a number in the range [0, n)
//useful for generating a random index of array.
int nrand(int n){
	int bucket_size = RAND_MAX / n;
	int r;
	do r = std::rand() / bucket_size;
	while(r >= n);

	return r;
}

//returns a bool that indicates whether or not 'word' is surrounded by '<' and '>'
bool bracketed(const string & word){
	return word.size() != 0 && word[0] == '<' && word[word.size() - 1] == '>';
}


//Rule_Body_Collection == vector<Rule_Body>
//this function simply returns a random rule_body from a number of rule_bodys
Rule_Body get_random_rule_body_from_collection(const Rule_Body_Collection & collection){
	return collection[nrand(collection.size())];
}


//Expands rule into all non-terminal symbols and stores them in the 'result' vector
/*
Say grammar g is:
<A>		<B> + <B>
<B>		<C> + x
<C>		y

If <A> was passed as the current_rule_def,

after execution, the 'result' vector would equal ["y", "+", "x", "+", "y", "+", "x"]

in other words,
<A>
is expanded to
y + x + y + x
*/
void expand_rule(const Grammar & g, const Rule_Body & current_rule_def, vector<string> & result){

	//loop through all of the words int the rule definition eg. <body> -> <noun> hello, world. // <noun> hello, world is the rule_body
	for(Rule_Body::const_iterator current_word_in_rule_def = current_rule_def.begin();
	 current_word_in_rule_def != current_rule_def.end();
	 ++current_word_in_rule_def){

	 	//base case, current word is terminal
		if(!bracketed(*current_word_in_rule_def))
			result.push_back(*current_word_in_rule_def);
		else{
			//encountered another bracketed word (nonterminal)
			Grammar::const_iterator entry = g.find(*current_word_in_rule_def);
			if(entry == g.end())
				throw logic_error("The inputted grammar does not have definition for tag: " + *current_word_in_rule_def);

			//continue to expand new tag
			expand_rule(g, get_random_rule_body_from_collection(entry->second), result);
		}

	}

}

//This function takes a gramamar and start tag to create a random sentence.
vector<string> generate_sentence(const Grammar & g, const string & start_tag){
	Grammar::const_iterator it = g.find(start_tag);
	if(it == g.end())
		throw logic_error("The inputted grammar does not have start_tag: " + start_tag + " defined.");

	vector<string> resulting_sentence;

	//the iterator 'it' has a pair<string, Rule_Collection> where the first string is the start_tag.
	Rule_Body unexpanded_sentence_structure = get_random_rule_body_from_collection(it->second);

	expand_rule(g, unexpanded_sentence_structure, resulting_sentence);

	return resulting_sentence;
	
}