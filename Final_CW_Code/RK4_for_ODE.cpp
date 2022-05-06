#include <iostream>
#include <iomanip>
#include <valarray>

#define set << setw(26) << fixed << setprecision(16) <<    // save some repetition when writing
using namespace std;

valarray<long double> F(const long double &t, const valarray<long double> &u){
    valarray<long double> f(u.size());
    // u[0] = x, u[1] = y   notes
    // y[0] = x, y[1] = y   slides
    f[0] = u[1];          //encodes components of du/dt = f(t,u(t))
    f[1] = -u[0];
    return f;
}

valarray<long double> RK4(long double &t, valarray<long double> &u, long double &dt, valarray<long double> f(const long double&, const valarray<long double>&)){
    unsigned long long m = u.size();    //int m
    valarray<long double> k1(m), k2(m), k3(m), k4(m);

    k1 = dt * f(t, u);
    k2 = dt * f(t + 0.5 * dt, u + 0.5 * k1);
    k3 = dt * f(t + 0.5 * dt, u + 0.5 * k2);
    k4 = dt * f(t + dt, u + k3);
    return u + (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
}

int main() {
    long double t_initial = 0.0L;
    long double t_final = 10.0L;
    int n = 1000; // number of time steps
    long double delta_t = (t_final - t_initial) / (long double)n;  // time step size
    valarray<long double> time_steps(n+2); // store time steps T[0], T[1], ..., T[n], T[n+1]
    valarray<valarray<long double>> U(n+2);
    valarray<long double> energy(n+2);  // Energy

    // set initial values at t = t_initial
    U[0] = {1., 0.};

    // print table header
    cout << 't' set 'x' set 'y' set 'e' << endl;

    for (int j = 0; j <= n; j++){
        time_steps[j] = t_initial + (long double)j * delta_t; // calculate the next time step
        U[j+1] = RK4(time_steps[j], U[j], delta_t, F); // approximate the next U using RK4 and previous U
        energy[j] = 0.5 * (U[j][0] * U[j][0] + U[j][1] * U[j][1]); // calculate the next energy value
        cout << time_steps[j] set U[j][0] set U[j][1] set energy[j] << endl; // tabulate
    }

    return 0;
}