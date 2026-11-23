#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string name[100], surname[100];
    double score[100];
    int n = 0;

    ifstream in("students.txt");
    while (in >> name[n] >> surname[n] >> score[n]) n++;

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (score[j] < score[j + 1]) {
                swap(name[j], name[j + 1]);
                swap(surname[j], surname[j + 1]);
                swap(score[j], score[j + 1]);
            }

    ofstream out("sorted.txt");
    for (int i = 0; i < n; i++)
        out << name[i] << " " << surname[i] << " " << score[i] << "\n";
    return 0;
}
