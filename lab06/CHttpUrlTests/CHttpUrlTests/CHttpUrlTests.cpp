#include "stdafx.h"
#include "../../CHttpUrl/CHttpUrl/CHttpUrl.h"
#include "../../CHttpUrl/CHttpUrl/CUrlParsingError.h"

BOOST_AUTO_TEST_SUITE(CHttpURL)
	BOOST_AUTO_TEST_CASE(initialization)
	{
		BOOST_CHECK_THROW(CHttpUrl("test://google.com/index"), CUrlParsingError); 
		BOOST_CHECK_THROW(CHttpUrl("", "/index/images", Protocol::HTTPS, 443), CUrlParsingError);
		BOOST_CHECK_THROW(CHttpUrl("", "/index/images", Protocol::HTTPS), CUrlParsingError);
		BOOST_CHECK_THROW(CHttpUrl("http://google.com/inde x"), CUrlParsingError);
	}
	BOOST_AUTO_TEST_SUITE(parse_url)
		BOOST_AUTO_TEST_CASE(parse_protocol)
		{
			BOOST_CHECK_THROW(CHttpUrl(""), CUrlParsingError);
			BOOST_CHECK_THROW(CHttpUrl("test://google.com/index"), CUrlParsingError);
			CHttpUrl httpUrl("http://google.com/index");
			BOOST_CHECK(httpUrl.GetProtocol() == Protocol::HTTP);
			CHttpUrl httpsUrl("https://google.com/index");
			BOOST_CHECK(httpsUrl.GetProtocol() == Protocol::HTTPS);
			BOOST_CHECK(httpsUrl.GetUrl() == "https://google.com/index");
		}
		BOOST_AUTO_TEST_CASE(parse_domain)
		{
			BOOST_CHECK_THROW(CHttpUrl("http://"), CUrlParsingError);
			BOOST_CHECK_THROW(CHttpUrl("http://google  .com/index"), CUrlParsingError);

			CHttpUrl httpsUrl("https://google.com/");
			BOOST_CHECK(httpsUrl.GetDomain() == "google.com");
		}
		BOOST_AUTO_TEST_CASE(parse_port)
		{
			BOOST_CHECK_THROW(CHttpUrl("https://domain.net: "), CUrlParsingError);
			BOOST_CHECK_THROW(CHttpUrl("https://domain.net:0/"), CUrlParsingError);
			BOOST_CHECK_THROW(CHttpUrl("https://domain.net:-8/"), CUrlParsingError);
			BOOST_CHECK_THROW(CHttpUrl("https://domain.net:65536"), CUrlParsingError);

			CHttpUrl httpsUrl("https://google.com/");
			BOOST_CHECK((int)httpsUrl.GetPort() == 443);

			CHttpUrl httpUrl("http://google.com/");
			BOOST_CHECK((int)httpUrl.GetPort() == 80);

			CHttpUrl url("https://google.com:3008/");
			BOOST_CHECK((int)url.GetPort() == 3008);
		}
		BOOST_AUTO_TEST_CASE(parse_document)
		{
			BOOST_CHECK_THROW(CHttpUrl("https://google.com/index/no document"), CUrlParsingError);

			CHttpUrl url("https://google.com:3008/index.php");
			BOOST_CHECK(url.GetDocument() == "/index.php");

			CHttpUrl httpUrl("https://google.com/index/dictonary.php");
			BOOST_CHECK(httpUrl.GetDocument() == "/index/dictonary.php");
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
