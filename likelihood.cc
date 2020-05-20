#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

long double poisson(double mu, int k) {
  using namespace std;
  long double P = (exp(-mu) * pow(mu, k))/(tgamma(k + 1));
  return P;
}

long double prob(std::vector<int> daten, double mu) {
  using namespace std;
  long double P = 1;
  for(int k : daten) {
    P *= poisson(mu, k);
  }
  return P;
}

int main() {
    using namespace std;


    ifstream fin("datensumme.txt");
    ofstream lin("likelihood.txt");
    ofstream nll("nll.txt");
    ofstream anll("deltanll.txt");
    

    vector<int> daten(0);

    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
      fin >> n_i;
      daten.push_back(n_i);
    }

    for(double i = 0; i <= 6; i += 0.02) {
      lin << i << " " << prob(daten, i) << endl;
      nll << i << " " << -2*log(prob(daten, i)) << endl;
      anll << i << " " << -2*log(prob(daten, i)) + 2*log(prob(daten, 3.11538)) << endl;
    }  

    
    fin.close();
    lin.close();
    nll.close();

    cout << prob(daten , 3.11538) << endl;

   //bester mu-Wert bei 2b und d: ca. 3.115
   //Intervall mit mu<1 ca. (3.001-3.235)
   //also: mu=3.115 +0.12 -0.114
}