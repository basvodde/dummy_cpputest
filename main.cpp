
#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestRegistry.h"


class MyPlugin: public TestPlugin {
    int* dummy_;
public:
    MyPlugin() :
            TestPlugin("MyPlugin")
    {
        dummy_ = (int*) malloc(100*sizeof(int));
    }
    virtual ~MyPlugin()
    {
        free(dummy_);
    }

};

int main(int argc, char** argv)
{
	MyPlugin m;
	TestRegistry::getCurrentRegistry()->installPlugin(&m);

	return CommandLineTestRunner::RunAllTests(argc, argv);
}
