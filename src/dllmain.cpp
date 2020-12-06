#include <stdinc.hpp>

DLL_EXPORT void on_initialize_context(const char* script, chaiscript::ChaiScript* chai)
{
    chai->add(chaiscript::user_type<request::http_request>(), "httpRequest");
    chai->add(chaiscript::constructor<request::http_request(const std::string& method, const std::string& url, const std::string& route)>(), "httpRequest");

    chai->add(chaiscript::fun(&request::http_request::send), "send");
    chai->add(chaiscript::fun(&request::http_request::set_header), "setHeader");
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {

    }

    return TRUE;
}