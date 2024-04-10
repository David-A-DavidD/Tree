// SearchService.h
#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include <vector>

#include "FileReader.h"
#include "SharedData.h"  //only including right now, may remove if unnecessary
#include "User.h"
#include "UserManager.h"

// most likely not functional
class Search {
   public:
    Search(SharedData& sharedData) : sharedData(sharedData) {}

    // Function to perform a search for users based on query and user permissions
    std::vector<User> searchUsers(const std::string& query, bool isAdmin, bool isSellingGames) {
        std::vector<User> searchResults;

        // Get the vector of users from shared data
        std::vector<User>& users = sharedData.getUsers();

        // Iterate through users to find matches with the query
        for (const User& user : users) {
            // Check if the user's name contains the search query
            if (user.getUsername().find(query) != std::string::npos) {
                // If the user is not an administrator or is selling games, add to search results
                if (!isAdmin || (!user.isAdmin() || isSellingGames)) {
                    searchResults.push_back(user);
                }
            }
        }

        return searchResults;
    }

   private:
    SharedData& sharedData;
};

#endif