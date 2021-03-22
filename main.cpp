#include <iostream>
#include "HttpHelper.h"
#include "Parser.h"
#include <thread>

int main()
{
	using std::string;
	
	const string key = "b8f018693cafdf2757edc95cd73f367c";
	const string city = "Grabovo";

	const string host = "api.openweathermap.org";
	const string target = "/data/2.5/weather?q=" + city + "&appid=" + key;

	const string response = http::HttpHelper::request(host, target);
	
	const string temp = jsn::Parser::parse(response, "temp");

	const unsigned short K = 273u;
	const unsigned short T = atoi(temp.c_str());
	const int C = T - K;

	std::cout << "C: " << C << std::endl;

	return 0;
}