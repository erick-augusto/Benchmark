#ifndef RANDOMCL_H
#define RANDOMCL_H

template<typename Tipo>
class RandomCL{
    private:
        Tipo r;
        unsigned char i;
    public:
        RandomCL(unsigned char i) {
            this->i= i;
            reset();
        }
        Tipo nextr() {
            r = 17*r + 23;
            return(r);
        }
        void reset() {
            unsigned short seeds[6] = {4, 81, 151, 1601, 2307, 4207};
            r = seeds[i%6];
        }
};

#endif