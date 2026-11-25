#include <iostream>
#include <iomanip>
#include <string>
#include "Truck.h"
#include "Sedan.h"
#include "Bus.h"
#include "CircularList.h"

using namespace std;

void showMenu() {
    cout << "\n====== POLYMORPHIC CIRCULAR LIST MENU ======\n";
    cout << "1. Add Truck\n";
    cout << "2. Add Sedan\n";
    cout << "3. Add Bus\n";
    cout << "4. Display All Transport (Tables by Type)\n";
    cout << "5. Search Transport by Brand (via searchByBrand)\n";
    cout << "6. Delete Transport by Index\n";
    cout << "7. Clear Entire List\n";
    cout << "0. Exit\n";
    cout << "===========================================\n";
    cout << "Choose action: ";
}

int main() {
    CircularList<Transport*> fleet;

    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: { // Добавить грузовик
            Truck* t = new Truck();
            cin >> *t;
            fleet.add(t);
            cout << "Truck added to fleet!\n";
            break;
        }
        case 2: { // Добавить седан
            Sedan* s = new Sedan();
            cin >> *s;
            fleet.add(s);
            cout << "Sedan added to fleet!\n";
            break;
        }
        case 3: { // Добавить автобус
            Bus* b = new Bus();
            cin >> *b;
            fleet.add(b);
            cout << "Bus added to fleet!\n";
            break;
        }
        case 4: { 
            if (fleet.isEmpty()) {
                cout << "Fleet is empty!\n";
            }
            else {
                bool truckPrinted = false;
                for (int i = 0; i < fleet.getSize(); i++) {
                    Transport* current = fleet.search(i);
                    if (Truck* truck = dynamic_cast<Truck*>(current)) {
                        if (!truckPrinted) {
                            cout << "\n>>> TRUCKS TABLE <<<\n";
                            truck->printTableHeader();
                            truckPrinted = true;
                        }
                        cout << left << setw(5) << i << *truck << "\n";
                    }
                }
                if (truckPrinted) {
                    cout << "======================================================================================================\n";
                }
              
                bool sedanPrinted = false;
                for (int i = 0; i < fleet.getSize(); i++) {
                    Transport* current = fleet.search(i);
                    if (Sedan* sedan = dynamic_cast<Sedan*>(current)) {
                        if (!sedanPrinted) {
                            cout << "\n>>> SEDANS TABLE <<<\n";
                            sedan->printTableHeader();
                            sedanPrinted = true;
                        }
                        cout << left << setw(5) << i << *sedan << "\n";
                    }
                }
                if (sedanPrinted) {
                    cout << "======================================================================================================\n";
                }

                bool busPrinted = false;
                for (int i = 0; i < fleet.getSize(); i++) {
                    Transport* current = fleet.search(i);
                    if (Bus* bus = dynamic_cast<Bus*>(current)) {
                        if (!busPrinted) {
                            cout << "\n>>> BUSES TABLE <<<\n";
                            bus->printTableHeader();
                            busPrinted = true;
                        }
                        cout << left << setw(5) << i << *bus << "\n";
                    }
                }
                if (busPrinted) {
                    cout << "======================================================================================================\n";
                }
            }
            break;
        }
        case 5: { // Поиск по бренду 
            if (fleet.isEmpty()) {
                cout << "Fleet is empty!\n";
            }
            else {
                string targetBrand;
                cout << "Enter brand to search: ";
                cin >> targetBrand;

                Transport* found = fleet.searchByBrand(targetBrand);

                if (found != nullptr) {
                    cout << "\nVehicle found:\n";
                    found->printTableHeader();
                    cout << left << setw(5) << "1";

                    if (Truck* t = dynamic_cast<Truck*>(found)) cout << *t << "\n";
                    else if (Sedan* s = dynamic_cast<Sedan*>(found)) cout << *s << "\n";
                    else if (Bus* b = dynamic_cast<Bus*>(found)) cout << *b << "\n";

                    cout << "======================================================================================================\n";
                }
                else {
                    cout << "Vehicle with brand '" << targetBrand << "' not found.\n";
                }
            }
            break;
        }
        case 6: { // Удаление по индексу
            if (fleet.isEmpty()) {
                cout << "Fleet is empty!\n";
            }
            else {
                int index;
                cout << "Enter index to delete (0 to " << fleet.getSize() - 1 << "): ";
                cin >> index;

                Transport* toDelete = fleet.search(index);
                if (toDelete != nullptr) {
                    cout << "\nDeleting sequence:\n";
                    delete toDelete; // Вызовет цепочку деструкторов (полиморфно!)
                    fleet.remove(index); // Удалит узел из списка
                    cout << "Transport deleted successfully.\n";
                }
                else {
                    cout << "Invalid index!\n";
                }
            }
            break;
        }
        case 7: { // Полная очистка
            if (fleet.isEmpty()) {
                cout << "Fleet is already empty.\n";
            }
            else {
                cout << "\nDeleting sequence for all transport:\n";
                for (int i = 0; i < fleet.getSize(); i++) {
                    delete fleet.search(i); // Удаляем динамические объекты
                }
                fleet.clear(); // Очищаем узлы списка
                cout << "Fleet completely cleared.\n";
            }
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    // Финальная очистка памяти перед закрытием программы
    if (!fleet.isEmpty()) {
        for (int i = 0; i < fleet.getSize(); i++) {
            delete fleet.search(i);
        }
        fleet.clear();
    }

    return 0;
}