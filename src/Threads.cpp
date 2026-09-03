#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex g_Mutex;
static int g_counter = 0;

void IncrementCounter()
{
	g_Mutex.lock();
	g_counter = g_counter + 1;
  g_Mutex.unlock();
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