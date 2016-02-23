#ifndef UMNS_H
#define UMNS_H

#include <string>
#include "nameserverinterface.h"
#include <algorithm>
#include <unordered_map>


class UMNS : public NameServerInterface{
public:
	UMNS();
	void insert(const HostName& host, const IPAddress& ip);
	bool remove(const HostName& host);
	IPAddress lookup(const HostName& host) const;
private:
	std::unordered_map<HostName, IPAddress> map;
};

#endif