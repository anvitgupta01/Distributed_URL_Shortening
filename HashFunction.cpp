#include "hashFunction.h"

std::vector<char> shortURL_chars = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
    'U', 'V', 'W', 'X', 'Y', 'Z', 
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
    'u', 'v', 'w', 'x', 'y', 'z', 
    '!', '@', '#', '$'
};

string hashFunction(string long_url, int how_many_times_to_shuffle) {
    string hash_value = ""; // shortURL can be generated using the hash_value

    vector<int> hash_in_int = {}, temp = {};
    int random_int = -1, m;

    // push the characters present in the long_url
    for (auto e : long_url) {
        hash_in_int.push_back(e);
    }

    // convert the number of characters to perfect square
    while(!isPerfectSquare(hash_in_int.size())) {
        random_int = generateRandom();
        hash_in_int.push_back(random_int);
    }

    // shuffle the vector
    for (int i=0;i < how_many_times_to_shuffle; i++) {
        shuffleVector(hash_in_int);
    }
    
    // form m charaters out of m*m characters
    m = sqrt(hash_in_int.size());
    for (int i=0;i < hash_in_int.size();i += m) {
        int sum = accumulate(hash_in_int.begin()+i, hash_in_int.begin()+i+m-1,0);
        sum %= 128;
        temp.push_back(sum);
    }
    
    // convert m characters into 7
    if (m == 1 || m == 2) {
        for (int i=0;i<7;i++) {
            random_int = generateRandom(0,65);
            hash_value += string(1, shortURL_chars[random_int]);
        }
    } else {
        int num_of_indexes_picked = m / 3;

        for (int idx = 0; idx < 7; idx++) {
            int sum = 0;
            for (int i=0;i<num_of_indexes_picked;i++) {
                random_int = generateRandom(0,m-1);
                sum += temp[random_int];
            }
            sum %= 66;
            hash_value += string(1, shortURL_chars[sum]);
        }
    }

    return hash_value;
}

int generateRandom() {
    random_device rd;
    mt19937 gen(rd());  // Mersenne Twister generator for integers
    
    int lower_bound = 0, upper_bound = 127LL;
    uniform_int_distribution<int> dist(lower_bound, upper_bound);
    
    int random_number = dist(gen);
    
    return random_number;
}

int generateRandom(int lower_bound, int upper_bound) {
    random_device rd;
    mt19937 gen(rd());  // Mersenne Twister generator for integers
    
    uniform_int_distribution<int> dist(lower_bound, upper_bound);
    
    int random_number = dist(gen);
    
    return random_number;
}

void shuffleVector(vector<int> &vec) {
    random_device rd;
    mt19937 gen(rd());  // Mersenne Twister random number generator

    shuffle(vec.begin(), vec.end(), gen);
}

bool isPerfectSquare(int n) {
    int x = sqrt(n);
    return ((x*x == n) ? 1 : 0);
}