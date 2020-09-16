#include "apppch.h"
#include "Application.h"
#include "tests.h"

void test()
{
	ARD_PROFILE_FUNCTION();

	ARD_TEST_INIT();
	ARD_TEST_BREAKDOWN();
}

int main()
{
	ARD_PROFILE_FUNCTION();

	Application app;

	//app.run();

	test();

	return 0;
}