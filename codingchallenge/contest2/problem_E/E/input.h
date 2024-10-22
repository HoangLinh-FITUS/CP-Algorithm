#pragma once
#include <iostream>
#include <fstream>

struct Input {
    int n, q;
    int* a, * u, * v, * t, * x;

    Input() {
        a = u = v = t = x = nullptr;
        n = q = 0;
    }
    ~Input() {
        delete[] a, u, v, x, t;
    }

    void read(const std::string& name_input_file) {
        std::ifstream cin(name_input_file);
        cin >> this->n;
        a = new int[n + 1];
        u = new int[n];
        v = new int[n];

        for (int i = 1; i <= n; i++) cin >> this->a[i];
        for (int i = 1; i < n; i++) cin >> this->u[i] >> this->v[i];
        cin >> this->q;
        t = new int[q + 1];
        x = new int[q + 1];
        for (int i = 1; i <= q; i++) {
            cin >> this->t[i] >> this->x[i];
        }
        cin.close();
    }
};