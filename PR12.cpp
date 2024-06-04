#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

struct MobilePhone {
    string model;
    int year;
    int ram; // розмір оперативної пам'яті в ГБ
    int storage; // вбудована пам'ять в ГБ
    double price; // ціна в доларах
};

int main() {
    vector<MobilePhone> phones = {
        {"ModelA", 2020, 4, 64, 299.99},
        {"ModelB", 2021, 6, 128, 399.99},
        {"ModelC", 2022, 8, 256, 499.99},
        {"ModelD", 2020, 4, 64, 199.99},
        {"ModelE", 2021, 6, 128, 299.99}
    };

    // Середня ціна усіх телефонів
    double averagePrice = accumulate(phones.begin(), phones.end(), 0.0,
        [](double sum, const MobilePhone& phone) {
            return sum + phone.price;
        }) / phones.size();

    cout << "Average price: $" << averagePrice << endl;

    // Модель з максимальним об'ємом пам'яті
    auto maxStoragePhone = max_element(phones.begin(), phones.end(),
        [](const MobilePhone& a, const MobilePhone& b) {
            return a.storage < b.storage;
        });

    if (maxStoragePhone != phones.end()) {
        cout << "Model with max storage: " << maxStoragePhone->model << " with " << maxStoragePhone->storage << "GB" << endl;
    }

    // Моделі, ціни яких лежать у заданому діапазоні
    double minPrice = 200.0, maxPrice = 400.0;
    cout << "Models with price in range $" << minPrice << " - $" << maxPrice << ":" << endl;
    for_each(phones.begin(), phones.end(),
        [minPrice, maxPrice](const MobilePhone& phone) {
            if (phone.price >= minPrice && phone.price <= maxPrice) {
                cout << phone.model << " ($" << phone.price << ")" << endl;
            }
        });

    // Кількість моделей, випущених в один рік
    int targetYear = 2021;
    int count = count_if(phones.begin(), phones.end(),
        [targetYear](const MobilePhone& phone) {
            return phone.year == targetYear;
        });

    cout << "Number of models released in " << targetYear << ": " << count << endl;

    return 0;
}
