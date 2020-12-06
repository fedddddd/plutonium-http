#pragma once

#pragma warning(disable: 4244)
#pragma warning(disable: 6031)
#pragma warning(disable: 26451)
#pragma warning(disable: 26495)
#pragma warning(disable: 26812)
#pragma warning(disable: 28020)

#define DLL_EXPORT extern "C" __declspec(dllexport)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <map>
#include <atomic>
#include <vector>
#include <mutex>
#include <queue>
#include <regex>
#include <chrono>
#include <thread>
#include <fstream>
#include <utility>
#include <filesystem>
#include <functional>
#include <sstream>
#include <optional>

#include <httplib.h>

using namespace std::string_literals;

#include "utils/memory.hpp"
#include "utils/string.hpp"

#include "game/chaiscript/chaiscript.hpp"

#include "core/conversion.hpp"
#include "core/client.hpp"
#include "core/request.hpp"