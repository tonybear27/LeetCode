class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string item;

        int slots = 1;

        while(getline(ss, item, ',')) {
            if(slots == 0) return 0;

            slots--;

            if(item != "#") slots += 2;
        }

        return slots == 0;
    }
};