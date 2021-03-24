#include <iostream>
#include "HttpHelper.h"
#include "Parser.h"

void output(const float C)
{
	std::cout << "\nTemperature: " << C << std::endl;
}

std::string input()
{
	std::cout << "Enter city:\n>> ";

	std::string city;
	std::cin >> city;

	return std::move(city);
}

int main()
{
	using namespace std;

	const auto key = "b8f018693cafdf2757edc95cd73f367c";
	const auto city = input();

	const auto host = "api.openweathermap.org";
	const auto target = "/data/2.5/weather?q=" + city + "&appid=" + key;

	const auto response = http::HttpHelper::request(host, target);
	
	const auto temp = jsn::Parser::parse(response, "temp");

	const auto K = 273u;
	const auto T = std::stof(temp.c_str());
	const auto C = T - K;

	output(C);

	return 0;
}