/*

Имеется N аэропортов, где N <=10 . о каждом известно название и марки самолетов, которые есть в этом
аэропорту. О каждом самолете известна марка, число посадочных мест. Вывести название аэропортов,
имеющих все марки самолетов, название, название  самолетов, которых нет ни в одном аэропорту
и по каждому аэропорту  суммарное количество пассажиров, которое перевозится самолетами этого аэропорта.
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
/*
map<string, int> Brands = { {"d",200} };
*/

map<string, int> Brands;

vector<string> all() {
    vector<string> result;
    for (const auto& El : Brands) {
        result.push_back(El.first);
    }
    return result;
}

class Plane {
public:
    Plane() {};

    Plane(const string& brand, const int& seats) {
        Brand = brand;
        Seats = seats;
    }

    string GetBrand() const {
        return Brand;
    }

    int GetSeats() const {
        return Seats;
    }

private:
    string Brand;
    int Seats;
};

int IsDigit(const string& s);

istream& operator>>(istream& is, Plane& plane) {
    cout << "Write brand of a plane: ";
    string brand;
    is >> brand;
    if (Brands.count(brand) == 0) {
        cout << "Write number of seats for plane " << brand << ": ";
        string seatd;
        is >> seatd;

        int seat = IsDigit(seatd);

        Brands[brand] = seat;
    }
    Plane plane2(brand, Brands[brand]);
    plane = plane2;
    return is;
}

ostream& operator<<(ostream& os, const Plane& plane) {
    os << plane.GetBrand() << " with " << plane.GetSeats() << " seats";
    return os;
}

bool operator<(const Plane& lhs, const Plane& rhs) {
    return lhs.GetBrand() < rhs.GetBrand();
}

bool operator==(const Plane& lhs, const Plane& rhs) {
    return (lhs.GetBrand() == rhs.GetBrand() && lhs.GetSeats() == rhs.GetSeats());
}

bool operator!=(const Plane& lhs, const Plane& rhs) {
    return (!(lhs == rhs));
}

template <class T>
class Airport {
public:
    Airport(const string& title) {
        Title = title;
        sum = 0;
    }

    void InitializerPlanes() {
        cout << "Write number of planes: ";
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            T j;
            cin >> j;
            AddPlane(j);
            sum += j.GetSeats();
        }
    }

    void AddPlane(const T& n) {
        bool nonexist = true;
        for (const T& t : Planes) {
            if (t == n) {
                nonexist = false;
            }
        }
        if (nonexist) {
            Planes.push_back(n);
        }
        sum += n.GetSeats();
    }

    void RemovalPlane(const T& n) {
        vector<T> result;
        for (const T& t : Planes) {
            if (t != n) {
                result.push_back(t);
            }
        }
        Planes = result;
        sum -= n.GetSeats();
    }

    vector<T> Unification(const vector<T>& num) {
        vector<T> result;
        for (const T& i : num) {
            result.AddPlane(i);
        }
        for (const T& i : Planes) {
            result.AddPlane(i);
        }
        return result;
    }

    vector<T> Intersection(const vector<T>& num) {
        vector<T> result;
        for (const T& i : num) {
            if (find(Planes.begin(), Planes.end(), i) != Planes.end()) {
                result.Plane(i);
            }
        }
        return result;
    }

    bool EntryPlane(const T& n) const {
        return (find(Planes.begin(), Planes.end(), n) != Planes.end());
    }

    string GetTitle() const {
        return Title;
    }

    int GetSum() const {
        return sum;
    }

    template <class O>
    friend ostream& operator<<(ostream& os, const Airport<O>& t);

    template <class C>
    friend bool IsAirportIncludesAllKindsOfPlanes(const Airport<C>& a);

    template <typename K>
    friend void PrintAllAirportsWithTheirSeats(const vector<Airport<K>>& Airports);

    template <class P>
    friend void PlanesAreNotInAnyAirport(const vector<Airport>& Air);

private:
    string Title;
    vector<T> Planes;
    int sum;
};

template <class T>
istream& operator>>(istream& is, Airport<T>& t) {
    cout << "Write number of planes: ";
    int n;
    is >> n;
    for (int i = 0; i < n; ++i) {
        T j;
        is >> j;
        t.Add(j);
    }
    return is;
}

template <class T>
ostream& operator<<(ostream& os, const Airport<T>& t) {
    for (const T& i : t.Planes) {
        os << i << "\t";
    }
    return os;
}

Plane MakePlaneByString(const string& s) {
    Plane p(s, Brands[s]);
    return p;
}

int IsDigit(const string& s) {
    int result = 0;
    for (const char& ch : s) {
        if (!(isdigit(ch))) {
            throw invalid_argument("Enter a NUMBER!!!");
        }
        else {
            result *= 10;
            result += ch - '0';
        }
    }
    return result;
}

template <class C>
bool IsAirportIncludesAllKindsOfPlanes(const Airport<C>& a) {
    for (const string& c : all()) {
        if (!(a.EntryPlane(MakePlaneByString(c)))) {
            return false;
        }
    }
    return true;
}

template <class P>
void PlanesAreNotInAnyAirport(const vector<P>& Air) {
    vector<string> v;
    for (const string& s : all()) {
        bool exist = false;
        for (const P& a : Air) {
            if (a.EntryPlane(MakePlaneByString(s))) {
                exist = true;
            }
        }
        if (!(exist)) {
            v.push_back(s);
        }
    }
    if (v.size() == 0) {
        return;
    }
    cout << "No planes:\n";
    for (const string& t : v) {
        cout << t << "\t";
    }
    cout << endl << endl;
}

template <typename K>
void PrintAllAirportsWithTheirSeats(const vector<Airport<K>>& Airports) {
    if (Airports.size() > 0) {
        cout << "All airports with their sum of seats:\n";
    }
    for (const Airport<K>& p : Airports) {
        cout << p.Title << "\t" << p.sum << endl;
    }
}

int main() {
    Brands["p3"] = 2;

    try {
        vector<Airport<Plane>> Airports;
        string Nd;
        cout << "Write number of airports: ";
        cin >> Nd;

        int N = IsDigit(Nd);

        for (int i = 0; i < N; ++i) {
            cout << "Write a title for airport #" << i + 1 << ": ";
            string title;
            cin >> title;
            Airport<Plane> a(title);
            cout << "Write number of planes in airport " << title << ": ";
            string nd;
            cin >> nd;

            int n = IsDigit(nd);

            for (int j = 0; j < n; ++j) {
                Plane p;
                cin >> p;
                a.AddPlane(p);
            }
            Airports.push_back(a);
        }

        cout << endl;
        bool first = true;
        for (const Airport<Plane>& a : Airports) {
            if (IsAirportIncludesAllKindsOfPlanes(a)) {
                if (first) {
                    cout << "Airports with all brands:\n";
                    first = false;
                }
                cout << a.GetTitle() << endl;
            }
        }
        if (!(first)) {
            cout << endl;
        }

        PlanesAreNotInAnyAirport(Airports);

        PrintAllAirportsWithTheirSeats(Airports);
    }
    catch (exception& ex) {
        cerr << ex.what();
    }
    return 0;
}
