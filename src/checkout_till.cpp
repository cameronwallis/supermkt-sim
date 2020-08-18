#include "checkout_till.hpp"
#include "customer.hpp"
#include <queue>

Checkout_Till::Checkout_Till() : idle_flag(true), service_timer(0){
}

void Checkout_Till::accept_customer() {
    this->checkout_q.push(Customer());
}

void Checkout_Till::tick() {
    if (this->service_timer <= 0) {
        if (!this->checkout_q.empty()) {            
            this->service_timer = this->checkout_q.front().checkout_time;
            this->checkout_q.pop();
            this->idle_flag = false;
        } else {
            this->idle_flag = true;
        }
    } else {
        --this->service_timer;
    }
}