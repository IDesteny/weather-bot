#include "HttpHelper.h"
#include <boost/asio/io_context.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/http/dynamic_body.hpp>
#include <boost/beast/http/string_body.hpp>
#include <boost/beast/http/message.hpp>
#include <boost/beast/http/write.hpp>
#include <boost/beast/http/read.hpp>
#include <boost/beast/core/buffers_to_string.hpp>
#include <boost/beast/core/flat_buffer.hpp>
#include <boost/beast/version.hpp>

std::string http::HttpHelper::request(const std::string &host, const std::string &target)
{
	try {
		boost::asio::io_context ioc;
		boost::asio::ip::tcp::resolver resolver(ioc);
		boost::asio::ip::tcp::socket socket(ioc);

		boost::asio::connect(socket, resolver.resolve(host, "80"));
		{
			boost::beast::http::request<boost::beast::http::string_body>
				req(boost::beast::http::verb::get, target, 11);

			req.set(boost::beast::http::field::host, host);
			req.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);

			boost::beast::http::write(socket, req);
		}
		std::string response;
		{
			boost::beast::flat_buffer buffer;
			boost::beast::http::response<boost::beast::http::dynamic_body> res;
			boost::beast::http::read(socket, buffer, res);
			response = boost::beast::buffers_to_string(res.body().data());
		}

		socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
		return std::move(response);
	} catch (const std::exception &e) { throw e; }
}