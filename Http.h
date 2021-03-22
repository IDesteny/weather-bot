#pragma once
#include <string>

namespace http
{
	class HttpHelper
	{
	public:
		static std::string __fastcall request(const std::string &, const std::string &target = "");
	};
}