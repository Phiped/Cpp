#ifndef AV_H
#define	AV_H

#include <utility>
#include <vector> 

template <typename Key, typename Value>
class AV{
public:
	using iterator = std::vector<std::pair<Kek,Value>>::iterator;
	AV(){}
	void insert(std::pair<Key,Value>& p){
		v.emplace_back(p);
		v.sort(v.begin(),b.end(), [](std:pair<Key,Value>& p1,std:pair<Key,Value>& p2){return p1.second< p2.second;})
	}
	iterator find(std::pair<Key,Value>& p){
		std::binary_search(v.begin(),v.end(), p.second, [std::pair<Key,Value>& p](std::pair<Key,Value>& p1){return p.first ==p1.first});
	}
	iterator begin() { v.begin()}
	iterator end() { v.end()}

private:
	std::vector<std::pair<Key,Value>> v;
};

#endif