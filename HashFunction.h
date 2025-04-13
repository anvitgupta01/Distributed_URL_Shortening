#pragma once

#include <bits/stdc++.h>
using namespace std;

string hashFunction(string long_url, int how_many_times_to_shuffle = 3);
int generateRandom();
int generateRandom(int lower_bound, int upper_bound);
void shuffleVector(vector<int> &vec);
bool isPerfectSquare(int n);