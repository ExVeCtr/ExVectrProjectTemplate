#include <iostream>

#include "ExVectrCore/topic.hpp"
#include "ExVectrCore/topic_subscribers.hpp"
#include "ExVectrCore/scheduler.hpp"
#include "ExVectrCore/time_base.hpp"

#include "ExVectrCore/scheduler2.hpp"
#include "ExVectrCore/task_types.hpp"

#include "ExVectrWindowsPlatform.hpp"


VCTR::Core::Topic<float> testTopic;
VCTR::Core::StaticCallback_Subscriber<float> testSub;
VCTR::Core::ListArray<float> listReceive;

void addToList(const float& item) {

    listReceive.append(item);

    std::cout << "Nums: " << std::endl;

    for (size_t i = 0; i < listReceive.size(); i++) {

        std::cout << i << ": " << listReceive[i] << std::endl;

    }

}


class ThreadTest: public VCTR::Core::Task_Periodic {
public:

    VCTR::Core::Scheduler& sp;

    ThreadTest(VCTR::Core::Scheduler& s) : VCTR::Core::Task_Periodic("Scheduler and task test", 1*VCTR::Core::SECONDS, 0, 3*VCTR::Core::SECONDS), sp(s) {}

    void init() override {

    }

    void thread() override {

        //testTopic.publish(VCTR::Core::NOWSeconds());
        std::cout << "HELLO: " << VCTR::Core::NOWSeconds() << std::endl;

        if (VCTR::Core::NOWSeconds() > 5.0f) {
            sp.removeTask(*this);
        }

    }

};


int main(int, char**) {

    VCTR::Core::Scheduler scheduler;
    ThreadTest test(scheduler);
    scheduler.addTask(test);
    
    testSub.subscribe(testTopic);
    testSub.setCallbackFunction(addToList);

    

    while (VCTR::Core::NOW() < 10*VCTR::Core::SECONDS) {

        //VCTR::Core::Task_Threading::schedulerTick();
        scheduler.tick();

    }

    std::cout << "Runtime: " << VCTR::Core::NOWSeconds() << std::endl;

    return 0;
 
}
