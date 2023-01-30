#include <iostream>
#include <chrono>

#include "ExVectrCore/topic.hpp"
#include "ExVectrCore/topic_subscribers.hpp"
#include "ExVectrCore/scheduler.hpp"
#include "ExVectrCore/time_base.hpp"


int64_t VCTR::timeBase() {

    static auto lastTime = std::chrono::steady_clock::now();//std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now()).count();
    static int64_t timeCount = 0;

    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - lastTime).count();
    if (time > 0) {
        lastTime = std::chrono::steady_clock::now();
        timeCount += time;
    }

    return timeCount;

}


VCTR::Topic<float> testTopic;
VCTR::StaticCallback_Subscriber<float> testSub;
VCTR::ListArray<float> listReceive;

void addToList(const float& item) {

    listReceive.append(item);

    std::cout << "Nums: " << std::endl;

    for (size_t i = 0; i < listReceive.size(); i++) {

        std::cout << i << ": " << listReceive[i] << std::endl;

    }

}


class ThreadTest: public VCTR::Task_Threading {
public:

    ThreadTest() : VCTR::Task_Threading("Test Thread", VCTR::eTaskPriority_Realtime, 1*VCTR::SECONDS) {}

    void thread() {

        testTopic.publish(VCTR::NOWSeconds());

    }

};


int main(int, char**) {
    
    testSub.subscribe(testTopic);
    testSub.setCallbackFunction(addToList);

    ThreadTest test;

    while (VCTR::NOW() < 10*VCTR::SECONDS) {

        VCTR::Task_Threading::schedulerTick();

    }

    std::cout << "Runtime: " << VCTR::NOWSeconds() << std::endl;
 
}
