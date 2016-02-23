#include "mns.h"

MNS::MNS(){}


void MNS::insert(const HostName& host, const IPAddress& ip){
	map.emplace(host,ip);
}

bool MNS::remove(const HostName& host){
	auto k = map.erase(host);
	return k != 0;
}

IPAddress MNS::lookup(const HostName& host) const{
	auto it = map.find(host);

	if(it != map.end()){
		return (*it).second;
	}else{
		return NON_EXISTING_ADDRESS;
	} 
}