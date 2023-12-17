class FoodRatings {
private:
    // Mapping from food names to pairs of cuisine and rating
    unordered_map<string, pair<string, int>> foodToCosine;

    // Mapping from cuisine to ratings and corresponding set of food names
    unordered_map<string, map<int, set<string>>> cosineToRating;

public:
    // Constructor to initialize the FoodRatings object with data
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            // Assign the cuisine and rating to the food name in foodToCosine map
            foodToCosine[foods[i]] = make_pair(cuisines[i], ratings[i]);

            // Insert the food name into the set corresponding to its cuisine and rating
            cosineToRating[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }

    // Method to change the rating of a food item
    void changeRating(string food, int newRating) {
        // Destructuring assignment to get cuisine and current rating of the food
        auto& [cosine, rating] = foodToCosine[food];

        // Erase the food from the set corresponding to its cuisine and current rating
        cosineToRating[cosine][rating].erase(food);

        // If the set becomes empty after erasing, remove the rating from the map
        if (cosineToRating[cosine][rating].empty()) {
            cosineToRating[cosine].erase(rating);
        }

        // Update the rating of the food to the new rating
        rating = newRating;

        // Insert the food into the set corresponding to its cuisine and new rating
        cosineToRating[cosine][newRating].insert(food);
    }

    // Method to get the highest-rated food for a given cuisine
    string highestRated(string cuisine) {
        // Retrieve the map of ratings and food sets for the given cuisine
        auto& ratings = cosineToRating[cuisine];

        // Get an iterator pointing to the entry with the highest rating
        auto maxRatingIt = ratings.empty() ? ratings.end() : prev(ratings.end());

        // If the iterator is valid and the set is not empty, return the first food in the set
        if (maxRatingIt != ratings.end() && !maxRatingIt->second.empty()) {
            return *maxRatingIt->second.begin();
        }

        // Return an empty string if no food is found
        return "";
    }
};