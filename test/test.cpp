#include "DuplicateStringFinderHeader.hpp"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	DuplicateStringFinder *dsf;
	set<int> result;
	if(argc > 1) dsf = new DuplicateStringFinder(argv[1]);
	else dsf = new DuplicateStringFinder("abccabaabcccababcb");
	//dsf->PrintPlain();
	dsf->StringAnalyzer();
	if(argc > 2) result = dsf->SearchDuplicateString(atof(argv[2]));
	else result = dsf->SearchDuplicateString(2.4);
	
	for(auto r: result)cout << r << ", ";	
	cout << endl;
	
	return 0;
}
