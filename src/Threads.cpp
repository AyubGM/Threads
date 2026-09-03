#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>

static std::atomic<int> g_counter{0};

void IncrementCounter()
{
	g_counter++;
}

int main()
{
	std::vector<std::jthread> threads;

	for (int i = 0; i < 1000; ++i) {
		threads.emplace_back(IncrementCounter);
	}

	threads.clear();

    std::cout << "Final counter value: " << g_counter << "\n";


}