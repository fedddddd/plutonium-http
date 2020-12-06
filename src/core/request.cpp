#include <stdinc.hpp>

namespace request
{
	namespace
	{
		std::map <std::string, methods> method_map =
		{
			{"GET", methods::get},
			{"POST", methods::post},
			{"PUT", methods::put},
			{"DELETE", methods::del},
		};
	}

	http_request::http_request(const std::string& method, const std::string& url, const std::string& route)
	{
		auto _method = utils::string::to_upper(method);

		if (method_map.find(_method) == method_map.end())
		{
			_method = "GET"s;
		}

		this->method = method_map[_method];
		this->url = url;
		this->route = route;
	}

	void http_request::set_header(const std::string& name, const chaiscript::Boxed_Value& value)
	{
		if (utils::string::to_lower(name) == "content-type"s)
		{
			this->content_type = chaiscript::boxed_cast<std::string>(value);
		}

		this->headers[name] = value;
	}

	void http_request::send(const std::string& body, const chaiscript::Boxed_Value& callback)
	{
		const auto headers = Conversion::map_to_headers(this->headers);

		std::thread http([body, callback, headers, this]()
		{
			httplib::Client cli(this->url.data());

			const auto _callback = chaiscript::boxed_cast<std::function<void(chaiscript::Boxed_Value)>>(callback);

			switch (this->method)
			{
			case (methods::get):
				_callback(Conversion::result_to_chai(cli.Get(this->route.data(), headers)));
				break;
			case (methods::post):
				_callback(Conversion::result_to_chai(cli.Post(this->route.data(), headers, body, this->content_type.data())));
				break;
			case (methods::put):
				_callback(Conversion::result_to_chai(cli.Put(this->route.data(), headers, body, this->content_type.data())));
				break;
			case (methods::del):
				_callback(Conversion::result_to_chai(cli.Put(this->route.data(), headers, body, this->content_type.data())));
				break;
			}
		});

		http.detach();
	}
}