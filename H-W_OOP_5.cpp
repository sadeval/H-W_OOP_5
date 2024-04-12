#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

class Lizard {

    string animalClass;
    string suborder;
    string family;
    int* bodyLength = nullptr;
    int bodyLengthCount = 0;

public:

    Lizard(const Lizard& original) {
        cout << "COPY C-TOR\n";

        this->animalClass = original.animalClass;
        this->suborder = original.suborder;
        this->bodyLengthCount = original.bodyLengthCount;

        this->bodyLength = new int[this->bodyLengthCount];

        for (int i = 0; i < this->bodyLengthCount; i++)
        {
            this->bodyLength[i] = original.bodyLength[i];
        }

    }

    Lizard(string animalClass, string suborder) {
        this->animalClass = animalClass;
        this->suborder = suborder;
        bodyLengthCount = 10;
        bodyLength = new int[bodyLengthCount];
        for (int i = 0; i < bodyLengthCount; i++)
        {
            bodyLength[i] = rand() % 70 + 11;
        }
    }

    Lizard() : Lizard("Reptilia", "Iguania", "Agamidae") {}
    // main c-tor
    Lizard(string animalClass, string suborder, string family) {
        SetAnimalClass(animalClass);
        SetSuborder(suborder);
        SetFamily(family);
        SetBodyLength(26);
    }

    void Print() const {
        cout << "Animal class: " << animalClass << "\n";
        cout << "Suborder: " << suborder << "\n";
        cout << "Body length: ";
        for (int i = 0; i < bodyLengthCount; i++)
        {
            cout << bodyLength[i] << ", ";
        }
        cout << "\n\n";
    }

    void SetAnimalClass(string animalClass) {
        this->animalClass = animalClass;
    }
    string GetSetAnimalClass() const {
        return animalClass;
    }

    void SetSuborder(string suborder) {
        this->suborder = suborder;
    }
    string GetSuborder() const {
        return suborder;
    }

    void SetFamily(string family) {
        this->family = family;
    }
    string GetFamily() const {
        return family;
    }

    void SetBodyLength(int bodyLength) {
        if (bodyLength < 5 || bodyLength > 70) throw "ERROR!";
        *this->bodyLength = bodyLength;
    }
    int GetBodyLength() const {
        return *bodyLength;
    }

    void Swim(string temperature) {
        cout << "Heat the bath to " << temperature << "\n";
    }

    void Eat(string insect) {
        cout << "Catch the " << insect << "\n";
    }

    void Gestures(string head_bob) {
        cout << "Violent bob " << head_bob << "\n";
    }

    ~Lizard() {
        cout << "The lizard ran away\n";
        delete[] bodyLength;
    }

};


class Hospital {

    string name;
    string location;
    int* availableBeds = nullptr;
    int bedsCount = 0;
    double rating;

public:

    Hospital(const Hospital& original) {
        cout << "COPY C-TOR\n";

        this->name = original.name;
        this->location = original.location;
        this->bedsCount = original.bedsCount;

        this->availableBeds = new int[this->bedsCount];

        for (int i = 0; i < this->bedsCount; i++)
        {
            this->availableBeds[i] = original.availableBeds[i];
        }

    }

    Hospital(string name, string location) {
        this->name = name;
        this->location = location;
        bedsCount = 5;
        availableBeds = new int[bedsCount];
        for (int i = 0; i < bedsCount; i++)
        {
            availableBeds[i] = rand() % 10 + 1;
        }
    }

    Hospital() : Hospital("Tropinka", "Kherson", 10) {}
    // main c-tor
    Hospital(string name, string location, int availableBeds) {
        SetName(name);
        SetLocation(location);
        SetBeds(availableBeds);
        SetRating(4.3);
    }

    void Print() const {
        cout << "Hospital's name: " << name << "\n";
        cout << "Location: " << location << "\n";
        cout << "Total beds: ";
        for (int i = 0; i < bedsCount; i++)
        {
            cout << availableBeds[i] << ", ";
        }
        cout << "\n\n";
    }

    void SetName(string name) {
        this->name = name;
    }
    string GetName() const {
        return name;
    }

    void SetLocation(string location) {
        this->location = location;
    }
    string GetLocation() const {
        return location;
    }

    void SetBeds(int availableBeds) {
        if (availableBeds < 0 || availableBeds > 20) throw "ERROR!";
        *this->availableBeds = availableBeds;
    }
    int GetBeds() const {
        return *availableBeds;
    }

    void SetRating(double rating) {
        if (rating < 0 || rating > 5) throw "ERROR!";
        this->rating = rating;
    }
    double GetRating() const {
        return rating;
    }

    void DoctorsAppointment(string doctor) {
        cout << "Choose a doctor: " << doctor << "\n";
    }

    void Examinations(string exam) {
        cout << "Choose an examination: " << exam << "\n";
    }

    void Registry(string reg) {
        cout << "Call the reception: " << reg << "\n";
        Sleep(1000);
        cout << "...subscriber is temporary unavailable, please call later...\n";
        Sleep(1000);
    }

    ~Hospital() {
        cout << "Hospital is closed\n";
        delete[] availableBeds;
    }
};

int main() {

    Lizard vitticeps("Reptilia", "Iguania");
    vitticeps.Print();
    Lizard copy = vitticeps;
    copy.Print();

    Hospital tropinka("Tropinka", "Kherson");
    tropinka.Print();
    Hospital duplicate = tropinka;
    duplicate.Print();

}