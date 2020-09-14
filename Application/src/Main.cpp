#include "apppch.h"
#include "Application.h"
#include "tests.h"

void test()
{
	ARD_TEST_INIT();
	ARD_TEST_EXPECT_EQ(1 + 2, 4);
	ARD_TEST_EXPECT_EQ(1 + 2, 3);
	ARD_TEST_BREAKDOWN();
}

int main()
{
	//Application app;

	//app.run();

	test();

	return 0;
}