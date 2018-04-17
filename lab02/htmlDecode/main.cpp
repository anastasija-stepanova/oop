#include "stdafx.h"
#include "htmlDecode.h"
using namespace std;

void DecodeHtmlDocument(istream &input, ostream &output)
{
	string htmlLine;
	while (getline(input, htmlLine))
	{
		output << HtmlDecode(htmlLine) << endl;
	}
}

int _tmain()
{
	DecodeHtmlDocument(cin, cout);
	return 0;
}
