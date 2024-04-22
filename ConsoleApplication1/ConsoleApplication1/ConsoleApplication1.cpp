#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Car {
private:
    string brand;
    string model;
    string price;
public:
    Car(string brand, string model, string price) : brand(brand), model(model), price(price) {}

    string getBrand() const {
        return brand;
    }

    string getModel() const {
        return model;
    }

    string getPrice() const {
        return price;
    }
};


class CarShowroom {
private:
    string name;
    vector<Car> cars;
public:
    CarShowroom(string name) : name(name) {}

    string getName() const {
        return name;
    }

    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void displayCars() const {
        cout << "Автомобили в автосалоне " << name << ":" << endl;
        for (const auto& car : cars) {
            cout << "Марка: " << car.getBrand() << ", Модель: " << car.getModel() << ", Цена: " << car.getPrice() << "Р" << endl;
        }
    }
};


void addCarToShowroom(vector<CarShowroom>& showrooms) {
    string showroomName, brand, model;
    string price;

    cout << "Введите название автосалона: ";
    cin >> showroomName;

    auto it = find_if(showrooms.begin(), showrooms.end(), [&](const CarShowroom& s) {
        return s.getName() == showroomName;
        });

    if (it == showrooms.end()) {
        CarShowroom newShowroom(showroomName);
        showrooms.push_back(newShowroom);
        it = showrooms.end() - 1; 
    }

    cout << "Введите марку автомобиля: ";
    cin >> brand;
    cout << "Введите модель автомобиля: ";
    cin >> model;
    cout << "Введите цену автомобиля: ";
    cin >> price;

   
    Car car(brand, model, price);
    it->addCar(car);

    cout << "Автомобиль успешно поступил в автосалон!" << endl;
}


void displayCarsInShowroom(const vector<CarShowroom>& showrooms) {
    string showroomName;
    cout << "Введите название выставочного зала: ";
    cin >> showroomName;

    for (const auto& showroom : showrooms) {
        if (showroom.getName() == showroomName) {
            showroom.displayCars();
            return;
        }
    }

    cout << "Автосалон не найден!" << endl;
}

int main() {
    vector<CarShowroom> showrooms;
    setlocale(LC_ALL, "Russian");

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить автомобиль в автосалон\n";
        cout << "2. Демонстрация автомобилей в автосалоне\n";
        cout << "3. Выход\n";
        cout << "Введите свой выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addCarToShowroom(showrooms);
            break;
        case 2:
            displayCarsInShowroom(showrooms);
            break;
        case 3:
            cout << "До сивдания!" << endl;
            break;
        default:
            cout << "Неверный выбор! Пожалуйста, введите еще раз." << endl;
        }
    } while (choice != 3);

    return 0;
}