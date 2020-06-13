#include <iostream>
#include <condition_variable>
#include <thread>

std::condition_variable cv;
std::mutex mtx;
bool isReady = false;


void waitForReady() {
  std::cout << " wait for ready ..." << std::endl;  
  std::unique_lock<std::mutex> lk(mtx);
  cv.wait(lk, []() { return isReady; });
  std::cout << " run ..." << std::endl;  
}

void setReady() {
  std::cout << " begin set " << std::endl;  
  {
    std::lock_guard<std::mutex> lk(mtx);
    isReady = true;
  }
  cv.notify_one();
  std::cout << " set ready finish " << std::endl;  
}


int main() {
  std::thread t1(waitForReady);
  std::thread t2(setReady);
  t1.join();
  t2.join();

  return 0;  
}
