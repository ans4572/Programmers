#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

bool playCmp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	unordered_map<string, vector<pair<int, int> > > genrePlayInfo;
	unordered_map<string, int> genreCount;

	for (int i = 0; i < genres.size(); ++i) {
		genrePlayInfo[genres[i]].push_back(make_pair(plays[i], i));
		genreCount[genres[i]] += plays[i];
	}

	for (auto& k : genrePlayInfo) {
		sort(k.second.begin(), k.second.end(), playCmp);
	}

	vector<pair<string, int> > vec(genreCount.begin(), genreCount.end());
	sort(vec.begin(), vec.end(), cmp);

	vector<int> answer;
	for (int i = 0; i < vec.size(); ++i) {
		string nowGen = vec[i].first;

		if (genrePlayInfo[nowGen].size() == 1)
			answer.push_back(genrePlayInfo[nowGen][0].second);
		else {
			answer.push_back(genrePlayInfo[nowGen][0].second);
			answer.push_back(genrePlayInfo[nowGen][1].second);
		}
	}

	return answer;
}