#pragma once

#include "assertions.h"

#define ARD_TEST_INIT() int tests_passed = 0;\
						int tests_tested = 0;\

//ARD_ASSERT_STATIC_COND_MSG(typeid(value) == typeid(expected), "Not same type");\

#define ARD_TEST_EXPECT_EQ(value, expected) if (value == expected)\
											{\
												++tests_passed;\
												printf("Test number %d succeeded.\n", tests_tested + 1);\
											}\
											else\
											{\
												printf("Test number %d failed\n", tests_tested + 1);\
											}\
											++tests_tested;

#define ARD_TEST_BREAKDOWN() if (0 == tests_tested)\
								{\
									printf("No tests were run");\
								}\
								else\
								{\
									printf("%d tests out of %d succeeded. Test rate: %.2f", tests_passed, tests_tested, (float)tests_passed / tests_tested);\
								}\
