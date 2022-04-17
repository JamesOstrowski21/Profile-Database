//
// Created by jostrowsk on 9/28/2021.
//
//Name: James Ostrowski
//Date: 9/28/21
//Description: Profile.cpp holds the function of the Profile class, allows for user to use options of adding/deleting friends and changing their status.
#include <vector>
#include <string>
#include <iostream>
#include "Profile.h"


//Description: addFriend() adds a friend to the profile's friends list.
//Inputs: string of the name of the friend to be added.
//Outputs: whether or no the friend is already on the list or when it is added to the list.
void Profile::addFriend(std::string f){ //AddFriend takes a name and adds it to the friends list of profile.
    int c = 0;
    for(int x = 0; x < friends.size();x++){//Checks to see if name is already in friends list.
        if(friends[x]== f){
            c = 1;
        }
    }
    if(c == 1){ //Output if already in friends list.
        std::cout << name << " already has " << f << " as a friend" << std::endl;
    } else{ //If not already, adds to vector for friends list and outputs to the screen.
        friends.push_back(f);
        std::cout << f << " added as a friend" << std::endl;
    }
}

//Description: deleteFriend removes a friend from the friends list.
//Inputs: string representing name of friend to remove.
//Outputs: text of whether or not the string has been added to the friends list.
void Profile::deleteFriend(std::string f){ //DeleteFriend takes a name and removes it from the profile's friends list.
    int c = 1;
    for(int x = 0; x < friends.size();x++){//Finds the name in the friends list.
        if(friends[x] == f){ //When it finds name, erase it from friends list.
            c= 0;
            friends.erase(friends.begin()+x);//Erases name.
        }
    }
    if (c==0){ //Output that friend has been removed from list.
        std::cout << f << " has been removed from friends list" << std::endl;
    }
    if(c==1){//If name is not in friends list to begin with.
        std:: cout << f << " is not a friend of " << name << std::endl;
    }
}

//Description: print() prints the profiles contents to the screen.
//Inputs: none
//Outputs: contents of the profile.
void Profile::print(){//Prints profile to screen.
    std::cout << "Name: " << name << std:: endl;//Name
    std::cout << "Status: " << status << std::endl;//Status
    std:: cout << "Friends: " << std:: endl;
    for(int x = 0; x < friends.size();x++){//Loops and outputs vector of friends.
        std::cout << friends[x] << std::endl;
    }
}