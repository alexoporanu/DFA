#include <iostream>

#include <queue>

#include <vector>

#include <fstream>

using namespace std;

unsigned int i;
int j, n, m, stare_1, stare_2, stare_i, stare_f, nr_stringuri, nr_finale;
char c;
string de_acceptat;

typedef pair < int, char > tranzitie;
vector < tranzitie > dfa[1001];
bool final[1001];

ifstream f("dfa.in");
ofstream g("dfa.out");

int e_acceptat(string de_acceptat) {
  int ok;
  int k;
  char temp;
  int stare_crt;
  vector < int > traseu;
  queue < int > litere;

  if (de_acceptat == "#")
    if (final[stare_i] == true) {
      g << "DA\n";
      g << "Traseu: " << stare_i << "\n";
      return true;
    }

  for (i = 0; i < de_acceptat.size(); i++)
    litere.push(de_acceptat[i]);

  stare_crt = stare_i;
  traseu.push_back(stare_i);

  while (1) {

    temp = litere.front();

    if (litere.empty())
      if (final[stare_crt] == true) {
        g << "DA\n";
        g << "Traseu: ";
        for (k = 0; k < traseu.size(); k++)
          g << traseu[k] << " ";
        g << "\n";

        return true;
      }
    else {
      g << "NU" << "\n";
      return false;
    }

    ok = 0;
    for (i = 0; i < dfa[stare_crt].size(); i++) {
      if (dfa[stare_crt][i].second == temp) {

        traseu.push_back(dfa[stare_crt][i].first);
        stare_crt = dfa[stare_crt][i].first;
        litere.pop();
        ok = 1;

        break;

      }
    }
    if (ok == 0) {
      g << "NU\n";
      return false;

    }
  }

}

int main() {

  f >> n >> m;
  int i;

  for (i = 0; i < m; i++) {
    f >> stare_1;
    f >> stare_2;
    f >> c;

    dfa[stare_1].push_back({stare_2,c});
  }

  f >> stare_i;

  f >> nr_finale;

  for (i = 0; i < nr_finale; i++) {
    f >> stare_f;
    final[stare_f] = true;
  }

  f >> nr_stringuri;

  for (j = 0; j < nr_stringuri; j++) {
    f >> de_acceptat;
    e_acceptat(de_acceptat);
  }

  return 0;

}
