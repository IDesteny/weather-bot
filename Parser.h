#pragma once
#include <string>
#include <utility>
#include <boost/regex.hpp>

namespace jsn
{
	class Parser
	{
	public:
		static std::string parse(const std::string &, const std::string &);
	};
}