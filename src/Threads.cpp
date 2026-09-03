#include <iostream>
#include <thread>
#include <vector>

int main()
{
	auto Test = [](int x) {
		std::cout << "Hello from thread! = " << std::this_thread::get_id() << "\n";
		std::cout << "Arg = " << x << "\n";
		};


	std::vector<std::jthread> threads;

	for (int i = 0; i < 1000; ++i) {
		threads.emplace_back(Test, i + 1);
	}

    std::cout << "Hello main!\n";


}