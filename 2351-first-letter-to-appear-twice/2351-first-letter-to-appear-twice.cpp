class Solution {
public:
    char repeatedCharacter(string s) {

        bool arr[26] = {false}; // This stores the false array of 26 indexing 

        for (int i = 0; i < s.size(); i++) {

            int index = s[i] - 'a';  // this compares ascii values and store in the index

            if (arr[index]) {
                return s[i];
            }

            arr[index] = true; 
            // Mark this character as already seen. (kuch nhi bas jo dikh gaye hai and same nhi unhe true kar raha hai)

            // Aur sath hi loop bhi end kar raha hai agar same index mila toh if wale ko bhej dega aur vo return kardega simple 
        }

        return ' '; // Kuch toh char return karna tha toh ye kardiya :)
    }
};