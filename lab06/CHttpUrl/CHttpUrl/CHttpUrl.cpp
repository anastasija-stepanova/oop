// CHttpUrl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CHttpUrl.h"

using namespace std;

namespace
{
const constexpr int PORT_MIN_BOUND = 1;
const constexpr int PORT_MAX_BOUND = 65535;
const vector<pair<Protocol, string>> protocolVector = {
	{ Protocol::HTTP, "http" },
	{ Protocol::HTTPS, "https" }
};

string GetProtocolString(Protocol protocol)
{
	for (const auto& pair : protocolVector)
	{
		if (pair.first == protocol)
		{
			return pair.second;
		}
	}

	throw invalid_argument("Can`t find protocol string representation by passed enum");
}

bool CheckPortInRange(unsigned short port)
{
	return (port >= PORT_MIN_BOUND && port <= PORT_MAX_BOUND);
}
} // namespace

CHttpUrl::CHttpUrl(const string& url)
	: m_url(url)
{
	if (url.empty())
	{
		throw CUrlParsingError("Url is empty");
	}
	smatch result;
	regex reg(R"(^(\w+):\/\/([^\s:\/]+)(?::(\d+))?(?:\/(\S*))?$)", regex::icase);
	bool mapped = regex_search(url, result, reg);

	if (!mapped)
	{
		throw CUrlParsingError("Url is invalid");
	}

	m_protocol = ParseProtocol(result[1]);
	m_domain = ParseDomain(result[2]); 
	m_port = ParsePort(result[3]); 
	m_document = ParseDocument(result[4]);
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol)
	: m_domain(domain)
	, m_document(document)
	, m_protocol(protocol)
{
	if (domain.empty())
	{
		throw CUrlParsingError("Domain is empty");
	}

	m_document = ParseDocument(document);
	string protocolStr = GetProtocolString(m_protocol);
	m_port = static_cast<int>(m_protocol);

	m_url = protocolStr + m_domain + m_document;
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol, unsigned short port)
	: m_domain(domain)
	, m_document(document)
	, m_protocol(protocol)
{
	if (CheckPortInRange(port))
	{
		m_port = port;
	}

	if (domain.empty())
	{
		throw CUrlParsingError("Domain is empty");
	}

	m_document = ParseDocument(document);

	string portStr;
	string protocolStr = GetProtocolString(m_protocol);
	if (m_protocol == Protocol::HTTP)
	{
		if (m_port != static_cast<unsigned short>(Protocol::HTTP))
		{
			portStr = ":" + to_string(m_port);
		}
	}
	else
	{
		if (m_port != static_cast<unsigned short>(Protocol::HTTPS))
		{
			portStr = ":" + to_string(m_port);
		}
	}

	m_url = protocolStr + m_domain + portStr + m_document;
}

string CHttpUrl::GetUrl() const
{
	return m_url;
}

string CHttpUrl::GetDomain() const
{
	return m_domain;
}

string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

unsigned short CHttpUrl::ParsePort(const string& portString)
{
	if (portString.empty())
	{
		return static_cast<unsigned short>(m_protocol);
	}
	auto port = stoi(portString);
	if (CheckPortInRange(port))
	{
		return port;
	}
	else
	{
		throw CUrlParsingError("Port out of range");
	}
}

string CHttpUrl::ParseDocument(const string& document)
{
	if (document.empty() || (document[0] != '/'))
	{
		return "/" + document;
	}
	return document;
}

Protocol CHttpUrl::ParseProtocol(const string& protocolStr)
{
	string lowCaseProtocol;
	transform(protocolStr.begin(), protocolStr.end(), back_inserter(lowCaseProtocol), tolower);

	for (const auto& pair : protocolVector)
	{
		if (pair.second == lowCaseProtocol)
		{
			return pair.first;
		}
	}
	throw CUrlParsingError("Protocol is invalid");
}

string CHttpUrl::ParseDomain(string const& domain)
{
	if (domain.empty())
	{
		throw CUrlParsingError("Domain is invalid");
	}
	return domain;
}
