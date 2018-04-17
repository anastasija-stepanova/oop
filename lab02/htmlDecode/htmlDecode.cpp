#include "stdafx.h"
#include "htmlDecode.h"

static const std::unordered_map<std::string, std::string> HTML_ENTITIES
{
	{ "&quot;", "\"" },
	{ "&apos;", "'" },
	{ "&lt;", "<" },
	{ "&gt;", ">" },
	{ "&amp;", "&" }
};

std::string DecodeHtmlEntity(const std::string &inputString, const std::string &searchString, const std::string &replacementString)
{
	std::string result;
	if (searchString.empty())
	{
		result = inputString;
	}
	size_t position = 0;
	while (position < inputString.size())
	{
		size_t positionSearchString = inputString.find(searchString, position);
		result.append(inputString, position, (positionSearchString - position));
		if (positionSearchString != std::string::npos)
		{
			result.append(replacementString);
			position = positionSearchString + searchString.size();
		}
		else
		{
			break;
		}
	}
	return result;
}

std::string HtmlDecode(std::string const& html)
{
	std::string result = html;
	for (auto& htmlEntity : HTML_ENTITIES)
	{
		result = DecodeHtmlEntity(result, htmlEntity.first, htmlEntity.second);
	}
	return result;
}