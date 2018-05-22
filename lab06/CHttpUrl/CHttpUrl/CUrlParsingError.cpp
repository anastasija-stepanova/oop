#include "stdafx.h"
#include "CUrlParsingError.h"

using namespace std;

CUrlParsingError::CUrlParsingError(const string& message)
	: invalid_argument(message)
{
}