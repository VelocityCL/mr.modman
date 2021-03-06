#pragma once

#include <iostream>
#include <cstdio>
#include <regex>

#ifndef LOADER
#include "../app/menus/menus.hpp"
#endif

class logger
{
public:
	static void log(const std::string& type, const std::string& text)
	{
		std::cout << "[ " << type << " ] " << text << std::endl;

#ifndef LOADER
		menus::console_output.emplace_back(std::string("[ " + type + " ] " + text));
#endif
	}

	static void log_info(const std::string& text)
	{
		log("INFO", text);
	}

	static void log_error(const std::string& text)
	{
		log("ERROR", text);
	}

	static void log_warning(const std::string& text)
	{
		log("WARNING", text);
	}

	static void log_debug(const std::string& text)
	{
#ifdef DEBUG
		log("DEBUG", text);
#endif
	}

	static std::string va(const char* fmt, ...)
	{
		va_list va;
		va_start(va, fmt);
		char result[512]{};
		std::vsprintf(result, fmt, va);
		return std::string(result);
	}

	static std::string get_toggle(bool input)
	{
		switch (input)
		{
		case true:
			return "On";
			break;

		case false:
			return "Off";
			break;

		default:
			return "???";
			break;
		}
	}

	static std::vector<std::string> split(const std::string& s, const std::string& seperator)
	{
		std::vector<std::string> output;

		std::string::size_type prev_pos = 0, pos = 0;

		while ((pos = s.find(seperator, pos)) != std::string::npos)
		{
			std::string substring(s.substr(prev_pos, pos - prev_pos));

			output.push_back(substring);

			prev_pos = ++pos;
		}

		output.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

		return output;
	}

	static void to_lower(std::string& string)
	{
		std::for_each(string.begin(), string.end(), ([](char& c)
		{
			c = std::tolower(c);
		}));
	}

	static void to_upper(std::string& string)
	{
		std::for_each(string.begin(), string.end(), ([](char& c)
		{
			c = std::toupper(c);
		}));
	}

	static bool ends_with(std::string const& value, std::string const& ending)
	{
		if (ending.size() > value.size()) return false;
		return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
	}

	static std::string replace(std::string const& in, std::string const& from, std::string const& to)
	{
		return std::regex_replace(in, std::regex(from), to);
	}

};
