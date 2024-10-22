#pragma once
#include <vector>
#include "input.h"

extern const int MOD;

std::vector <int> answers_of_problem(const Input& input) {
    std::vector <std::vector<int>> G;
    G.resize(input.n + 1);
    for (int i = 1; i < input.n; i++) {
        G[input.u[i]].push_back(input.v[i]);
        G[input.v[i]].push_back(input.u[i]);
    }
    
    std::vector <int> a(input.n + 1);
    for (int i = 1; i <= input.n; i++) a[i] = input.a[i];

    std::vector <int> output;
    for (int i = 1; i <= input.q; i++) {
        if (input.t[i] == 1) {
            int x = input.x[i];
            for (auto v : G[x]) {
                a[v] += a[x];
                a[v] %= MOD;
            }
        }
        else {
            int x = input.x[i];
            int Total_S = 0;
            for (auto v : G[x]) {
                Total_S += a[v];
                Total_S %= MOD;
            }
            output.push_back(Total_S);
        }
    }
    return output;
}