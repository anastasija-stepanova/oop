#include "stdafx.h"
#include "../../CHttpUrl/CHttpUrl/CHttpUrl.h"
#include "../../CHttpUrl/CHttpUrl/CUrlParsingError.h"

BOOST_AUTO_TEST_SUITE(CHttpURL)
	BOOST_AUTO_TEST_CASE(url_is_invalid)
	{
		BOOST_CHECK_THROW(CHttpUrl("", "/index/images", Protocol::HTTPS), CUrlParsingError);
	}
	BOOST_AUTO_TEST_CASE(protocol_is_invalid_and_url_is_invalid)
	{
		BOOST_CHECK_THROW(CHttpUrl("http://google.com/inde x"), CUrlParsingError);
	}
	BOOST_AUTO_TEST_CASE(initialization)
	{
		BOOST_CHECK_THROW(CHttpUrl("test://google.com/index"), CUrlParsingError);
		BOOST_CHECK_THROW(CHttpUrl("", "/index/images", Protocol::HTTPS), CUrlParsingError);
		BOOST_CHECK_THROW(CHttpUrl("http://google.com/inde x"), CUrlParsingError);
	}

	BOOST_AUTO_TEST_SUITE(parse_url)
		BOOST_AUTO_TEST_CASE(parse_empty_url)
		{
			BOOST_CHECK_THROW(CHttpUrl(""), CUrlParsingError);
		}
		BOOST_AUTO_TEST_CASE(parse_invalid_url)
		{
			BOOST_CHECK_THROW(CHttpUrl("", "/index/images", Protocol::HTTPS), CUrlParsingError);
		}
		BOOST_AUTO_TEST_CASE(parse_valid_url)
		{
			CHttpUrl httpsUrl("https://google.com/index");
			BOOST_CHECK(httpsUrl.GetProtocol() == Protocol::HTTPS);
			BOOST_CHECK(httpsUrl.GetDomain() == "google.com");
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(parse_protocol)
		BOOST_AUTO_TEST_CASE(parse_invalid_protocol)
		{
			BOOST_CHECK_THROW(CHttpUrl("test://google.com/index"), CUrlParsingError);
		}
		BOOST_AUTO_TEST_CASE(parse_http_protocol)
		{
			CHttpUrl httpUrl("http://google.com/index");
			BOOST_CHECK(httpUrl.GetProtocol() == Protocol::HTTP);
		}
		BOOST_AUTO_TEST_CASE(parse_https_protocol)
		{
			CHttpUrl httpsUrl("https://google.com/index");
			BOOST_CHECK(httpsUrl.GetProtocol() == Protocol::HTTPS);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(parse_domain)
		BOOST_AUTO_TEST_CASE(parse_valid_domain)
		{
			CHttpUrl httpsUrl("https://google.com/");
			BOOST_CHECK(httpsUrl.GetDomain() == "google.com");
		}
		BOOST_AUTO_TEST_CASE(parse_invalid_domain)
		{
			BOOST_CHECK_THROW(CHttpUrl("http://google  .com/index"), CUrlParsingError);
		}
		BOOST_AUTO_TEST_CASE(parse_empty_domain)
		{
			BOOST_CHECK_THROW(CHttpUrl("http://"), CUrlParsingError);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(parse_port)
		BOOST_AUTO_TEST_CASE(parse_url_with_80_port)
		{
			CHttpUrl httpUrl("http://google.com/");
			BOOST_CHECK((int)httpUrl.GetPort() == 80);
		}
		BOOST_AUTO_TEST_CASE(parse_url_with_443_port)
		{
			CHttpUrl httpsUrl("https://google.com/");
			BOOST_CHECK((int)httpsUrl.GetPort() == 443);
		}
		BOOST_AUTO_TEST_CASE(parse_url_with_port_in_url)
		{
			CHttpUrl url("https://google.com:3008/");
			BOOST_CHECK((int)url.GetPort() == 3008);
		}
		BOOST_AUTO_TEST_CASE(parse_invalid_port)
		{
			BOOST_CHECK_THROW(CHttpUrl("https://domain.net: "), CUrlParsingError);
			BOOST_CHECK_THROW(CHttpUrl("https://domain.net:0/"), CUrlParsingError);
			BOOST_CHECK_THROW(CHttpUrl("https://domain.net:-8/"), CUrlParsingError);
			BOOST_CHECK_THROW(CHttpUrl("https://domain.net:65536"), CUrlParsingError);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(parse_document)
		BOOST_AUTO_TEST_CASE(parse_valid_port)
		{
			CHttpUrl url("https://google.com:3008/index.php");
			BOOST_CHECK(url.GetDocument() == "/index.php");
		}
		BOOST_AUTO_TEST_CASE(parse_invalid_port)
		{
			BOOST_CHECK_THROW(CHttpUrl("https://google.com/index/no document"), CUrlParsingError);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
