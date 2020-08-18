#include "checkout_till.hpp"
#include "customer.hpp"
#include <queue>

void Checkout_Till::accept_customer() {
    this->checkout_q.push(Customer());
}