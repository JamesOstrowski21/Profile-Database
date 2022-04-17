//
// Created by jostrowsk on 9/28/2021.
//
//Name: James Ostrowski
//Date: 9/28/21
//Description: ProfileDatabase.cpp holds the functions to modify the database of profiles as when as the individual profiles.
#include <vector>
#include <iostream>
#include "ProfileDatabase.h"
#include "Profile.h"

//Description: addProfile() adds a profile to the database.
//Inputs: profile of type profile.
//Outputs: only prints if profile already exists and when it is added.
void ProfileDatabase::addProfile(Profile p) { //Adds a profile to the database.
    int b = 1; //Temp variable for if profile is existing.
    int x = 0;//Loop counter.
    while (b != 0 && x < profiles.size()){//While loop cycles through list of profiles.
        if(p.getName() == profiles[x].getName()){//Check if profile at index match name parameter.
            b = 0; //These two lines end the loop because profile already exists.
            x = profiles.size();
            std::cout << "Warning: a profile with that name already exists, Profile not added" << std::endl;
        }
        x ++;
    }

    if(b == 1){ //If profile doesnt already exist it gets added.
        std::cout<< "A profile with the name " << p.getName() << " was added to the network" << std::endl;
    }
    if(b == 1){ //Profiles added to vector of profiles.
        profiles.push_back(p);
    }

}

//Description: getProfile() returns a profile from the list in database.
//Inputs: string that contains the name of the profile.
//Outputs: return the profile from the list.
Profile ProfileDatabase::getProfile(std::string nm) { //Returns a profile from the list.
    int b =0;
    for(int x =0; x < profiles.size();x++){ //Loops through and finds profile by matching name from parameter.
        if(profiles[x].getName()== nm){
            b = 1;
            return profiles[x]; //Returns profile.
        }
    }
    if (b == 0){ //If Profile is not found in loop it does not exist.
        return (Profile("missing profile", "")); //returns empty missing profile.
    }
}

//Description: deleteProfile() deletes a profile from the database and from any and all friends lists.
//Inputs: string of name of profile to be deleted.
//Outputs: only when profile is deleted or profile does not exist.
void ProfileDatabase::deleteProfile(std::string d) {//Deletes a profile form the list.
    int b = 0;
    for(int x = 0;x < profiles.size();x++){ //Loops through list to find profile user would like to delete.
        if(d == profiles[x].getName()){
            b =1;
            profiles.erase(profiles.begin()+x);//Removes the profile form the list.
            for(int y = 0; y<profiles.size();y++){//Removes profile from each persons friends list.
                profiles[y].deleteFriend(d);
            }
        }
    }
    if(b == 1){ //Output profile has been removed.
       std::cout << d << " has been removed from the database" << std::endl;
    }
    if(b == 0){//Output for is the profile name does not exist.
        std::cout << d << " does not exist" << std::endl;
    }
}
//Description: getProfileIndex() gets the index of the profile in the list.
//Inputs: string that is the name of profile.
//Outputs: returns the index of profile or (-1) if no profile exists.
int ProfileDatabase::getProfileIndex(std::string i){//Gets the index of the profile base on name.
    int index = -1; //Sets base to -1 because function previously return 0 if no match found which is still a valid index.
    for(int x = 0; x < profiles.size();x++){//Loops through to find matching name.
        if(i == profiles[x].getName()){
            index =  x;
        }
    }
    return index;
}

//Description: addFriends() adds friends to each others friend's list.
//Inputs: two strings containing two names to be added as friends.
//Outputs: prints if friends cant be added or that the friends have been added.
void ProfileDatabase::addFriends(std::string n1, std::string n2) {//Takes two profiles and adds them to each others friends list.
    if((getProfileIndex(n1) >= 0 && getProfileIndex(n2) >= 0)){//Checks to make sure both profiles exist.
        if(n1 == n2){ //If both names are the same output error or invalid.
            std::cout << "Invalid input to addFriends:" << n1 << " cannot be added to its own friends list" << std::endl;
        } else {//if they arent the same add to each others friends list.
            profiles[getProfileIndex(n1)].addFriend(n2);
            profiles[getProfileIndex(n2)].addFriend(n1);
        }
    } else if(getProfileIndex(n1) < 0){ //If first name does not exist.
        std::cout << n1 << " has no profile" << std::endl;
    } else if(getProfileIndex(n2) < 0){//If second name does not exist.
        std::cout << n2 << " has no profile" << std::endl;
    }
}

//Description: deleteFriends() deletes friends from each others friends list.
//Inputs: takes two strings containing the names of friends to be deleted.
//Outputs: prints if input is valid or when friends are deleted.
void ProfileDatabase::deleteFriends(std::string n3, std::string n4){//Takes two names and deletes each other from friends list.
    if((getProfileIndex(n3) >= 0 && getProfileIndex(n4)>=0)){//Checks to make sure both profiles exist.
        if(n3 == n4){//Checks to make sure both names no the same.
            std::cout << "Invalid input to deleteFriends:" << n3 << " cannot be added to its own friends list" << std::endl;
        } else {
            profiles[getProfileIndex(n3)].deleteFriend(n4);//Removes each other from friends list.
            profiles[getProfileIndex(n4)].deleteFriend(n3);
        }
    } else if(getProfileIndex(n3) < 0){//If name 1 doesn't exist.
        std::cout << n3 << " has no profile" << std::endl;
    } else if(getProfileIndex(n4) < 0){//If name 2 doesn't exist.
        std::cout << n4 << " has no profile" << std::endl;
    }
}

//Description: updateStatus() updates the status of a profile
//Inputs: string of name of profile, and string of new status.
//Outputs: prints if the status was updated and what the new status is.
void ProfileDatabase::updateStatus(std::string s, std::string s1) { //Updates the current status of a profile.
    if(getProfileIndex(s) >= 0){//Finds the profile and makes sure it exists.
        profiles[getProfileIndex(s)].setStatus(s1);//Updates profile status.
        std::cout << s << "'s status was updated to " << s1 << std::endl;
    } else{//Else if doesn't exist.
        std::cout << s << " does not exist. Status was not updated" << std::endl;
    }
}

//Description: print() prints the list of profiles in the database.
//Inputs: none
//Outputs: prints the list of profiles in the database.
void ProfileDatabase::print(){//Prints out the list of profiles.
    for(int x = 0; x < profiles.size(); x++){
        std::cout << profiles[x].getName() << std::endl;
    }
}