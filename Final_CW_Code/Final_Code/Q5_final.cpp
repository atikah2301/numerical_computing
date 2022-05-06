#include <iostream>
#include <iomanip>
#include <valarray>

#define set << setw(26) << fixed << setprecision(18) <<
#define cld const long double
#define cld_valarray const valarray<long double>
#define ld_valarray valarray<long double>
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

// Hermite's 2nd Order Method = Trapezium Rule Method for Systems of ODEs
valarray<long double> H2(cld& t1, cld_valarray& u1, cld& dt, ld_valarray f(cld&, cld_valarray&)){
    long double t2 = t1 + dt;
    unsigned int imax = 8;
    valarray<long double> u2 = u1; //initial guess
    for(int i = 0; i<imax; ++i) {
        u2 = u1 + 0.5 * dt * (f(t1, u1) + f(t2, u2));  //trapezium rule
    }
    return u2;
}

valarray<long double> RK2(cld& t, cld_valarray& u, cld& dt, ld_valarray f(cld&, cld_valarray&)){
    unsigned long long m = u.size();
    valarray<long double> k1(m), k2(m);
    k1 = dt * f(t, u);
    k2 = dt * f(t + 0.5 * dt, u + 0.5 * k1);
    return u + k2;
}

int main() {
    const long double t_initial = 0.0L;
    const long double t_final = 10.0L;
    const int N = 10000; // number of time steps
    const long double delta_t = (t_final - t_initial) / (long double)N;
    valarray<long double> time_steps(N + 2);   //[0],T[1],...,T[n],T[n+1]
    valarray<valarray<long double>> U(N + 2);
    valarray<long double> energy(N + 2);
    valarray<long double> error(N + 2);

    // set the initial u[0] = q_0 = -1/2, u[1] = p_0 = 0
    U[0][0] = -0.5L;
    U[0][1] = 0.0L;

    // PART (A)

    // create a header for table
    cout << "Part (a)" << endl;
    cout << 't' set 'x' set 'y' set 'error' << endl;

    for (int j = 0; j <= N; j++){
        time_steps[j] = t_initial + (long double)j * delta_t; // calculate the next time step
        U[j + 1] = RK2(time_steps[j], U[j], delta_t, F); // approximate the next U using RK4 and previous U
        // E = (1/2)(p^2) + V(q),    V(q)= (1/2) k q^2
        energy[j] = 0.5L * (U[j][1] * U[j][1] + U[j][0] * U[j][0]); // calculate the next energy value
        cout << time_steps[j] set U[j][0] set U[j][1] set energy[j] << endl; // tabulate all
        cout << "hi" << endl;
    }

    // PART (C)

    // create a header for table
    cout << "Part (c)" << endl;
    cout << 't' set 'x' set 'y' << endl;

    for (int j = 0; j <= N; j++){
        time_steps[j] = t_initial + (long double)j * delta_t; // calculate the next time step
         U[j + 1] = H2(time_steps[j], U[j], delta_t, F); // approximate the next U using H2 and previous U
        // E = (1/2)(p^2) + V(q),    V(q)= (1/2) k q^2
        energy[j] = 0.5L * (U[j][1] * U[j][1] + U[j][0] * U[j][0]); // calculate the next energy value
        cout << time_steps[j] set U[j][0] set U[j][1] set energy[j] << endl; // tabulate all
        cout << "hi" << endl;
    }

}