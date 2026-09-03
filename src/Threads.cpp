#include <iostream>
#include <thread>

void Test(int x) {
	std::cout << "Hello from thread! x = " << x << std::endl;
}


int main()
{
	std::thread myThread(Test, 42);

    std::cout << "Hello main!\n";
    myThread.join();
}