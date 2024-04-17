#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <fstream>
#include <thread>
#include <future>
using namespace std;

bool func(string write_this, unsigned int this_number){
    for(unsigned int counter = 0; counter < this_number; ++counter){
    cout<<write_this<<endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    }
    return true;
}

int main() {
    unsigned int thread_number = 5;
    std::vector<future<bool>> future_list;
    for(unsigned int counter = 0; counter < thread_number;++counter){
        future_list.push_back(async(launch::async,func, "thread"+std::to_string(counter), 100));
    }

    unsigned int return_counter;

    for(auto& each_future : future_list){
        cout<<each_future.get()<<endl;
    }
    return 0;
}