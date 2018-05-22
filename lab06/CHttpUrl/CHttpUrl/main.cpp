#include "stdafx.h"
#include "CHttpUrl.h"

using namespace std;

string GetProtocolTitle(Protocol protocol)
{
	return (protocol == Protocol::HTTP) ? "http" : "https";
}

int _tmain()
{
	while (!cin.eof() && !cin.fail())
	{
		string inputUrl;
		cout << "Enter URL: ";
		cin >> inputUrl;
		cout << endl;
		try
		{
			CHttpUrl url(inputUrl);
			cout << "> Protocol: " << GetProtocolTitle(url.GetProtocol()) << endl;
			cout << "> Domain: " << url.GetDomain() << endl;
			cout << "> Port: " << url.GetPort() << endl;
			cout << "> Document: " << url.GetDocument() << endl;
		}
		catch (CUrlParsingError const& e)
		{
			cerr << e.what() << endl;
		}
	}

	return 0;
}
