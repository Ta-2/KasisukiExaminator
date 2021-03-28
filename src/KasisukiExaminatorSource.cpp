#include "KasisukiExaminatorHeader.hpp"

KasisukiExaminator::KasisukiExaminator(vector<AppearTable>Where){
	this->Where = Where;
}

set<int> KasisukiExaminator::Examinate(double limen){
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
		for(const refAppearTable& w: Where){
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
			
			PeriodMap[a.first] = new vector<refAppearTable>;
			vector<refAppearTable>* AddrefAppearTable = PeriodMap[a.first];
			for(auto s: a.second){
				AddrefAppearTable->push_back(make_pair<const string, vector<int>>((const string)s.first, vector<int>()));
				vector<int>* AddVector = &(AddrefAppearTable->back().second);
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
