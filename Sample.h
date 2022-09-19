#ifndef SAMPLE_H
#define SAMPLE_H

#include <iostream>

class Sample{
    public:

        Sample();
        Sample(int v);
        Sample(Sample const &other);

        Sample& operator=(Sample const &other);

        void setValue(int v);
        int getValue();
        void removeValue();

        ~Sample();

    private:
        int* val_ptr;
};

#endif
