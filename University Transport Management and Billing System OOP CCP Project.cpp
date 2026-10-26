

#include "classes.h"

int main() 

{
  
    for (int i = 0; i < MAX_USERS; i++) all_users[i] = nullptr;

    for (int i = 0; i < MAX_VEHICLES; i++) all_vehicles[i] = nullptr;

    for (int i = 0; i < MAX_ROUTES; i++) all_routes[i] = nullptr;

    for (int i = 0; i < MAX_REGS; i++) all_passes[i] = nullptr;

    for (int i = 0; i < MAX_BILLS; i++) all_bills[i] = nullptr;


    load_all_data();

    cout << "  Data loaded from files.\n";

    int choice;

    do {

        system("cls");

        cout << "\n========== MAIN MENU ==========\n";
        cout << "  University Transport Management System\n";
        cout << "  1. Register User\n";
        cout << "  2. Login\n";
        cout << "  3. Exit\n";
        cout << "  Enter choice: ";

        cin >> choice;


        if (choice == 1)
        {
            system("cls");
            register_user();
        }

        else if (choice == 2)
        {
            system("cls");
            login_user();
        }

        else if (choice == 3) 
        {
           
            save_all_data();
            cout << "  Goodbye!\n";
        }
        else
        {
            cout << "  Invalid choice!\n";
        }
    } while (choice != 3);

   

    free_all_memory();
    return 0;
}