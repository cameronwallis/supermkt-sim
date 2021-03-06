#include <iostream>
#include <getopt.h>
#include <cstdlib>
#include <ctime>

#include "customer.hpp"
#include "checkout_till.hpp"
#include "observer.hpp"

void print_help();

int main(int argc, char **argv) {

    int opt = 0;
    int open_time = 0;
    int n_tills = 0;

    while ((opt = getopt(argc, argv, "ht:n:")) != -1) {
        switch (opt) {
            case 'h':
                print_help();
                exit(EXIT_SUCCESS);
            case 't':
                open_time = atoi(optarg);
                break;
            case 'n':
                n_tills = atoi(optarg);
                break;
        }
    }

    if (open_time == 0) {
        std::cerr << "ERROR: Shop cannot have 0 open time!" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (n_tills <= 0) {
        std::cerr << "WARN: Setting number of tills to 1" << std::endl;
        n_tills = 1;
    }

    int open_time_s = open_time * 60 * 60;
    
    std::vector<Checkout_Till> tills;

    for (int i = 0; i < n_tills; ++i) {
        tills.push_back(Checkout_Till());
    }

    Observer *O = Observer::init_observer(tills);

    std::srand(std::time(nullptr));

    int new_customer_timer = 0;

    std::cout << "Simulating...  0%";

    for (int i = open_time_s; i > 0; --i) {
        std::cout << "\rSimulating...  " << ((open_time_s - i) * 100 )/ open_time_s << "%";
        if (new_customer_timer == 0) {
            int till_number = std::rand() % (tills.size());
            tills[till_number].accept_customer();
            new_customer_timer = (std::rand() % 330) + 30;
        } else {
            --new_customer_timer;
        }
        for (int j = 0; j < tills.size(); ++j) {
            tills[j].tick();
        }
        O->measure(tills);
    }

    std::cout << std::endl;
    std::cout << "Calculating..." << std::endl;
    O->display(open_time_s, tills.size());

    return 0;
}

void print_help() {
    std::cout << "help" << std::endl;
}