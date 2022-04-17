//
// Created by jostrowsk on 9/28/2021.
//
//Name: James Ostrowski
//Date: 9/28/21
//Description: Class that creates user profiles, a user has a name, status and a friends list. Class allows for a user to add/delete friends,
// and change their status of their profile.


#ifndef HW3_PROFILE_H
#define HW3_PROFILE_H

class Profile{ //Creates a class called profile.
public:
    Profile(std::string n = "", std::string s = ""){ //Default constructor with empty strings.
        setName(n);
        setStatus(s);
    }
    void print();
    void addFriend(std::string f); //adds friends
    void deleteFriend(std::string f); //deletes friends
    std::string getName()const{return name;} //Returns name on profile.
    std::string getStatus()const{return status;}//Return status of profile.
    void setName(const std::string& n){name = n;}//Sets a new name for profile.
    void setStatus(const std::string& s){status = s;}//Sets/updates status.

private:
    std::string name;//name of profile.
    std::string status;//Status of profile.
    std::vector<std::string> friends;//Friends list for profile.
};


#endif //HW3_PROFILE_H
