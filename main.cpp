#include <iostream>
#include <map>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <exception>
#include <fstream>
#include <boost/thread/thread.hpp>

using namespace std;

class Pairs {
	list<pair<int, int>> original;
	list<pair<int, int>> result;

	void deleteSomePairs(int n, list<pair<int, int>> & l) {
		list<pair<int, int>>::iterator it = l.begin();
		++it; //pass first x
		size_t size = l.size();
		for (size_t i = 2; i <= size - 1; i++) { 
			if (i % n != 0) {
				list<pair<int, int>>::iterator tmpIt = it;
				++it;
				l.erase(tmpIt);
			}
			else
				++it;
		}
	}
public:
	Pairs(istream& is) {
		int first, second;
		char c;
		while (is >> c) { //read '('
			is >> first;
			is >> c;	  //read ','
			is >> second;
			is >> c;      //read ')'
			original.push_back(make_pair(first, second));
		}
	}
	void solve(int n) {
		unordered_map<int, list<pair<int, int>>> YX; //for each Y store (X, Y) pairs
		for (list<pair<int, int>>::const_iterator it = original.cbegin(); it != original.cend(); ++it)
			YX[it->second].push_back(*it);

		boost::thread_group threads;
		for (unordered_map<int, list<pair<int, int>>>::iterator it = YX.begin(); it != YX.end(); ++it) 
			threads.create_thread(boost::bind(&Pairs::deleteSomePairs, this, n, ref(it->second)));
		threads.join_all();

		/* Merge together what left after calculations */
		for (unordered_map<int, list<pair<int, int>>>::iterator it = YX.begin(); it != YX.end(); ++it)
			result.merge(it->second);
	}

	void printResult(ostream & os) const {
		for (list<pair<int, int>>::const_iterator it = result.cbegin(); it != result.cend(); ++it)
			os << "(" << it->first << ", " << it->second << ") ";
	}
};
int main() {
	ifstream from("input.txt");
	Pairs xy(from);
	cout << "Input n " << endl;
	int n;
	cin >> n;
	xy.solve(n);
	xy.printResult(cout);
	return 0;
}
