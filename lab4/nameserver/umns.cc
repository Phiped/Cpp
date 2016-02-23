#include "umns.h"

UMNS::UMNS(){}


void UMNS::insert(const HostName& host, const IPAddress& ip){
	map.emplace(host,ip);
}

bool UMNS::remove(const HostName& host){
	auto k = map.erase(host);
	return k != 0;
}

IPAddress UMNS::lookup(const HostName& host) const{
	auto it = map.find(host);

	if(it != map.end()){
		return (*it).second;
	}else{
		return NON_EXISTING_ADDRESS;
	} 
}