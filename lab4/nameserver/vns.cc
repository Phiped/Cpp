#include "vns.h"

VNS::VNS(){}

void VNS::insert(const HostName& host, const IPAddress& ip){
	v.emplace_back(host,ip);
}

bool VNS::remove(const HostName& host){
	auto it = v.erase(find_if(v.begin(),v.end(),[&host](std::pair<HostName,IPAddress> p){ return p.first==host; }));

	if(it>v.end()){
		return false;
	}else{
		return true;
	}
}

IPAddress VNS::lookup(const HostName& host) const{
	auto it = find_if(v.begin(),v.end(),[&host](std::pair<HostName,IPAddress> p){ return p.first==host;});
	if (it == v.end())
	{
		return NON_EXISTING_ADDRESS;
	} else {
		return (*it).second;
	}
}