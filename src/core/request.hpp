#pragma once

namespace request
{
	enum methods
	{
		get = 0,
		post = 1,
		put = 2,
		del = 3,
	};

	class http_request
	{
	public:
		http_request(const std::string& method, const std::string& url, const std::string& route);
		void set_header(const std::string& name, const chaiscript::Boxed_Value& value);
		void send(const std::string& body, const chaiscript::Boxed_Value& callback);
	private:
		std::string url;
		std::string route;
		std::string content_type = "text/plain"s;

		methods method;
		std::map<std::string, chaiscript::Boxed_Value> headers;
	};
}