#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <climits>
#include<locale>
using namespace std;

struct Animal {
    string owner;
    string type;
    string name;
    int age;
};


void trim(string& s) {
    if (s.empty()) return;

    
    size_t start = 0;
    while (start < s.size() && isspace(static_cast<unsigned char>(s[start]))) {
        start++;
    }

    
    size_t end = s.size();
    while (end > start && isspace(static_cast<unsigned char>(s[end - 1]))) {
        end--;
    }

    s = s.substr(start, end - start);
}


vector<Animal> readAnimals(const string& filename) {
    ifstream file(filename);
    vector<Animal> animals;
    string line;

    while (getline(file, line)) {
        
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        vector<string> fields;
        stringstream ss(line);
        string field;

        while (getline(ss, field, ',')) {
            trim(field);
            fields.push_back(field);
        }

        if (fields.size() < 4) continue;

        Animal animal;
        animal.owner = fields[0];
        animal.type = fields[1];
        animal.name = fields[2];
        animal.age = -1;

        
        if (!fields[3].empty()) {
            try {
                animal.age = stoi(fields[3]);
            }
            catch (...) {
                
            }
        }
        animals.push_back(animal);
    }
    return animals;
}

int main() {
    
    setlocale(LC_ALL, "rus");
    vector<Animal> animals = readAnimals("input.txt");
    
    map<string, set<string>> ownerToTypes;
    map<string, set<pair<string, string>>> typeToOwnersAndNames;
    map<string, set<string>> nameToTypes;
    map<string, pair<int, int>> typeToMinMaxAge;

    
    for (const auto& animal : animals) {
        
        ownerToTypes[animal.owner].insert(animal.type);

        
        if (!animal.name.empty()) {
            typeToOwnersAndNames[animal.type].insert({ animal.owner, animal.name });
        }

        
        if (!animal.name.empty()) {
            nameToTypes[animal.name].insert(animal.type);
        }

        
        if (animal.age != -1) {
            auto& agePair = typeToMinMaxAge[animal.type];
            if (agePair.first == 0 && agePair.second == 0) {
                agePair = { animal.age, animal.age };
            }
            else {
                agePair.first = min(agePair.first, animal.age);
                agePair.second = max(agePair.second, animal.age);
            }
        }
    }

    int choice;
    while (true) {
        cout << "-----------------------------------------------------\n";
        cout << "1. Количество видов животных у каждого владельца\n";
        cout << "2. Владельцы и клички для вида животного\n";
        cout << "3. Количество видов животных с заданной кличкой\n";
        cout << "4. Возрастные минимумы и максимумы по видам\n";
        cout << "Любая другая цифра - выход\n";
        cout << "Выберите операцию: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            for (const auto& owner : ownerToTypes) {
                cout << owner.first << ": " << owner.second.size() << " видов\n";
            }
            break;
        }
        case 2: {
            string animalType;
            cout << "Введите вид животного: ";
            cin.ignore();
            getline(cin, animalType);

            if (typeToOwnersAndNames.find(animalType) == typeToOwnersAndNames.end()) {
                cout << "Животные такого вида не найдены\n";
            }
            else {
                for (const auto& ownerName : typeToOwnersAndNames[animalType]) {
                    cout << "Владелец: " << ownerName.first << ", Кличка: ";
                    cout << (ownerName.second.empty() ? "[без клички]" : ownerName.second) << "\n";
                }
            }
            break;
        }
        case 3: {
            string name;
            cout << "Введите кличку: ";
            cin.ignore();
            getline(cin, name);

            if (nameToTypes.find(name) == nameToTypes.end()) {
                cout << "Животные с такой кличкой не найдены\n";
            }
            else {
                cout << "Количество видов: " << nameToTypes[name].size() << "\n";
            }
            break;
        }
        case 4: {
            for (const auto& typeAges : typeToMinMaxAge) {
                cout << typeAges.first << ": ";
                cout << "min возраст = " << typeAges.second.first;
                cout << ", max возраст = " << typeAges.second.second << "\n";
            }
            break;
        }
        default:
            return 0;
        }
    }
}