#include "observer.hpp"
#include "checkout_till.hpp"
#include <vector>
#include <iostream>
#include <cmath>

bool Observer::observer_flag = false;

Observer::Observer(std::vector<Checkout_Till>& t) : total_queue_length(0) {
    for (int i = 0; i < t.size(); ++i) {
        this->idle_seconds.push_back(0);
    }
}

Observer *Observer::init_observer(std::vector<Checkout_Till>& t) {
    if (Observer::observer_flag) {
        return nullptr;
    } else {
        Observer::observer_flag = true;
        return new Observer(t);
    }
}

void Observer::measure(std::vector<Checkout_Till>& t) {
    for (int i = 0; i < t.size(); ++i) {
        this->total_queue_length += t[i].queue_size();
        this->queue_length_samples.push_back(t[i].queue_size());
        if (t[i].idle_flag) {
            this->idle_seconds[i]++;
        }
    }
}

void Observer::display(int time, int n_tills) {
    double avg_q_len = static_cast<double>(this->total_queue_length) / (static_cast<double>(time) * static_cast<double>(n_tills));
    std::cout << "Avg queue length = " << avg_q_len << std::endl;

    int sum_of_samples = 0;

    for (auto&n : this->queue_length_samples) {
        int sample = (n - avg_q_len) * (n - avg_q_len);
        sum_of_samples += sample;
    }

    double variance = static_cast<double>(sum_of_samples) / static_cast<double>(this->queue_length_samples.size());
    double stddev = std::sqrt(variance);

    std::cout << "sigma = " << stddev << std::endl;


    for (int i = 0; i < this->idle_seconds.size(); ++i) {
        std::cout << "Till " << i + 1 << " idle for " << this->idle_seconds[i] << "s" << std::endl;
    }

}