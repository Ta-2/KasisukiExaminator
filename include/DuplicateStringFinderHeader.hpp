#ifndef dsfH
#define dsfH

#include "StatisticsCalculator.hpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <utility>
#include <cmath>
using namespace std;

typedef pair<string, vector<int>> PSV;
typedef pair<const string, vector<int>> refPSV;

class DuplicateStringFinder{
private:
	int size = 0;
	string plain;
	vector<PSV> Where;
	map<string, vector<int>> CMap;
	map<int, vector<refPSV>> AppearMap;
	map<int, vector<refPSV>*> PeriodMap;
	set<int> Candidates;
public:
	DuplicateStringFinder(string);
	void StringAnalyzer();
	set<int> SearchDuplicateString(double);
	void MoreSearchDuplicateString(map<string, vector<int>>::iterator&);
};


#endif
