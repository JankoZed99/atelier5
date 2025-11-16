class vect {
protected:
    int nelem;
    int* adr;

public:
    vect(int n) : nelem(n) {
        adr = (n > 0) ? new int[n] : nullptr;
    }

    ~vect() {
        delete[] adr;
    }

    int& operator[](int i) {
        return adr[i];
    }
};

class vectok : public vect {
public:
    vectok(int n = 0) : vect(n) {}

    vectok(const vectok& v) : vect(v.nelem) {
        for (int i = 0; i < nelem; ++i)
            adr[i] = v.adr[i];
    }

    vectok& operator=(const vectok& v) {
        if (this != &v) {
            if (nelem != v.nelem) {
                delete[] adr;
                nelem = v.nelem;
                adr = (nelem > 0) ? new int[nelem] : nullptr;
            }
            for (int i = 0; i < nelem; ++i)
                adr[i] = v.adr[i];
        }
        return *this;
    }

    int taille() const { return nelem; }
};
