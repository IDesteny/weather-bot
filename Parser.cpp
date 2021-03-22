#include "Parser.h"

std::string jsn::Parser::parse(const std::string &json, const std::string &field)
{
	using namespace boost;

	regex pattern("\"" + field + "\":([^,]*)");
	smatch res;

	regex_search(json, res, pattern);
	return std::move(res[1]);
}