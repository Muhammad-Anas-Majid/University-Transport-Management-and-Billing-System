#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;


const int MAX_USERS = 100;
const int MAX_VEHICLES = 50;
const int MAX_ROUTES = 50;
const int MAX_REGS = 100;
const int MAX_BILLS = 100;


class user;
class student;
class admin;
class vehicle;
class bus;
class van;
class route;
class transport_pass;
class bill;


extern user* all_users[];
extern int user_count;

extern vehicle* all_vehicles[];
extern int vehicle_count;

extern route* all_routes[];
extern int route_count;

extern transport_pass* all_passes[];
extern int pass_count;

extern bill* all_bills[];
extern int bill_count;



string make_id(string prefix, int count);

int find_vehicle_by_id(vehicle* arr[], int count, string search_id);
int find_route_by_id(route* arr[], int count, string search_id);
int find_pass_by_id(transport_pass* arr[], int count, string search_id);
int find_pass_by_student(transport_pass* arr[], int count, string sid);
int find_bill_by_student(bill* arr[], int count, string sid);

void save_all_data();
void load_all_data();
void free_all_memory();

void student_menu(student* current_student);
void admin_menu();
void register_user();
void login_user();

#endif#pragma once
