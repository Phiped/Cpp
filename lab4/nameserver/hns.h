#ifndef HNS_H
#define HNS_H

#include <string>
#include "nameserverinterface.h"
#include <algorithm>
#include <unordered_map>
#include <utility>


class HNS : public NameServerInterface{
public:
	HNS(int i);
	void insert(const HostName& host, const IPAddress& ip);
	bool remove(const HostName& host);
	IPAddress lookup(const HostName& host) const;
private:
	int size;
	std::vector<std::vector<std::pair<HostName,IPAddress>>> v;
	std::hash<HostName> host_hash;
};

#endif