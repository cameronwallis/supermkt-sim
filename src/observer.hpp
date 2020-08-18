#pragma once

class Observer {
    private:
        Observer();
    public:
        static Observer *init_observer();
        void measure();
}