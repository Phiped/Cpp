#include "mns.h"
#include <stdexcept>

MNS::MNS(){}


void MNS::insert(const HostName& host, const IPAddress& ip){
	map.emplace(host,ip);
}

bool MNS::remove(const HostName& host){
	auto k = map.erase(host);
	return k != 0;
}

IPAddress MNS::lookup(const HostName& host) const{
	
	try{
		return map.at(host);
	}catch (out_of_range& e){
		return NON_EXISTING_ADDRESS;
	}
}