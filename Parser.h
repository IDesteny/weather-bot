#pragma once
#include <boost/regex.hpp>
#include <string>

namespace jsn
{
	class Parser
	{
	public:
		static std::string parse(const std::string &, const std::string &);
	};
}
