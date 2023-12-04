class Solution {
public:
    // Function to find the largest good integer in a given string
    string largestGoodInteger(string num) {
        string ans = ""; // Initialize an empty string to store the result
        string empty = ""; // Initialize an empty string for a special case
        int temp = 0; // Initialize a variable to store the largest digit found
        bool check = true; // Initialize a flag to check for a specific condition

        // Loop through the string to find the largest digit occurring thrice consecutively
        for (int i = 0; i < num.size() - 2; i++) {
            // Check if the current digit is the same as the next two digits
            if (i + 2 < num.size() && num[i] == num[i + 1] && num[i] == num[i + 2]) {
                // Convert the character digit to its integer equivalent and update 'temp'
                temp = max(temp, num[i] - '0');
                check = false; // Update the flag to indicate the condition was met
            }
        }

        // If the condition was met (i.e., a triplet was found)
        if (check == false) {
            // Append the largest digit found three times to the 'ans' string
            for (int i = 0; i < 3; i++) {
                ans += to_string(temp);
            }
        } else { // If no such triplet found
            return empty; // Return the empty string
        }

        return ans; // Return the result containing the largest good integer
    }
};