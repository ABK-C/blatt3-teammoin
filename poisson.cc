#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

double poisson(double mu, int k) {
  double P = (exp(-mu) * pow(mu, k))/(tgamma(k + 1));
  return P;
}

int main() {


    ifstream fin("datensumme.txt");
    ofstream fout("hist.txt");
    ofstream fout1("histpoi.txt");
    vector<int>zaehler(11); 
    int n_i;

    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        zaehler[n_i] += 1;
    }
    
    for(int j = 0; j < zaehler.size(); ++j) {
    fout << j << " " << zaehler[j] << endl;
    fout1 << j << " " << zaehler[j] << " " << poisson(3.11538, j) * 234 << endl;
    }
    
    fin.close();

  
}