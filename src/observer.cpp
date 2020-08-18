#include "observer.hpp"
#include "checkout_till.hpp"
#include <vector>
#include <iostream>

bool Observer::observer_flag = false;

Observer::Observer() : total_queue_length(0) {

}

Observer *Observer::init_observer() {
    if (Observer::observer_flag) {
        return nullptr;
    } else {
        Observer::observer_flag = true;
        return new Observer();
    }
}

void Observer::measure(std::vector<Checkout_Till>& t) {
    for (int i = 0; i < t.size(); ++i) {
        this->total_queue_length += t[i].queue_size();
    }
}

void Observer::display(int time, int n_tills) {
    double avg_q_len = static_cast<double>(this->total_queue_length) / (static_cast<double>(time) * static_cast<double>(n_tills));
    std::cout << "Avg queue length = " << avg_q_len << std::endl;
}