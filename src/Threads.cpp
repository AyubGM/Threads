#include <iostream>
#include <thread>




int main()
{
	auto Test = [](int x) {
		std::cout << "Hello from thread! x = " << x << "\n";
		};
	std::thread myThread(Test, 1);


    std::cout << "Hello main!\n";
    myThread.join();

}