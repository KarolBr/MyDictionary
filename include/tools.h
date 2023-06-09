#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <chrono>
#include <iomanip>
#include<string>
#include<vector>


std::string getDateAndTimeToString(const char *param = "%F %T")
{
    const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
    std::stringstream currTime;
    currTime << std::put_time(std::localtime(&t_c), param);
    return currTime.str();
}


std::vector<std::string> split(std::string s)
{
	std::vector<std::string> vec{};
	
	int pos{}, next_pos{};

	while(next_pos != -1){
		next_pos = s.find(' ',pos);
        vec.push_back(s.substr(pos,next_pos-pos));
        pos=next_pos+1;
	}
	return vec;
}

#endif // TOOLS_H