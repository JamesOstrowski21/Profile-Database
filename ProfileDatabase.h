//
// Created by jostrowsk on 9/28/2021.
//
//Name: James Ostrowski
//Date: 9/28/21
//Description: ProfileDatabase class creates a database of profiles, allows the user to add/delete profiles as well as edit
//existing profiles individually. Using the profile class methods as well as its own database methods.

#ifndef HW3_PROFILEDATABASE_H
#define HW3_PROFILEDATABASE_H

#include "Profile.h"

class ProfileDatabase{ //Creates class called ProfilesDatabase.
public:
    ProfileDatabase() = default; //Default constructor initialized.
    void addProfile(Profile p); //adds profiles
    void deleteProfile(std::string d); //deletes profiles
    void addFriends(std::string n1, std::string n2); //adds friends
    void deleteFriends(std::string n3, std::string n4); //deletes friends
    void updateStatus(std::string s, std::string s1); //updates status
    void print(); //prints list of profiles
    int amountProfiles() {return profiles.size();} //How many profiles in the database.
    int getProfileIndex(std::string i); //returns profile index
    Profile getProfile(std::string nm); //returns profile in list
private:
    std::vector<Profile> profiles;//Creates a vector of profiles to store list of profiles.

};
#endif //HW3_PROFILEDATABASE_H
