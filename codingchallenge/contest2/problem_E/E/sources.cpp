#include <iostream>
#include "answers.h"
#include "solve.h"
#include <random>
#include <chrono>

using namespace std;
const int MOD = 1e9 + 7;
const int INF = 2e9;

namespace RandomTest {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    #define rand(l, r) uniform_int_distribution <int> (l, r) (rng)
    
    void subtask1(const string& FILE_TEST) { // n <= 5000, q <= 1000
        ofstream Fout(FILE_TEST);
        int n = rand(5, 5000);
        int q = rand(5, 1000);
        Fout << n << '\n';
        int* a = new int[n + 1];
        for (int i = 1; i <= n; i++) a[i] = rand(0, MOD - 1);
        for (int i = 1; i <= n; i++) Fout << a[i] << " "; Fout << '\n';
        for (int i = 1; i < n; i++) {
            Fout << i << " " << rand(i + 1, n) << '\n';
        }

        Fout << q << '\n';
        while (q--) {
            Fout << rand(1, 2) << " " << rand(1, n) << '\n';
        }

        Fout.close();
    }
    void subtask2(const string& FILE_TEST) { // n <= 10^5, q <= 10^5
        ofstream Fout(FILE_TEST);
        int n = rand(5, 1e5);
        int q = rand(5, 1e5);
        Fout << n << '\n';
        int* a = new int[n + 1];
        for (int i = 1; i <= n; i++) a[i] = rand(0, MOD - 1);
        for (int i = 1; i <= n; i++) Fout << a[i] << " "; Fout << '\n';
        for (int i = 1; i < n; i++) {
            Fout << i << " " << rand(i + 1, n) << '\n';
        }

        Fout << q << '\n';
        while (q--) {
            Fout << rand(1, 2) << " " << rand(1, n) << '\n';
        }

        Fout.close();
    }
}

const string FILE_TEST = "test3.txt";

int main() {
    static int cnt = 0;
    cnt++;
    cout << "TEST " << cnt << ": ";
    RandomTest::subtask2(FILE_TEST);

    Input input_problem;
    input_problem.read(FILE_TEST);
    std::vector <int> answers = answers_of_problem(input_problem);
    //std::cout << "ANSWERS: ";for (auto i : answers) cout << i << " "; cout << '\n';
    std::vector <int> output = solve_of_problem(input_problem);
    //for (auto i : output) cout << i << " "; cout << '\n'; 
    
    if (output == answers) {
        cout << "AC\n";
    }
    else {
        return cout << "WA\n", 0;
    }
    main();
    return 0;
}