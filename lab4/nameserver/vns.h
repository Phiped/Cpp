#ifndef VNS_H
#define VNS_H

#include <string>
#include "nameserverinterface.h"
#include <vector>
#include <utility>
#include <algorithm>


class VNS : public NameServerInterface{
public:
	VNS();
	void insert(const HostName& host, const IPAddress& ip);
	bool remove(const HostName& host);
	IPAddress lookup(const HostName& host) const;
private:
	std::vector<std::pair<HostName,IPAddress>> v;
};

#endif