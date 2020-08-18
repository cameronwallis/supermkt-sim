#pragma once

#include <queue>
#include "customer.hpp"

class Checkout_Till {
    private:
        std::queue<Customer> checkout_q;
        int service_timer;

    public:
        Checkout_Till();
        bool idle_flag;
        void tick();
        void accept_customer();
        int queue_size();
};