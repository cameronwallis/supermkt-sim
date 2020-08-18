#include "customer.hpp"
#include <cstdlib>
#include <ctime>

Customer::Customer() {
    std::srand(std::time(nullptr));
    this->checkout_time = (std::rand() % 180) + 120;
}