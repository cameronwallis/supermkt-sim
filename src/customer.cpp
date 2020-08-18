#include "customer.hpp"
#include <cstdlib>

Customer::Customer() {
    std::srand(std::time(nullptr));
    this->checkout_time = (std::rand() % 180) + 120;
}