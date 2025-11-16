set<int> s;
for(int i = 1; i <= 100; i++)
    s.insert(i);
bool rechercher(const set<int>& s, int val) {
    return s.find(val) != s.end();
}
bool rechercher_it(set<int>::iterator deb, set<int>::iterator fin, int val) {
    for (auto it = deb; it != fin; ++it)
        if (*it == val) return true;
    return false;
}
template <class It, class T>
bool rechercher_gen(It deb, It fin, T val) {
    for (auto it = deb; it != fin; ++it)
        if (*it == val) return true;
    return false;
}
