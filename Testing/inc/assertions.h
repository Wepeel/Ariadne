#pragma once

#define ARD_ASSERT_STATIC_EQ(value, expected, message) static_assert(value, expected, message)

#define ARD_ASSERT_STATIC_EQ(value, expected) static_assert(value, expected)


#define ARD_ASSERT_RT_EQ(value, expected, message) 

#define ARD_ASSERT_RT_EQ(value, expected) assertion::assert_eq(value, expected)


//TODO: Create portable debugbreak macro
#ifdef _MSC_VER
#define DEBUG_BREAK __debugbreak()
#endif


namespace assertion
{
	template<typename T>
	void assert_eq(T value, T expected)
	{
		if (value != expected)
		{
			DEBUG_BREAK;
		}
	}
}