
#include "classes.h"

//MODULE 1 :  (anas)


class user {

public:
    string user_id;
    string user_name;
    string password;
    string role;        

    user() 
    {
        user_id = "";
        user_name = "";
        password = "";
        role = "";
    }

    user(string id, string name, string pass, string r) 
    {
        user_id = id;
        user_name = name;
        password = pass;
        role = r;
    }

    // Copy constructor

    user(const user& other) 
    {
        user_id = other.user_id;
        user_name = other.user_name;
        password = other.password;
        role = other.role;
    }

    // Assignment operator

    user& operator=(const user& other) 
    {
        user_id = other.user_id;
        user_name = other.user_name;
        password = other.password;
        role = other.role;
        return *this;
    }



    virtual void show_info() = 0;

    virtual ~user() {}
};



class student : public user 
{
public:
    string registered_route_id;   
    student() : user() 
    {
        registered_route_id = "";
    }

    student(string id, string name, string pass) : user(id, name, pass, "student") 
    {
        registered_route_id = "";
    }

    void show_info() override 
    {
        cout << "  [Student] ID: " << user_id << " | Name: " << user_name
            << " | Route: " << (registered_route_id == "" ? "None" : registered_route_id) << endl;
    }
};



class admin : public user 
{

public:

    admin() : user() 
    {}

    admin(string id, string name, string pass) : user(id, name, pass, "admin") 
    {}

    void show_info() override 
    {
        cout << "  [Admin]   ID: " << user_id << " | Name: " << user_name << endl;
    }
};



class vehicle 
{

public:

    string vehicle_id;
    string vehicle_type;  
    int    capacity;
    int    seats_taken;
    string assigned_route_id;

    vehicle() 
    {
        vehicle_id = "";
        vehicle_type = "";
        capacity = 0;
        seats_taken = 0;
        assigned_route_id = "";
    }

    vehicle(string vid, string vtype, int cap) 
    {
        vehicle_id = vid;
        vehicle_type = vtype;
        capacity = cap;
        seats_taken = 0;
        assigned_route_id = "";
    }

    // Copy constructor

    vehicle(const vehicle& other) 
    {
        vehicle_id = other.vehicle_id;
        vehicle_type = other.vehicle_type;
        capacity = other.capacity;
        seats_taken = other.seats_taken;
        assigned_route_id = other.assigned_route_id;
    }

    // Assignment operator

    vehicle& operator=(const vehicle& other) 
    {
        vehicle_id = other.vehicle_id;
        vehicle_type = other.vehicle_type;
        capacity = other.capacity;
        seats_taken = other.seats_taken;
        assigned_route_id = other.assigned_route_id;
        return *this;
    }

    bool has_seat() 
    {
        return seats_taken < capacity;
    }


    virtual void show_vehicle() = 0;

    virtual ~vehicle() 
    {}
};



class bus : public vehicle 
{
public:
    bus() : vehicle() 
    {}

    bus(string vid, int cap) : vehicle(vid, "Bus", cap) 
    {}

    void show_vehicle() override 
    {
        cout << "  [Bus] ID: " << vehicle_id
            << " | Cap: " << capacity
            << " | Taken: " << seats_taken
            << " | Route: " << (assigned_route_id == "" ? "None" : assigned_route_id) << endl;
    }
};



class van : public vehicle 
{

public:

    van() : vehicle() 
    {}

    van(string vid, int cap) : vehicle(vid, "Van", cap) 
    {}

    void show_vehicle() override 
    {
        cout << "  [Van] ID: " << vehicle_id
            << " | Cap: " << capacity
            << " | Taken: " << seats_taken
            << " | Route: " << (assigned_route_id == "" ? "None" : assigned_route_id) << endl;
    }
};


class route 
{
public:

    string route_id;
    string start_point;
    string end_point;
    double distance_km;
    double monthly_fee;

    route()
    {
        route_id = "";
        start_point = "";
        end_point = "";
        distance_km = 0;
        monthly_fee = 0;
    }

    route(string rid, string start, string end, double dist, double fee)
    {
        route_id = rid;
        start_point = start;
        end_point = end;
        distance_km = dist;
        monthly_fee = fee;
    }

    void show_route() 
    {
        cout << "  Route ID: " << route_id
            << " | " << start_point << " -> " << end_point
            << " | Dist: " << distance_km << " km"
            << " | Fee: Rs." << monthly_fee << "/month" << endl;
    }
};


bool operator>(route& r1, route& r2) 
{
    return r1.monthly_fee > r2.monthly_fee;
}




class transport_pass 
{

public:
    string pass_id;
    string student_id;
    string route_id;
    string vehicle_id;
    string status;     

    transport_pass()
    {
        pass_id = "";
        student_id = "";
        route_id = "";
        vehicle_id = "";
        status = "pending";
    }

    transport_pass(string pid, string sid, string rid, string vid) 
    {
        pass_id = pid;
        student_id = sid;
        route_id = rid;
        vehicle_id = vid;
        status = "pending";
    }

    void show_pass() 
    {
        cout << "  Pass ID: " << pass_id
            << " | Student: " << student_id
            << " | Route: " << route_id
            << " | Vehicle: " << vehicle_id
            << " | Status: " << status << endl;
    }
};



class bill 
{

public:
    string bill_id;
    string student_id;
    string route_id;
    double base_fee;
    double late_fine;
    double total_amount;
    string is_paid;  

    bill() 
    {
        bill_id = "";
        student_id = "";
        route_id = "";
        base_fee = 0;
        late_fine = 0;
        total_amount = 0;
        is_paid = "no";
    }

    bill(string bid, string sid, string rid, double fee, double fine) 
    {
        bill_id = bid;
        student_id = sid;
        route_id = rid;
        base_fee = fee;
        late_fine = fine;
        total_amount = fee + fine;
        is_paid = "no";
    }

    void show_bill() 
    {
        cout << "  Bill ID: " << bill_id
            << " | Student: " << student_id
            << " | Route: " << route_id
            << " | Base: Rs." << base_fee
            << " | Fine: Rs." << late_fine
            << " | Total: Rs." << total_amount
            << " | Paid: " << is_paid << endl;
    }
};



template <typename T>

int find_by_id(T* arr[], int count, string search_id)
{
    for (int i = 0; i < count; i++) 
    {

        if (arr[i] != nullptr && arr[i]->user_id == search_id)
            return i;

    }
    return -1;
}

// global arrays

user* all_users[MAX_USERS];

int user_count = 0;

vehicle* all_vehicles[MAX_VEHICLES];

int vehicle_count = 0;

route* all_routes[MAX_ROUTES];

int route_count = 0;

transport_pass* all_passes[MAX_REGS];

int pass_count = 0;

bill* all_bills[MAX_BILLS];
int  bill_count = 0;


//         helper functions


string make_id(string prefix, int count) 
{
    return prefix + to_string(count + 1);
}

int find_vehicle_by_id(vehicle* arr[], int count, string search_id) 
{
    for (int i = 0; i < count; i++)
    {

        if (arr[i] != nullptr && arr[i]->vehicle_id == search_id)
            return i;

    }

    return -1;
}

int find_route_by_id(route* arr[], int count, string search_id) 
{
    for (int i = 0; i < count; i++) 
    {

        if (arr[i] != nullptr && arr[i]->route_id == search_id)
            return i;

    }

    return -1;
}

int find_pass_by_id(transport_pass* arr[], int count, string search_id) 
{
    for (int i = 0; i < count; i++) 
    {

        if (arr[i] != nullptr && arr[i]->pass_id == search_id)
            return i;

    }

    return -1;
}

int find_pass_by_student(transport_pass* arr[], int count, string sid) 
{
    for (int i = 0; i < count; i++) 
    {

        if (arr[i] != nullptr && arr[i]->student_id == sid)
            return i;

    }

    return -1;
}

int find_bill_by_student(bill* arr[], int count, string sid) 
{
    for (int i = 0; i < count; i++) 
    {

        if (arr[i] != nullptr && arr[i]->student_id == sid)
            return i;

    }
    return -1;
}



//        module 2 : mohid

void save_users() 
{
    ofstream file("users.txt");

    for (int i = 0; i < user_count; i++) 
    {
        if (all_users[i] != nullptr) 
        {
            file << all_users[i]->user_id << "\n";
            file << all_users[i]->user_name << "\n";
            file << all_users[i]->password << "\n";
            file << all_users[i]->role << "\n";

            if (all_users[i]->role == "student") 
            {

                student* s = (student*)all_users[i];
                file << (s->registered_route_id == "" ? "none" : s->registered_route_id) << "\n";

            }
            else 
            {
                file << "none\n";
            }
        }
    }

    file.close();


    cout << "  Users saved.\n";
}

void load_users() 
{
    ifstream file("users.txt");
    if (!file.is_open()) return;
    user_count = 0;

    while (!file.eof() && user_count < MAX_USERS) 
    {
        string uid, uname, upass, urole, extra;

        if (!getline(file, uid))   break;

        if (!getline(file, uname)) break;

        if (!getline(file, upass)) break;

        if (!getline(file, urole)) break;

        if (!getline(file, extra)) break;

        if (uid == "") break;

        if (urole == "student") 
        {
            student* s = new student(uid, uname, upass);
            s->registered_route_id = (extra == "none" ? "" : extra);
            all_users[user_count] = s;
        }
        else
        {
            all_users[user_count] = new admin(uid, uname, upass);
        }

        user_count++;
    }

    file.close();
}

void save_vehicles() 
{
    ofstream file("vehicles.txt");

    for (int i = 0; i < vehicle_count; i++) 
    {
        if (all_vehicles[i] != nullptr) 
        {
            file << all_vehicles[i]->vehicle_id << "\n";
            file << all_vehicles[i]->vehicle_type << "\n";
            file << all_vehicles[i]->capacity << "\n";
            file << all_vehicles[i]->seats_taken << "\n";
            file << (all_vehicles[i]->assigned_route_id == "" ? "none" : all_vehicles[i]->assigned_route_id) << "\n";
        }
    }
    file.close();

    cout << "  Vehicles saved.\n";
}

void load_vehicles() 
{
    ifstream file("vehicles.txt");

    if (!file.is_open()) return;

    vehicle_count = 0;

    while (!file.eof() && vehicle_count < MAX_VEHICLES) 
    {
        string vid, vtype, vcap_str, vtaken_str, vroute;

        if (!getline(file, vid))        break;

        if (!getline(file, vtype))      break;

        if (!getline(file, vcap_str))   break;

        if (!getline(file, vtaken_str)) break;

        if (!getline(file, vroute))     break;

        if (vid == "") break;

        int cap = stoi(vcap_str);

        int taken = stoi(vtaken_str);

        vehicle* v;

        if (vtype == "Bus")
        {
            v = new bus(vid, cap);
        }

        else
        {
            v = new van(vid, cap);
        }

        v->seats_taken = taken;
        v->assigned_route_id = (vroute == "none" ? "" : vroute);
        all_vehicles[vehicle_count] = v;
        vehicle_count++;
    }

    file.close();
}

void save_routes()
{
    ofstream file("routes.txt");

    for (int i = 0; i < route_count; i++) 
    {
        if (all_routes[i] != nullptr) 
        {
            file << all_routes[i]->route_id << "\n";
            file << all_routes[i]->start_point << "\n";
            file << all_routes[i]->end_point << "\n";
            file << all_routes[i]->distance_km << "\n";
            file << all_routes[i]->monthly_fee << "\n";
        }
    }

    file.close();
    cout << "  Routes saved.\n";
}

void load_routes() 
{
    ifstream file("routes.txt");

    if (!file.is_open()) return;
    route_count = 0;

    while (!file.eof() && route_count < MAX_ROUTES) 
    {
        string rid, rstart, rend, rdist_str, rfee_str;

        if (!getline(file, rid))       break;

        if (!getline(file, rstart))    break;

        if (!getline(file, rend))      break;

        if (!getline(file, rdist_str)) break;

        if (!getline(file, rfee_str))  break;

        if (rid == "") break;

        double dist = stod(rdist_str);

        double fee = stod(rfee_str);

        all_routes[route_count] = new route(rid, rstart, rend, dist, fee);

        route_count++;
    }
    file.close();
}

void save_registrations() 
{
    ofstream file("registrations.txt");

    for (int i = 0; i < pass_count; i++)
    {
        if (all_passes[i] != nullptr) 
        {
            file << all_passes[i]->pass_id << "\n";
            file << all_passes[i]->student_id << "\n";
            file << all_passes[i]->route_id << "\n";
            file << all_passes[i]->vehicle_id << "\n";
            file << all_passes[i]->status << "\n";
        }
    }

    file.close();
    cout << "  Registrations saved.\n";
}

void load_registrations() 
{
    ifstream file("registrations.txt");

    if (!file.is_open()) return;

    pass_count = 0;

    while (!file.eof() && pass_count < MAX_REGS)
    {
        string pid, sid, rid, vid, stat;

        if (!getline(file, pid))  break;

        if (!getline(file, sid))  break;

        if (!getline(file, rid))  break;

        if (!getline(file, vid))  break;

        if (!getline(file, stat)) break;

        if (pid == "") break;

        transport_pass* p = new transport_pass(pid, sid, rid, vid);

        p->status = stat;

        all_passes[pass_count] = p;

        pass_count++;
    }

    file.close();
}

void save_bills()
{
    ofstream file("bills.txt");


    for (int i = 0; i < bill_count; i++) 
    {
        if (all_bills[i] != nullptr) 
        {
            file << all_bills[i]->bill_id << "\n";
            file << all_bills[i]->student_id << "\n";
            file << all_bills[i]->route_id << "\n";
            file << all_bills[i]->base_fee << "\n";
            file << all_bills[i]->late_fine << "\n";
            file << all_bills[i]->total_amount << "\n";
            file << all_bills[i]->is_paid << "\n";
        }
    }
    file.close();

    cout << "  Bills saved.\n";
}

void load_bills() 
{
    ifstream file("bills.txt");

    if (!file.is_open()) return;

    bill_count = 0;

    while (!file.eof() && bill_count < MAX_BILLS) 
    {
        string bid, sid, rid, bfee_str, fine_str, total_str, paid;

        if (!getline(file, bid))       break;

        if (!getline(file, sid))       break;

        if (!getline(file, rid))       break;

        if (!getline(file, bfee_str))  break;

        if (!getline(file, fine_str))  break;

        if (!getline(file, total_str)) break;

        if (!getline(file, paid))      break;

        if (bid == "") break;

        double bfee = stod(bfee_str);
        double fine = stod(fine_str);

        bill* b = new bill(bid, sid, rid, bfee, fine);

        b->total_amount = stod(total_str);
        b->is_paid = paid;
        all_bills[bill_count] = b;
        bill_count++;
    }

    file.close();
}

void save_all_data() 
{
    save_users();
    save_vehicles();
    save_routes();
    save_registrations();
    save_bills();
    cout << "  All data saved successfully!\n";
}

void load_all_data() 
{
    load_users();
    load_vehicles();
    load_routes();
    load_registrations();
    load_bills();
}

void free_all_memory() 
{

    for (int i = 0; i < user_count; i++) { delete all_users[i];    all_users[i] = nullptr; }

    for (int i = 0; i < vehicle_count; i++) { delete all_vehicles[i]; all_vehicles[i] = nullptr; }

    for (int i = 0; i < route_count; i++) { delete all_routes[i];   all_routes[i] = nullptr; }

    for (int i = 0; i < pass_count; i++) { delete all_passes[i];   all_passes[i] = nullptr; }

    for (int i = 0; i < bill_count; i++) { delete all_bills[i];    all_bills[i] = nullptr; }

}



//   student menu functions


void student_view_routes() 
{
    cout << "\n--- Available Routes ---\n";

    if (route_count == 0) 
    { cout << "  No routes available.\n"; return; }

    for (int i = 0; i < route_count; i++) 
    {

        if (all_routes[i] != nullptr)
            all_routes[i]->show_route();

    }
}

void student_apply_transport(student* current_student) 
{
    if (current_student->registered_route_id != "") 
    {
        cout << "  You already have an active registration.\n";
        return;
    }
    cout << "\n--- Apply for Transport ---\n";
    student_view_routes();

    cin.ignore();
    cout << "  Enter Route ID to apply: ";
    string rid;
    getline(cin, rid);

    int ri = find_route_by_id(all_routes, route_count, rid);

    if (ri == -1) { cout << "  Route not found!\n"; return; }



    int vi = -1;

    for (int i = 0; i < vehicle_count; i++)
    {
        if (all_vehicles[i] != nullptr &&
            all_vehicles[i]->assigned_route_id == rid &&
            all_vehicles[i]->has_seat()) 
        {
            vi = i;
            break;
        }
    }
    if (vi == -1) { cout << "  No vehicle available on this route.\n"; return; }

    string pid = make_id("PASS", pass_count);

    transport_pass* p = new transport_pass(pid, current_student->user_id, rid, all_vehicles[vi]->vehicle_id);

    all_passes[pass_count] = p;
    pass_count++;

    cout << "  Application submitted! Pass ID: " << pid << " | Status: pending\n";
}

void student_view_registration(student* current_student) 
{
    cout << "\n--- My Registration ---\n";

    int pi = find_pass_by_student(all_passes, pass_count, current_student->user_id);

    if (pi == -1) { cout << "  No registration found.\n"; return; }

    all_passes[pi]->show_pass();

    int bi = find_bill_by_student(all_bills, bill_count, current_student->user_id);

    if (bi != -1) { cout << "  --- Your Bill ---\n"; all_bills[bi]->show_bill(); }

}

void student_cancel_registration(student* current_student)
{
    cout << "\n--- Cancel Registration ---\n";

    int pi = find_pass_by_student(all_passes, pass_count, current_student->user_id);

    if (pi == -1) { cout << "  No registration to cancel.\n"; return; }

    if (all_passes[pi]->status == "cancelled") { cout << "  Already cancelled.\n"; return; }

    if (all_passes[pi]->status == "approved") 
    {
        int vi = find_vehicle_by_id(all_vehicles, vehicle_count, all_passes[pi]->vehicle_id);

        if (vi != -1 && all_vehicles[vi]->seats_taken > 0)
            all_vehicles[vi]->seats_taken--;
        current_student->registered_route_id = "";

    }

    all_passes[pi]->status = "cancelled";
    cout << "  Registration cancelled.\n";
}

void student_menu(student* current_student) 
{
    system("cls");
    int choice;
    do {

        
        cout << "\n========== STUDENT MENU ==========\n";
        cout << "  1. View Routes\n";
        cout << "  2. Apply for Transport\n";
        cout << "  3. View My Registration\n";
        cout << "  4. Cancel Registration\n";
        cout << "  5. Logout\n";
        cout << "  Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            student_view_routes();
        }

        else if (choice == 2)
        {
            system("cls");
            student_apply_transport(current_student);
        }

        else if (choice == 3)
        {
            system("cls");
            student_view_registration(current_student);
        }

        else if (choice == 4)
        {
            system("cls");
            student_cancel_registration(current_student);
        }

        else if (choice == 5)
        {
            cout << "  Logged out.\n";
        }

        else
        {
            cout << "  Invalid choice!\n";
        }

    } while (choice != 5);
}


//     admin menu functions

void admin_add_vehicle() 
{
    cout << "\n--- Add Vehicle ---\n";
    string vtype;
    int cap;

    cout << "  Enter type (Bus/Van): ";
    cin >> vtype;

    cout << "  Enter capacity: ";
    cin >> cap;

    string vid = make_id("V", vehicle_count);
    vehicle* v;

    if (vtype == "Bus" || vtype == "bus")
    {
        v = new bus(vid, cap);
    }

    else
    {
        v = new van(vid, cap);
    }

    all_vehicles[vehicle_count] = v;
    vehicle_count++;

    cout << "  Vehicle added! ID: " << vid << "\n";
}

void admin_edit_vehicle() 
{

    cout << "\n--- Edit Vehicle ---\n";
    cout << "  Enter Vehicle ID to edit: ";
    string vid;
    cin >> vid;

    int vi = find_vehicle_by_id(all_vehicles, vehicle_count, vid);

    if (vi == -1) { cout << "  Vehicle not found!\n"; return; }

    cout << "  Enter new capacity: ";
    cin >> all_vehicles[vi]->capacity;

    cout << "  Vehicle updated.\n";
}

void admin_remove_vehicle() 
{
    cout << "\n--- Remove Vehicle ---\n";

    cout << "  Enter Vehicle ID to remove: ";

    string vid;
    cin >> vid;
    int vi = find_vehicle_by_id(all_vehicles, vehicle_count, vid);

    if (vi == -1) { cout << "  Vehicle not found!\n"; return; }

    delete all_vehicles[vi];

    for (int i = vi; i < vehicle_count - 1; i++)
        all_vehicles[i] = all_vehicles[i + 1];
    vehicle_count--;

    cout << "  Vehicle removed.\n";
}

void admin_view_vehicles() 
{
    cout << "\n--- All Vehicles ---\n";

    if (vehicle_count == 0) { cout << "  No vehicles.\n"; return; }

    for (int i = 0; i < vehicle_count; i++) 
    {

        if (all_vehicles[i] != nullptr)
        {
            all_vehicles[i]->show_vehicle();
        }

    }
}

void admin_add_route() 
{
    cout << "\n--- Add Route ---\n";
    string start, end;
    double dist, fee;

    cin.ignore();

    cout << "  Enter start point: ";   
    getline(cin, start);
    cout << "  Enter end point: ";     
    getline(cin, end);
    cout << "  Enter distance (km): "; 
    cin >> dist;
    cout << "  Enter monthly fee: ";   
    cin >> fee;


    string rid = make_id("R", route_count);

    all_routes[route_count] = new route(rid, start, end, dist, fee);

    route_count++;

    cout << "  Route added! ID: " << rid << "\n";
}

void admin_assign_vehicle_to_route() 
{
    cout << "\n--- Assign Vehicle to Route ---\n";
    string vid, rid;

    cin.ignore();

    cout << "  Enter Vehicle ID: "; 
    getline(cin, vid);
    cout << "  Enter Route ID: ";   
    getline(cin, rid);


    int vi = find_vehicle_by_id(all_vehicles, vehicle_count, vid);

    int ri = find_route_by_id(all_routes, route_count, rid);

    if (vi == -1) { cout << "  Vehicle not found!\n"; return; }

    if (ri == -1) { cout << "  Route not found!\n";   return; }

    all_vehicles[vi]->assigned_route_id = rid;

    cout << "  Vehicle " << vid << " assigned to route " << rid << "\n";
}

void admin_view_applications() 
{
    cout << "\n--- All Applications ---\n";
    if (pass_count == 0) { cout << "  No applications.\n"; return; }

    for (int i = 0; i < pass_count; i++) 
    {
        if (all_passes[i] != nullptr)
        {
            all_passes[i]->show_pass();
        }
    }
}

void admin_approve_reject() 
{
    cout << "\n--- Approve / Reject Application ---\n";
    cout << "  Enter Pass ID: ";

    string pid;
    cin >> pid;

    int pi = find_pass_by_id(all_passes, pass_count, pid);

    if (pi == -1) { cout << "  Pass not found!\n"; return; }

    if (all_passes[pi]->status != "pending") 
    {
        cout << "  Already " << all_passes[pi]->status << "\n";
        return;
    }

    cout << "  Enter decision (approve/reject): ";
    string decision;
    cin >> decision;
    if (decision == "approve") 
    {
        int vi = find_vehicle_by_id(all_vehicles, vehicle_count, all_passes[pi]->vehicle_id);

        if (vi != -1 && all_vehicles[vi]->has_seat()) 
        {
            all_vehicles[vi]->seats_taken++;
            all_passes[pi]->status = "approved";
            for (int i = 0; i < user_count; i++) 
            {
                if (all_users[i] != nullptr &&
                    all_users[i]->role == "student" &&
                    all_users[i]->user_id == all_passes[pi]->student_id) 
                {
                    student* s = (student*)all_users[i];
                    s->registered_route_id = all_passes[pi]->route_id;
                    break;
                }
            }

            int ri = find_route_by_id(all_routes, route_count, all_passes[pi]->route_id);

            double fee = (ri != -1) ? all_routes[ri]->monthly_fee : 0;
            string bid = make_id("BILL", bill_count);

            all_bills[bill_count] = new bill(bid, all_passes[pi]->student_id, all_passes[pi]->route_id, fee, 0);
            bill_count++;

            cout << "  Approved! Bill generated: " << bid << "\n";
        }

        else 
        {
            cout << "  No seats available!\n";
        }
    }
    else if (decision == "reject") 
    {

        all_passes[pi]->status = "rejected";
        cout << "  Application rejected.\n";

    }

    else 
    {

        cout << "  Invalid decision.\n";

    }
}

void admin_generate_reports() 
{
    cout << "\n--- Reports ---\n";
    double total_revenue = 0;

    cout << "  === All Bills ===\n";

    for (int i = 0; i < bill_count; i++) 
    {
        if (all_bills[i] != nullptr) 
        {
            all_bills[i]->show_bill();
            total_revenue += all_bills[i]->total_amount;
        }
    }

    cout << "  Total Revenue: Rs." << total_revenue << "\n";
    cout << "\n  === Route-wise Usage ===\n";

    for (int r = 0; r < route_count; r++) 
    {
        if (all_routes[r] == nullptr) continue;
        int usage = 0;

        for (int p = 0; p < pass_count; p++) 
        {
            if (all_passes[p] != nullptr && all_passes[p]->route_id == all_routes[r]->route_id && all_passes[p]->status == "approved")

                usage++;

        }

        cout << "  Route " << all_routes[r]->route_id
            << " (" << all_routes[r]->start_point << " -> " << all_routes[r]->end_point << ")"
            << " | Approved: " << usage << "\n";
    }
}

void admin_menu() 
{
    system("cls");

    int choice;
    do {

        
        cout << "\n========== ADMIN MENU ==========\n";
        cout << "  1.  Add Vehicle\n";
        cout << "  2.  Edit Vehicle\n";
        cout << "  3.  Remove Vehicle\n";
        cout << "  4.  View Vehicles\n";
        cout << "  5.  Add Route\n";
        cout << "  6.  Assign Vehicle to Route\n";
        cout << "  7.  View Applications\n";
        cout << "  8.  Approve / Reject Applications\n";
        cout << "  9.  Generate Reports\n";
        cout << "  10. Save Data\n";
        cout << "  11. Logout\n";
        cout << "  Enter choice: ";

        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            admin_add_vehicle();
        }

        else if (choice == 2)
        {
            system("cls");
            admin_edit_vehicle();
        }

        else if (choice == 3)
        {
            system("cls");
            admin_remove_vehicle();
        }

        else if (choice == 4)
        {
            system("cls");
            admin_view_vehicles();
        }

        else if (choice == 5)
        {
            system("cls");
            admin_add_route();
        }

        else if (choice == 6)
        {
            system("cls");
            admin_assign_vehicle_to_route();
        }

        else if (choice == 7)
        {
            system("cls");
            admin_view_applications();
        }

        else if (choice == 8)
        {
            system("cls");
            admin_approve_reject();
        }

        else if (choice == 9)
        {
            system("cls");
            admin_generate_reports();
        }

        else if (choice == 10)
        {
            system("cls");
            save_all_data();
        }

        else if (choice == 11)
        {

            cout << "  Logged out.\n";
        }

        else
        {
            cout << "  Invalid choice!\n";
        }


    } while (choice != 11);
}



//      main menu functions


void register_user() 
{
    cout << "\n--- Register New User ---\n";

    string role, uname, upass;

    cout << "  Enter role (student/admin): "; 
    cin >> role;
    cin.ignore();

    cout << "  Enter username: ";             
    getline(cin, uname);
    cout << "  Enter password: ";           
    cin >> upass;

    string uid = make_id("U", user_count);

    if (role == "student") 
    {
        all_users[user_count] = new student(uid, uname, upass);
    }

    else if (role == "admin") 
    {
        all_users[user_count] = new admin(uid, uname, upass);
    }

    else 
    {
        cout << "  Invalid role!\n";
        return;
    }

    user_count++;

    cout << "  Registered! Your ID: " << uid << "\n";

    cout << "\n  Press Enter to continue...";
    cin.ignore(1000, '\n');
    cin.get();
}

void login_user() 
{
    cout << "\n--- Login ---\n";

    string uid, upass;

    cout << "  Enter User ID: ";  cin >> uid;
    cout << "  Enter Password: "; cin >> upass;

    int idx = find_by_id(all_users, user_count, uid);

    if (idx == -1) { cout << "  User not found!\n";  return; }

    if (all_users[idx]->password != upass) { cout << "  Wrong password!\n"; return; }

    cout << "  Welcome, " << all_users[idx]->user_name << "!\n";

    system("cls");

    if (all_users[idx]->role == "student") 
    {

        student* s = (student*)all_users[idx];
        student_menu(s);

    }

    else if (all_users[idx]->role == "admin")
    {

        admin_menu();

    }
}