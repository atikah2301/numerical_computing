#include <iostream>
#include <iomanip>
#include <valarray>

#define set << setw(26) << fixed << setprecision(18) <<
#define cld const long double
#define cld_valarray const valarray<long double>
using namespace std;

valarray<long double> F(cld& t, cld_valarray& u){
    // F = dU/dt = f(t,U) = {p, -V'(q)} where U = {q, p}
    valarray<long double> f(u.size());
    long double q = u[0];
    long double p = u[1];
    f[0] = p;
    f[1] = -(3.0L * q * q + q); // -V'(q) = -(3q^2 + q)
    return f;
}

// for Hermite 4th order
valarray<long double> dF(cld& t, cld_valarray& u){
    // dF(t,u(t))/dt
    valarray<long double> df(u.size());
    long double q = u[0];
    long double p = u[1];
    df[0] = -q;
    df[1] = -p;
    return df;
}

valarray<long double> RK4(cld& t, cld_valarray& u, cld& dt, valarray<long double> f(cld&, cld_valarray&)){
    unsigned long long m = u.size();
    valarray<long double> k1(m), k2(m), k3(m), k4(m);
    k1 = dt * f(t, u);
    k2 = dt * f(t + 0.5 * dt, u + 0.5 * k1);
    k3 = dt * f(t + 0.5 * dt, u + 0.5 * k2);
    k4 = dt * f(t + dt, u + k3);
    return u + (k1 + 2.*(k2 + k3) + k4)/6.0;
}

valarray<long double> RK2(cld& t, cld_valarray& u, cld& dt, valarray<long double> f(cld&, cld_valarray&)){
    unsigned long long m = u.size();
    valarray<long double> k1(m), k2(m);
    k1 = dt * f(t, u);
    k2 = dt * f(t + 0.5 * dt, u + 0.5 * k1);
    return u + k2;
}

int main() {
    const long double t_initial = 0.0L;
    const long double t_final = 10.0L;
    const int N = 1000; // number of time steps
    const long double delta_t = (t_final - t_initial) / (long double)N;
    valarray<long double> time_steps(N + 2);   //[0],T[1],...,T[n],T[n+1]
    valarray<valarray<long double>> U(N + 2);
    valarray<long double> energy(N + 2);

    // set the initial u[0] = q_0 = -1/2, u[1] = p_0 = 0
    U[0][0] = -0.5L;
    U[0][1] = 0.0L;

    // create a header for table
    cout << 't' set 'x' set 'y' << endl;

    for (int j = 0; j <= N; j++){
        time_steps[j] = t_initial + (long double)j * delta_t; // calculate the next time step
        U[j + 1] = RK4(time_steps[j], U[j], delta_t, F); // approximate the next U using RK4 and previous U
        // E = (1/2)(p^2) + V(q),    V(q)= (1/2) k q^2
        energy[j] = 0.5L * (U[j][1] * U[j][1] + U[j][0] * U[j][0]); // calculate the next energy value
        cout << time_steps[j] set U[j][0] set U[j][1] set energy[j] << endl; // tabulate all
    }

}