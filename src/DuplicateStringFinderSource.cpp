#include "DuplicateStringFinderHeader.hpp"

DuplicateStringFinder::DuplicateStringFinder(string plain){
	this->plain = plain;
}
void DuplicateStringFinder::StringAnalyzer(){
	//-------------------------------------------------
	//initialize CMap to register first location owhere each characters appeared
	//-------------------------------------------------
	size = plain.length();
	for(int i = 0; i < size; i++)
		CMap[string()+plain[i]].push_back(i);
}
set<int> DuplicateStringFinder::SearchDuplicateString(double limen){
		//-------------------------------------------------
		//search strings that appeared 	more than twice
		//-------------------------------------------------
		for(auto c = CMap.begin(); c != CMap.end(); c++)
			MoreSearchDuplicateString(c);
		
		//-------------------------------------------------
		//calculate scores and statistic
		//-------------------------------------------------
		StatisticsCalculator *sc = new StatisticsCalculator;
		
		for(auto a: Where){
			int WordCount = a.first.length(), NumAppearance = a.second.size();
			sc->AddData( (log2(WordCount) * NumAppearance) );
		}
		
		//-------------------------------------------------
		//extract strings most appeared in each group that has same number of length of string
		//-------------------------------------------------
		for(const refPSV& w: Where){
			if(!AppearMap.count(w.first.length())){
				AppearMap[w.first.length()].push_back(w);
				continue;
			} else if (AppearMap[w.first.length()][0].second.size() > w.second.size())
				continue;
			else if(AppearMap[w.first.length()][0].second.size() < w.second.size())
				AppearMap[w.first.length()].clear();
			AppearMap[w.first.length()].push_back(w);
		}
		
		//-------------------------------------------------
		//change AppearMap to PeriodMap
		//-------------------------------------------------
		for(auto a: AppearMap){
			int WordCount = a.first, NumAppearance = a.second[0].second.size();
			double score = log2(WordCount) * NumAppearance;
			if(sc->Standardize(score) < limen)continue;
			
			PeriodMap[a.first] = new vector<refPSV>;
			vector<refPSV>* AddrefPSV = PeriodMap[a.first];
			for(auto s: a.second){
				AddrefPSV->push_back(make_pair<const string, vector<int>>((const string)s.first, vector<int>()));
				vector<int>* AddVector = &(AddrefPSV->back().second);
				int Old = s.second[0];
				
				for(auto p: s.second){
					if((p - Old) > 0)AddVector->push_back(p - Old);
					Old = p;
				}
			}
		}
		
		//-------------------------------------------------
		//calculate common divisors
		//-------------------------------------------------
		for(auto p: PeriodMap){
			for(auto q: *(p.second)){
				int min = *min_element(q.second.begin(), q.second.end());
				for(int i = 1; i*i <= min; i++){
					int num_front = 0, num_back = 0;
					if(!(min % i)){
						for(auto now: q.second) if(!(now%i))num_front++;
						if(i*i-min) for(auto now: q.second) if(!(now%(min/i)))num_back++;
					}
					if((long int)q.second.size() == num_front){
						Candidates.insert(i);
					}
					if((long int)q.second.size() == num_back){
						Candidates.insert(min/i);
					}
				}
			}
		}
		
		//-------------------------------------------------
		//print cnadidates
		//-------------------------------------------------
		return Candidates;

}
void DuplicateStringFinder::MoreSearchDuplicateString(
	map<string, vector<int>>::iterator &c){
	map<string, vector<int>>NextS;
		
		for(auto l: c->second){
			string AddStr = c->first + plain[l + (c->first).length()];
			if((long int)l < (long int)(size-(c->first).length()))
				NextS[AddStr].push_back(l);
		}
		map<string, vector<int> >::iterator it = NextS.begin();
		while(it != NextS.end()){
			if(it->second.size() > 1){
				MoreSearchDuplicateString(it);
				Where.push_back(*it);
				++it;
			} else NextS.erase(it++);
		}
}
