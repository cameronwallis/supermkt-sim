#pragma once

#include <vector>
#include "checkout_till.hpp"

class Observer {
    private:
        Observer();
        static bool observer_flag;
        int total_queue_length;
    public:
        static Observer *init_observer();
        void measure(std::vector<Checkout_Till>& t);
        void display(int time, int n_tills);
};