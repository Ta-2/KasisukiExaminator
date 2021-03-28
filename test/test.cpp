#include "KasisukiExaminatorHeader.hpp"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	vector<AppearTable> table{
		make_pair<string, vector<int>>("a", vector<int>{1, 54, 75, 2}), 
		make_pair<string, vector<int>>("b", vector<int>{2, 54, 87}), 
		make_pair<string, vector<int>>("cd", vector<int>{2, 5, 7, 9}), 
		make_pair<string, vector<int>>("dd", vector<int>{14, 54}), 
		make_pair<string, vector<int>>("etd", vector<int>{2, 4, 43, 67}) 
	};
	KasisukiExaminator *ke;
	set<int> result;
	ke = new KasisukiExaminator(table);
	result = ke->Examinate(2.4);
	
	for(auto r: result)cout << r << ", ";	
	cout << endl;
	
	return 0;
}
