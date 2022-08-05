#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#endif

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

int countVal = 0;
int threadID = 0;
int sharedSum = 0;
mutex myMutex;
bool wait = true;

void thread_function() {
	
	myMutex.lock();
	int thisThread = threadID;
	threadID++;
	myMutex.unlock();

	for (int i = 0; i < countVal; i++) {
		myMutex.lock();
		cout << "Thread #" << thisThread << ", value " << sharedSum << "\n";
		sharedSum++;
		myMutex.unlock();
		sleep(1);
	}
}

bool isNumeric(string const& input)
{
	return !input.empty() && input.find_first_not_of("0123456789") == string::npos;
}

int main(int argc, char** argv) {

	if (argc != 3) {//guard clause
		cout << "Number of command line args does not meet criteria. Enter number of threads and count value.\n";
		return -1;
	}

	
	if (!isNumeric(argv[1])) {
		cout << "arg 1 is not a digit!\n";
		return -1;
	}
	

	if (atoi(argv[1]) < 1) {
		cout << "Num threads <1. Enter number greater than 1.\n";
		return -1;
	}

	
	if (!isNumeric(argv[2])) {
		cout << "arg 2 is not a digit!\n";
		return -1;
	}
	

	if (atoi(argv[2]) < 1) {
		cout << "Num count <1. Enter number greater than 1.\n";
		return -1;
	}

	int numThreads = atoi(argv[1]);
	countVal = atoi(argv[2]);

	vector<thread> threads;	
	myMutex.lock();

	for (int i = 0; i < numThreads; i++) {
		threads.push_back(thread(thread_function));
	}

	cout << "Sleeping for 10 seconds...\n";
	sleep(10000);
	myMutex.unlock();

	for (int i = 0; i < numThreads; i++) {
		threads.at(i).join();
	}

	return 0;
}

