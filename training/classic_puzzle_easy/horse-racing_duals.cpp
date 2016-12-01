#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
 
int main()
{
    int N;
    //int max_diff;
    vector<int> horse;
    vector<int> diff;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        horse.push_back(Pi);
    }
    sort(horse.begin(), horse.end());
    for (int i = 0; i < N - 1; i++) {
        diff.push_back(horse[i + 1] - horse[i]);    
    }
    sort(diff.begin(), diff.end());
    

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << diff[0] << endl;
}