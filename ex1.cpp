#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <string>

using namespace std;

// ==========================
// 2) Fonction de recherche pour un set<int>
// ==========================
bool contient(const set<int>& ens, int valeur) {
    return ens.find(valeur) != ens.end();
}

// ==========================
// 3) Fonction avec deux iterateurs (set<int>)
// ==========================
bool contient(set<int>::const_iterator debut,
              set<int>::const_iterator fin,
              int valeur) {
    for (auto it = debut; it != fin; ++it)
        if (*it == valeur)
            return true;
    return false;
}

// ==========================
// 4) Version template générique (tout type d’itérateur et valeur)
// ==========================
template <class InputIt, class T>
bool contient(InputIt debut, InputIt fin, const T& valeur) {
    for (auto it = debut; it != fin; ++it)
        if (*it == valeur)
            return true;
    return false;
}

// ==========================
// Programme principal avec exemples d'appel
// ==========================
int main() {

    // 1) Créer un set contenant les entiers de 1 à 100
    set<int> s;
    for (int i = 1; i <= 100; ++i)
        s.insert(i);

    cout << "Test sur set<int> : " << contient(s, 50) << endl;
    cout << "Test via iterateurs : " 
         << contient(s.begin(), s.end(), 75) << endl;


    // Exemples d'appel pour la version template :

    // A) Vecteur de string
    vector<string> vs = {"un", "deux", "trois"};
    cout << "Vecteur<string> contient 'deux' ? "
         << contient(vs.begin(), vs.end(), string("deux")) << endl;

    // B) Liste d'entiers
    list<int> li = { 3, 6, 9, 12 };
    cout << "Liste<int> contient 9 ? "
         << contient(li.begin(), li.end(), 9) << endl;

    // C) Tableau classique de float
    float tab[] = { 1.1f, 2.2f, 3.3f };
    cout << "Tableau float contient 2.2 ? "
         << contient(tab, tab + 3, 2.2f) << endl;

    return 0;
}
