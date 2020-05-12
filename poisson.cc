#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

double poisson(double mu, int k) {
    return 0;
}

int main() {


    ifstream fin("datensumme.txt");
    ofstream fout("hist.txt");
    vector<int>zaehler(11); 
    int n_i;

    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        zaehler[n_i] += 1;
    }
    
    for(int j = 0; j < zaehler.size(); ++j) {
    fout << j << " " << zaehler[j] << endl;
    }
    
    fin.close();

  
}