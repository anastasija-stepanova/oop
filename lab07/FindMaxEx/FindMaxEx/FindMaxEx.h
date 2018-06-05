#pragma once

template <typename T, typename Less>
bool FindMax(
	const std::vector<T>& arr,
	T& maxValue,
	const Less& less = std::less<T>)
{
	auto large = arr.begin();
	for (auto it = arr.begin(); it != arr.end(); ++it)
	{
		if (less(*large, *it))
		{
			large = it;
		}
	}
	if (large != arr.end())
	{
		maxValue = *large;
		return true;
	}
	return false;
}
