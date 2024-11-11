#include <iostream>
#include <string>

using namespace std;

struct City {
    string name;
    int population;
    int year_of_foundation;
    int number_of_museums;
};

void input_city(City& city) {
    cout << "Введите название города: ";
    cin >> city.name;

    cout << "Введите количество жителей: ";
    cin >> city.population;

    cout << "Введите год основания: ";
    cin >> city.year_of_foundation;

    cout << "Введите количество музеев: ";
    cin >> city.number_of_museums;
}

void input_city_count(int& num) {
    cout << "Введите количество городов: ";
    cin >> num;
    cout << endl;
}

void input_population_limits(int& min_population, int& max_population) {
    cout << "Введите минимальное количество жителей: ";
    cin >> min_population;
    cout << "Введите максимальное количество жителей: ";
    cin >> max_population;
    cout << endl;
}

void output_filtered_cities(const City cities[], int num_cities, int min_population, int max_population) {
    for (int i = 0; i < num_cities; i++) {
        if (cities[i].population > min_population && cities[i].population < max_population) {
            cout << "Город: " << cities[i].name << endl;
            cout << "Численность населения: " << cities[i].population << endl;
            cout << "Год основания: " << cities[i].year_of_foundation << endl;
            cout << "Количество музеев: " << cities[i].number_of_museums << endl;
            cout << string(24, '_') << endl;
        }
    }
}

int main() {
    int num_cities;
    int min_population;
    int max_population;

    input_city_count(num_cities);

    City* cities = new City[num_cities];

    for (int i = 0; i < num_cities; i++) {
        cout << "Введите информацию о городе #" << i + 1 << ":" << endl;
        input_city(cities[i]);
    }

    input_population_limits(min_population, max_population);

    cout << string(24, '_') << endl;
    cout << "Города с населением более " << min_population << " и менее " << max_population << ":" << endl;
    output_filtered_cities(cities, num_cities, min_population, max_population);

    return 0;
}
