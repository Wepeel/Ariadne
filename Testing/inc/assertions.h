#pragma once

//TODO: Create portable debugbreak macro
#ifdef _MSC_VER
#define DEBUG_BREAK __debugbreak()
#endif

#define ARD_ASSERT_STATIC_EQ_MSG(value, expected, message) static_assert(value == expected, message)

#define ARD_ASSERT_STATIC_EQ(value, expected) static_assert(value == expected, "Fail")


#define ARD_ASSERT_RT_EQ(value, expected) if (value != expected) DEBUG_BREAK


namespace assertion
{
	template<typename T>
	static void assert_eq(T value, T expected)
	{
		if (value != expected)
		{
			DEBUG_BREAK;
		}
	}
}