#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <string>
#include <cmath>

using namespace std;

const int MAX_BUS_VEHICLES = 10;
const int MAX_CAR_VEHICLES = 15;
const int MAX_TRUCK_VEHICLES = 5;

//Bus

class Bus
{
private:
    string model;
    unsigned int seats;
public:
    int x = 0, y = 0;

    Bus(string _model, int _seats) : model(_model), seats(_seats)
    {
    }

    Bus() : Bus("", 0) {}

    string GetModel() { return model; }

    int GetSeats() { return seats; }

    void Set(string _model, int _seats)
    {
        model = _model;
        seats = _seats;
    }
    void Print()
    {
        cout << "\nАвтобус на станції.\n" << "модель: " << model << ", сидінь: " << seats << endl;
    }
    void Print_cords()
    {
        cout << "\nАвтобус не на станції!!\n" "модель: " << model << ", сидінь: " << seats << " координати: (" << this->x << "," << this->y << ")" << endl;
    }
    int get_distance()
    {
        return pow(pow((this->x - 0), 2.0) + pow((this->y - 0), 2.0), 0.5);
    }
    void print_distance()
    {
        int dis = get_distance();
        cout << "Відстань між станцією та автобусом моделі - " << model << " з кількістью посадочних місць - " << seats << " це (" << dis << ") одиниць!\n";
    }
};

//Car

class Car
{
private:
    string model;
public:
    int x = 0, y = 0;

    Car(string _model) :model(_model)
    {
    }
    Car() : Car("")
    {
    }
    string GetModel() { return model; }
    void SetModel(string _model)
    {
        model = _model;
    }
    void Print()
    {
        cout << "\nМашина на станції.\n" << "Модель: " << model << endl;
    }
    void Print_cords()
    {
        cout << "\nМашина не на станції!!\n" << " Модель: " << model << " координати: (" << this->x << "," << this->y << ")" << endl;
    }
    int get_distance()
    {
        return pow(pow((this->x - 0), 2.0) + pow((this->y - 0), 2.0), 0.5);
    }
    void print_distance()
    {
        int dis = get_distance();
        cout << "Відстань між станцією та машиною моделі - " << model << " це (" << dis << ") одиниць!\n";
    }
};

//Truck

class Truck
{
private:
    string model;
public:

    int x = 0, y = 0;

    Truck(string _model) :model(_model)
    {
    }
    Truck() : Truck("")
    {
    }
    string GetModel() { return model; }
    void SetModel(string _model)
    {
        model = _model;
    }
    void Print()
    {
        cout << "\nВантажівка на станції.\n" << "модель: " << model << endl;
    }
    void Print_cords()
    {
        cout << "\nВантажівка не на станції!!\n" << " Модель: " << model << " координати: (" << this->x << "," << this->y << ")" << endl;
    }
    int get_distance()
    {
        return pow(pow((this->x - 0), 2.0) + pow((this->y - 0), 2.0), 0.5);
    }
    void print_distance()
    {
        int dis = get_distance();
        cout << "Відстань між станцією та вантажівкою моделі - " << model << " це (" << dis << ") одиниць!\n";
    }
};

//station

class Station
{
public:
    vector <Bus> B;
    vector <Car> C;
    vector <Truck> T;
    //Bus
    Bus GetBus(unsigned int number)
    {
        if (number < B.size())
            return B[number];
        else
        {
            cout << "Помилка в номері автобуса" << endl;
            return Bus("", 0);
        }
    }

    void AddBus(string model, unsigned int seats)
    {
        if (B.size() < MAX_BUS_VEHICLES)
        {
            Bus temp(model, seats);
            B.push_back(temp);
            cout << "Новий автобус додано!" << endl;
        }
        else
        {
            cout << "Не можливо додати новий автобус" << endl;
            return;
        }
    }

    void DelBus(unsigned int number)
    {
        if (number <= B.size())
        {
            B.erase(B.begin() + (number + 1));
            cout << "автобус видалено!" << endl;
        }
    }

    void GoBus(unsigned int number) {
        B[number].x = 1 + (rand() % 10);
        B[number].y = 1 + (rand() % 10);
    }

    //Car
    Car GetCar(unsigned int number)
    {
        if (number < C.size())
            return C[number];
        else
        {
            cout << "Помилка в номері автівки!" << endl;
            return Car("");
        }
    }

    void AddCar(string model)
    {
        if (C.size() < MAX_CAR_VEHICLES)
        {
            Car temp(model);
            C.push_back(temp);
            cout << "Нове авто додане!" << endl;
        }
        else
        {
            cout << "Не можливо додати нове авто!" << endl;
            return;
        }
    }

    void DelCar(unsigned int number)
    {
        if (number < C.size())
        {
            C.erase(C.begin() + (number + 1));
            cout << "вантажівку видалено!" << endl;
        }
    }

    void GoCar(unsigned int number) {
        C[number].x = 1 + (rand() % 10);
        C[number].y = 1 + (rand() % 10);
    }
    //Truck

    Truck GetTruck(unsigned int number)
    {
        if (number < T.size())
            return T[number];
        else
        {
            cout << "Помилка в номері вантажівки!" << endl;
            return Truck("");
        }
    }

    void AddTruck(string model)
    {
        if (T.size() < MAX_TRUCK_VEHICLES)
        {
            Truck temp(model);
            T.push_back(temp);
            cout << "Нова вантажівка додана!" << endl;
        }
        else
        {
            cout << "Не можливо додати нову вантажівку!" << endl;
            return;
        }
    }

    void DelTruck(unsigned int number)
    {
        if (number < T.size())
        {
            T.erase(T.begin() + (number + 1));
            cout << "вантажівку видалено!" << endl;
        }
    }

    void GoTruck(unsigned int number) {
        T[number].x = 1 + (rand() % 10);
        T[number].y = 1 + (rand() % 10);
    }
    //Print
    void Print()
    {
        cout << "Відомості про автостанцію:" << endl;
        if (B.empty()) {
            cout << "Станція для автобусів пуста!" << endl;
        }
        else {
            cout << "\nКількість автобусів = " << B.size() << endl;
            if (B.size() > 0)
            {
                cout << "Відомості про автобуси:" << endl;
                for (int i = 0; i < B.size(); i++)
                {
                    if (B[i].x == 0 && B[i].y == 0)
                    {
                        B[i].Print();
                    }
                    else
                    {
                        B[i].Print_cords();
                    }
                }
            }
        }
        if (C.empty()) {
            cout << "Станція для автівок пуста!" << endl;
        }
        else {
            cout << "\nКількість автомобілів = " << C.size() << endl;
            if (C.size() > 0)
            {
                cout << "Відомості про автомобілі:" << endl;
                for (int i = 0; i < C.size(); i++)
                {
                    if (C[i].x == 0 && C[i].y == 0)
                    {
                        C[i].Print();
                    }
                    else
                    {
                        C[i].Print_cords();
                    }
                }
            }
        }
        if (T.empty()) {
            cout << "Станція для вантажівок пуста!" << endl;
        }
        else {
            cout << "\nКількість вантажівок = " << T.size() << endl;
            if (T.size() > 0)
            {
                cout << "Відомості про вантажівки:" << endl;
                for (int i = 0; i < T.size(); i++)
                {
                    if (T[i].x == 0 && T[i].y == 0)
                    {
                        T[i].Print();
                    }
                    else
                    {
                        T[i].Print_cords();
                    }
                }
            }
        }

    }

    void Write(string path = "file.txt") {
        ofstream fout(path);
        fout << B.size() << "\n";

        for (size_t i = 0; i < B.size(); i++)
        {
            fout << B[i].GetModel() << "\n" << B[i].GetSeats() << "\n";

        }

        fout << C.size() << "\n";

        for (size_t i = 0; i < C.size(); i++)
        {
            fout << C[i].GetModel() << "\n";

        }

        fout << T.size() << "\n";

        for (size_t i = 0; i < T.size(); i++)
        {
            fout << T[i].GetModel() << "\n";

        }

        fout.close();
    }

    void Read(string path = "file.txt") {
        ifstream fin(path);

        if (!fin.is_open())
        {
            cout << "can`t open this file\n";
        }
        else
        {
            int size;
            string model;
            int seats;
            fin >> size;
            getline(fin, model);
            if (size != 0)
            {
                for (size_t i = 0; i < size; i++)
                {
                    getline(fin, model);
                    fin >> seats;
                    this->AddBus(model, seats);
                    getline(fin, model);
                }
            }

            fin >> size;
            getline(fin, model);
            if (size != 0)
            {
                for (size_t i = 0; i < size; i++)
                {
                    getline(fin, model);
                    this->AddCar(model);
                }
            }

            fin >> size;
            getline(fin, model);
            if (size != 0)
            {
                for (size_t i = 0; i < size; i++)
                {
                    getline(fin, model);
                    this->AddTruck(model);
                }
            }
        }
        fin.close();
    }
};


int main() { // Щоб додати новий транспортний засіб потрібно просто викликати один із методів:
            //s.AddBus("модель", кіль-ість місць);  s.AddTruck("модель"); s.AddCar("модель");
            // і програма автоматично запише його у файл
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Station s;
    cout << "ініцалізація попередньої інформації:\n";
    s.Read(); // зчитування інформації попереднього сеансу
    cout << endl << endl << endl;
    s.GoCar(1);
    s.GoCar(2);
    s.GoBus(1);
    s.GoTruck(1);
    s.Print();

    //s.AddBus("Mercedes", 6);
    //s.AddTruck("Volkswagen");
    //s.AddCar("Audi");

     //s.Print();

    cout << endl << endl << endl;

    s.C[1].print_distance();
    cout << endl;
    s.B[1].print_distance();
    cout << endl;
    s.T[1].print_distance();

    cout << endl << endl << endl;
    cout << "запис поточної інформації про сеанс:\n";
    s.Write(); //запис поточної інформації про сеанс
    cout << "запис завершено\n\n\n";
}