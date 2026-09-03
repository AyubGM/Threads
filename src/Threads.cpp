#include <iostream>
#include <thread>
#include <vector>

int main()
{
	auto Test = [](int x) {
		std::cout << "Hello from thread! = " << std::this_thread::get_id() << "\n";
		std::cout << "Arg = " << x << "\n";
		};


	std::vector<std::thread> threads;

	for (int i = 0; i < 10; ++i) {
		threads.emplace_back(Test, i + 1);
	}

    std::cout << "Hello main!\n";

	for (auto& t : threads) {
		t.join();
	}

}