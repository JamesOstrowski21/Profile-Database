#include <iostream>
#include <vector>
#include "Profile.h"
#include "ProfileDatabase.h"
//Name: James Ostrowski
//Date:9/28/21
//Description:For milestone 1 and 2 main program serves as a test for two class files ProfileDatabase and Profile
//Inputs: ProfileDatabase and Profile
//Outputs: Objects of the classes tested.
using namespace std;

int main() {
    Profile person1("Jane","Seeing someone");//test profile constructor.
    person1.print();//Prints test.
    person1.setName("John");
    person1.setStatus("sleeping");

    person1.addFriend("Joe"); //Test adding friends.
    person1.addFriend("Sally");
    cout << endl;
    person1.print();

    person1.deleteFriend("Joe");//Tests deleting friends.
    cout << endl;
    person1.print();

    cout << endl;
    cout << "Database test:" << endl;
    cout << endl;

    ProfileDatabase database; //Default database constructor.
    Profile A("Sam","programming");//Test profile initialization.
    Profile B("Sally","reading");
    Profile C("Sally","sleeping");
    database.addProfile(A);//Adds profiles to the database.
    database.addProfile(B);
    database.addProfile(C);
    database.addFriends("Sam","Sally"); //Tests adding friends.
    database.addFriends("Sam","Sally");
    database.addFriends("Sam","Jane");
    database.deleteFriends("Sam","Jane");//Tests deleting friends.
    database.deleteFriends("Sam","Sally");
    database.updateStatus("Sally", "Sleeping");//Test updating status
    database.updateStatus("John","gaming");
    database.getProfileIndex("Sally"); //Tests getting index.
    cout<< endl;
    database.print();//Test print method.
    cout << endl;
    cout << "Main Program: " << endl;

    int end = 1; //while loop parameter for menu
    int end2 = 1; //while loop parameter for submenu
    string menu, name, status, submenu, name2, status2,name3; //input variable for user inputs
    ProfileDatabase data; //Initialize profile database
    while (end != 0){ //While loop for menu
        cout << "Please enter one of the following options: Print = '1', Add a Profile = '2', Delete a Profile = '3', lookup/modify a profile = '4', or Exit = '5'." << endl; //Menu output to user
        cin >> menu; //User input for menu

        if(menu == "1"){ //If print is selected
            if(data.amountProfiles() > 0){ //check to see if there are any profiles in database.
                data.print(); //Prints profiles of database.
            } else {
                cout << "The FriendsNetwork is empty" << endl; //if no profiles.
            }
        }
        if(menu == "2"){ //If add a profile is selected
            cout << "Please enter a name (no spaces):" << endl; //Prompt to enter a name.
            cin >> name; //store name
            cout << "Please enter a status" << endl; //prompt to enter status
            cin >> status; //store status.
            Profile n (name,status); //create profile.
            if(data.getProfileIndex(name) < 0) { //check to see if a profile with that name exists.
                data.addProfile(n); // add profile to database.
                cout << "New Profile created" << endl; //output to user.
                n.print(); //output profile info.
            } else {
                cout << "A profile with the name:" << name << " already exist." << endl; //if profile with name exist.
            }

        }
        if(menu == "3"){ //if delete profile is selected.
            cout << "Please enter a name (no spaces): "<< endl; //prompt for a name
            cin >> name; //store given name from user.
            if(data.getProfileIndex(name) >=0) { //check to see if profile exists.
                data.deleteProfile(name); //delete profile.
                cout << "Profile with the name: " << name << " was deleted." << endl; //output to user.
            } else {
                cout << "A profile with the name: " << name << " does not exist." << endl; //if profile doesn't exist.
            }

        }
        if(menu == "4"){ //if submenu is selected
                cout << "Please enter a name (no spaces): " << endl; //prompt to enter name.
                cin >> name2; //store name.
                if(data.getProfileIndex(name2) >= 0){ //check if profile exists in order to be modified.
                    data.getProfile(name2).print(); //print profile.
                    while(end2 != 0){ // while loop for submenu
                        cout << "Please enter one of the following: add friend = '1', delete friend = '2', change status '3', or exit = '4'." << endl; //submenu output to user.
                        cin >> submenu; //store users submenu input.
                        if(submenu == "1"){ // if add friend is selected
                            cout << "Please enter a name (no spaces): " << endl; //prompt to enter name of friend to be added
                            cin >> name3; //store friend name
                            if(data.getProfileIndex(name3)>= 0){ //Check if friend exists.
                                data.addFriends(name2,name3); //add friend.
                            } else {
                                cout << name3 << " does not exist." << endl; // if friend doesn't exist.
                            }
                        }
                        if(submenu == "2"){ //if delete friend is selected.
                            cout << "Please enter a name (no spaces): " << endl; //prompt for friends name.
                            cin >> name3; //store friends name.
                            if(data.getProfileIndex(name3)>= 0){ //Check if friend exists.
                                data.deleteFriends(name2,name3); //delete friend.
                            } else {
                                cout << name3 << " does not exist." << endl; //if friend doesn't exist.
                            }
                        }
                        if(submenu == "3"){ //if change status is selected.
                            cout << "Please enter the new status of the profile." << endl; //prompt for new status.
                            cin >> status2; //store status.
                            data.updateStatus(name2, status2); //update profile status.
                        }
                        if(submenu == "4"){ //exists from submenu back to main menu.
                            end2 = 0;
                        }
                    }
                } else {
                    cout << "A Profile with the name: " << name2 << " does not exist." << endl; //if profile selected to modify doesn't exist.
                }
            end2 = 1; //reset submenu parameter.
        }
        if(menu == "5"){ //exists the main menu.
            end = 0;
        }
    }
    return 0;
}