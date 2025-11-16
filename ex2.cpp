class Test {
public:
    static int tableau[];

    static int division(int indice, int diviseur) {
        const int TAILLE = 10;

        if (indice < 0 || indice >= TAILLE)
            throw out_of_range("Indice hors limites");

        if (diviseur == 0)
            throw runtime_error("Division par zero");

        return tableau[indice] / diviseur;
    }
};

int Test::tableau[] = {17, 12, 15, 38, 29, 157, 89, -22, 0, 5};
