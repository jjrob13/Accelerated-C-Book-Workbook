#include "url_parser.h"
#include <algorithm>
#include <cctype>

using std::vector;		using std::string;

string::const_iterator find_url_start(string::const_iterator, string::const_iterator);
string::const_iterator find_url_end(string::const_iterator, string::const_iterator);
bool not_url_char(char);


vector<string> extract_urls(const string & doc){
	typedef string::const_iterator iter;

	iter start = doc.begin();

	vector<string> result;
	//invariant: result contains all of the urls seen so far
	while(start != doc.end()){
		start = find_url_start(start, doc.end());

		iter url_end_plus_1 = find_url_end(start, doc.end());

		//empty string returned
		if(start != doc.end())
			result.push_back(string(start, url_end_plus_1));

		start = url_end_plus_1;
	}


	return result;
}

string::const_iterator find_url_start(string::const_iterator begin, string::const_iterator end){
	static const string splitter = "://";
	typedef string::const_iterator iter;
	iter split_start;

	while((split_start =  std::search(begin, end, splitter.begin(), splitter.end())) != end){

		//there is atleast one VALID character before and after the ://
		if(split_start != begin &&  //the doc does not start with ://
			split_start + splitter.size() != end && //there is a character after ://
			!not_url_char(split_start[splitter.size()]) &&  //there is at least one valid url char after the ://
			std::isalpha(split_start[-1])){				// there is at least one valid url char before the ://


			iter protocol_start = split_start - 1;

			//invariant: protocol_start is an alphabetical character before the :// 
			while(protocol_start != begin && isalpha(protocol_start[-1]))
				protocol_start--;

			return protocol_start;
		}
	}

	return end;
}

string::const_iterator find_url_end(string::const_iterator begin, string::const_iterator end){
	return find_if(begin, end, not_url_char);
}


bool not_url_char(char c){
	static const string allowed_chars = "~;/?:@=&$-_.+!*'(),";

	return !(std::isalnum(c) ||
		std::find(allowed_chars.begin(), allowed_chars.end(), c) != allowed_chars.end());
}
