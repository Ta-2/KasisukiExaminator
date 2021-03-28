#ifndef dsfH
#define dsfH

#include "StatisticsCalculator.hpp"
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
using namespace std;

typedef pair<string, vector<int>> AppearTable;
typedef pair<const string, vector<int>> refAppearTable;

class KasisukiExaminator{
private:
	int size = 0;
	vector<AppearTable> Where;
	map<string, vector<int>> CMap;
	map<int, vector<refAppearTable>> AppearMap;
	map<int, vector<refAppearTable>*> PeriodMap;
	set<int> Candidates;
public:
	KasisukiExaminator(vector<AppearTable>);
	set<int> Examinate(double);
};


#endif
