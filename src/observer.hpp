#pragma once

#include <vector>
#include "checkout_till.hpp"

class Observer {
    private:
        Observer(std::vector<Checkout_Till>& t);
        static bool observer_flag;
        int total_queue_length;
        std::vector<int> idle_seconds;
        std::vector<int> queue_length_samples;
    public:
        static Observer *init_observer(std::vector<Checkout_Till>& t);
        void measure(std::vector<Checkout_Till>& t);
        void display(int time, int n_tills);
};