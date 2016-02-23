#include "hns.h"
#include <iostream>

HNS::HNS(int i): size(i), v(i,std::vector<std::pair<HostName,IPAddress>>()) {
	
}


void HNS::insert(const HostName& host, const IPAddress& ip){
	(v[host_hash(host)%size]).emplace_back(host,ip);
	
}

bool HNS::remove(const HostName& host){
	auto &vector = v[host_hash(host)%size];
	auto it = find_if(vector.begin(),vector.end(), [&host](std::pair<HostName,IPAddress> p){ return p.first==host; });

	if(it!=vector.end()){
		it = vector.erase(it);
		return true;
	}else{
		return false;
	}

}

IPAddress HNS::lookup(const HostName& host) const{
	auto &vector = v[host_hash(host)%size];
	auto it = find_if(vector.begin(),vector.end(), [&host](std::pair<HostName,IPAddress> p){ return p.first==host; });

	if(it != vector.end()){
		return (*it).second;
	}else{
		return NON_EXISTING_ADDRESS;
	} 
}