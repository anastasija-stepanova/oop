#include "stdafx.h"
#include "../../CHttpUrl/CHttpUrl/CHttpUrl.h"
#include "../../CHttpUrl/CHttpUrl/CUrlParsingError.h"

BOOST_AUTO_TEST_SUITE(CHttpURL)
BOOST_AUTO_TEST_SUITE(url)
		BOOST_AUTO_TEST_CASE(can_not_be_parse_bacause_it_is_empty)
		{
			BOOST_CHECK_THROW(CHttpUrl(""), CUrlParsingError);
		}
		BOOST_AUTO_TEST_CASE(can_not_be_parse_bacause_protocol_is_empty)
		{
			BOOST_CHECK_THROW(CHttpUrl("", "/index/images", Protocol::HTTPS), CUrlParsingError);
		}
		BOOST_AUTO_TEST_CASE(can_be_parse)
		{
			CHttpUrl httpsUrl("https://google.com/index");
			BOOST_CHECK(httpsUrl.GetProtocol() == Protocol::HTTPS);
			BOOST_CHECK(httpsUrl.GetDomain() == "google.com");
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(protocol)
		BOOST_AUTO_TEST_CASE(can_not_be_parse_because_it_is_invalid)
		{
			BOOST_CHECK_THROW(CHttpUrl("test://google.com/index"), CUrlParsingError);
		}
		BOOST_AUTO_TEST_CASE(can_be_parse_bacause_it_is_equal_to_http)
		{
			CHttpUrl httpUrl("http://google.com/index");
			BOOST_CHECK(httpUrl.GetProtocol() == Protocol::HTTP);
		}
		BOOST_AUTO_TEST_CASE(can_be_parse_bacause_it_is_equal_to_https)
		{
			CHttpUrl httpsUrl("https://google.com/index");
			BOOST_CHECK(httpsUrl.GetProtocol() == Protocol::HTTPS);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(domain)
		BOOST_AUTO_TEST_CASE(can_be_parse)
		{
			CHttpUrl httpsUrl("https://google.com/");
			BOOST_CHECK(httpsUrl.GetDomain() == "google.com");
		}
		BOOST_AUTO_TEST_CASE(can_not_be_parse_because_it_is_invalid)
		{
			BOOST_CHECK_THROW(CHttpUrl("http://google  .com/index"), CUrlParsingError);
		}
		BOOST_AUTO_TEST_CASE(is_empty)
		{
			BOOST_CHECK_THROW(CHttpUrl("http://"), CUrlParsingError);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(port)
		BOOST_AUTO_TEST_CASE(can_be_parse_because_it_is_equal_to_80)
		{
			CHttpUrl httpUrl("http://google.com/");
			BOOST_CHECK((int)httpUrl.GetPort() == 80);
		}
		BOOST_AUTO_TEST_CASE(can_be_parse_because_it_is_equal_to_443)
		{
			CHttpUrl httpsUrl("https://google.com/");
			BOOST_CHECK((int)httpsUrl.GetPort() == 443);
		}
		BOOST_AUTO_TEST_CASE(can_be_parse_in_url)
		{
			CHttpUrl url("https://google.com:3008/");
			BOOST_CHECK((int)url.GetPort() == 3008);
		}
		BOOST_AUTO_TEST_CASE(can_be_parse_because_it_is_qual_to_1)
		{
			CHttpUrl url("https://google.com:1/");
			BOOST_CHECK((int)url.GetPort() == 1);
		}
		BOOST_AUTO_TEST_CASE(can_be_parse_because_it_is_qual_to_65535)
		{
			CHttpUrl url("https://google.com:65535/");
			BOOST_CHECK((int)url.GetPort() == 65535);
		}
		BOOST_AUTO_TEST_CASE(can_not_be_parse_because_it_out_of_range)
		{
			BOOST_CHECK_THROW(CHttpUrl("https://domain.net: "), CUrlParsingError);
			BOOST_CHECK_THROW(CHttpUrl("https://domain.net:0/"), CUrlParsingError);
			BOOST_CHECK_THROW(CHttpUrl("https://domain.net:-8/"), CUrlParsingError);
			BOOST_CHECK_THROW(CHttpUrl("https://domain.net:65536"), CUrlParsingError);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(document)
		BOOST_AUTO_TEST_CASE(can_be_parse)
		{
			CHttpUrl url("https://google.com:3008/index.php");
			BOOST_CHECK(url.GetDocument() == "/index.php");
		}
		BOOST_AUTO_TEST_CASE(can_not_be_parse_because_it_is_invalid)
		{
			BOOST_CHECK_THROW(CHttpUrl("https://google.com/index/no document"), CUrlParsingError);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
