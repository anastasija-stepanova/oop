#pragma once

template <typename T, typename Less>
bool FindMax(
	const std::vector<T>& arr,
	T& maxValue,
	const Less& less = std::less<T>)
{
	auto theBiggest = arr.begin();
	for (auto it = arr.begin(); it != arr.end(); ++it)
	{
		if (less(*theBiggest, *it))
		{
			theBiggest = it;
		}
	}
	if (theBiggest != arr.end())
	{
		maxValue = *theBiggest;
		return true;
	}
	return false;
}
