#include "Fruit.hpp"
#include <vector>


using namespace std;
	
int main() {
    
    vector<Fruit*> fruit;//init vector

    fruit.push_back(new Fruit());//add elements
    fruit.push_back(new Banana());
    fruit.push_back(new Tangerine());
    fruit.push_back(new Pear());

    for (auto f : fruit) {//identify each element
        f->Identify();
        delete f;//release memory
    }

	return 0;
}