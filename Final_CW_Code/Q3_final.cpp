#include <iostream> // for cout
#include <iomanip> // for setprecision()
#include <fstream> // for ofstream, is_open()
#include <valarray> // for valarrays
#include <cmath> // for exp(), pow() - overloading for long doubles and valarrays

#define set << setprecision(10)
using namespace std;

// Function Declarations

// Tabulating & Printing Output
void print_valarray(const valarray<long double>& A);
string tabulated_format(const long double& x, const int& decimals, const int& width);
string centre_align(const string& str, const int& width);
// Part (a)
long double known_function(const long double& x);
valarray<long double> known_function(const valarray<long double>& X);
valarray<long double> known_function_2nd_derivatives(const valarray<long double>& X);
valarray<long double> finite_differences(const valarray<long double>& X);
// Part (b)
long double kahan_sum(const valarray<long double>& v);
long double mean_error(const valarray<long double>& errors);
valarray<valarray<long double>> run_comparison(const valarray<int>& N_values);

int main()
{
    // Part (a) - Finite Differences Method
    int N = 63; // x values numbered using i = 0, 1, .., N => valarrays should have N + 1 elements
    valarray<long double> X(N + 1); // x_i
    valarray<long double> F(N + 1); // f(x_i)
    valarray<long double> analytical_2nd_derivatives(N + 1); // f''(x_i)
    valarray<long double> numerical_2nd_derivatives(N + 1); // f''_i
    valarray<long double> errors(N + 1); // e_i
    long double mean_err;
    long double n_sqr_mean_err;

    // Calculate the values and store them
    for (int i = 0; i <= N; i++) {
        X[i] = (long double)((2 * i) - N) / (long double)N;
    }
    F = known_function(X);
    analytical_2nd_derivatives = known_function_2nd_derivatives(X);
    numerical_2nd_derivatives = finite_differences(X);
    errors = analytical_2nd_derivatives - numerical_2nd_derivatives;
    mean_err = mean_error(errors);
    n_sqr_mean_err = (long double)(N * N) * mean_err;

    // print calculations
    cout << "X = \n"; print_valarray(X); // x values should be equidistant and in the interval [-1, 1]
    cout << "F(X) = \n"; print_valarray(F);
    cout << "F''(X) Numerical = \n"; print_valarray(numerical_2nd_derivatives); // should be similar to analytical values
    cout << "F''(X) Analytical = \n"; print_valarray(analytical_2nd_derivatives); // approx = 0, .., 14, .., -32, .., 14, .., 0
    cout << "Error = \n"; print_valarray(errors);

    // Part (a) - Tabulate
    int width = 15;
    int decimals = 10;

    // set up the headings
    cout
            << centre_align("i", 5) << " | "
            << centre_align("x", 10) << " | " << centre_align("f(x)", width) << " | "
            << centre_align("f''(x) exact", width) << " | " << centre_align("f''(x) approx", width) << " | "
            << centre_align("error", width) << endl
            << string(width * 6, '-') << endl; // create the headings' underline

    // assign values from each valarray to their own columns
    for (int i = 0; i <= N; i++) {
        cout
                << tabulated_format(i, 0, 5) << " | "
                << tabulated_format(X[i], 5, 10) << " | "
                << tabulated_format(F[i], decimals, width) << " | "
                << tabulated_format(analytical_2nd_derivatives[i], decimals, width) << " | "
                << tabulated_format(numerical_2nd_derivatives[i], decimals, width) << " | "
                << tabulated_format(errors[i], decimals, width) << endl;
    }

    // Part (a) - save all outputs to a file
    ofstream file_1("C:\\Users\\atika\\Desktop\\all_data.txt");
    if (file_1.is_open()) {
        for (int i = 0; i <= N; i++)  {
            file_1 set
            << X[i] << "\t"
            << F[i] << "\t"
            << analytical_2nd_derivatives[i] << "\t"
            << numerical_2nd_derivatives[i] << "\t"
            << errors[i] << "\n";
        }
        cout << "Output saved to file successfully!" << endl;
    }
    else
        cout << "Error with saving output to file." << endl;

    // Part (a) - save outputs needed for plot to a file
    ofstream file_2("C:\\Users\\atika\\Desktop\\numerical_2nd_derivatives.txt");
    if (file_2.is_open()) {
        for (int i = 0; i <= N; i++)  {
            file_2 set
                    << X[i] << "\t"
                    << numerical_2nd_derivatives[i] << "\n";
        }
        cout << "Output saved to file successfully!" << endl;
    }
    else
        cout << "Error with saving output to file." << endl;


    // Part (b) - Obtain N^2*MeanError values from different N values
    valarray<int> N_values = {15, 31, 63, 127, 255};
    valarray<valarray<long double>> all_data = run_comparison(N_values);
    cout << "mean errors = \n"; print_valarray(all_data[0]);
    cout << "N^2 * mean errors = \n"; print_valarray(all_data[1]);
    cout << "delta^2 = \n"; print_valarray(all_data[2]);

    // Part (b) - Tabulate
    int width_2 = 15;
    int decimals_2 = 10;

    // set up the headings
    cout
            << centre_align("N", 5) << " | "
            << centre_align("<e>", width_2) << " | "
            << centre_align("N^2 * <e>", width_2) << " | "
            << centre_align("Delta^2", width_2) << endl
            << string(width * 4, '-') << endl; // create the headings' underline

    // assign values from each valarray to their own columns
    for (int i = 0; i < N_values.size(); i++) {
        cout
                << tabulated_format(N_values[i], 0, 5) << " | "
                << tabulated_format(all_data[0][i], decimals_2, width_2) << " | "
                << tabulated_format(all_data[1][i], decimals_2, width_2) << " | "
                << tabulated_format(all_data[2][i], decimals_2, width_2) << endl;
    }

    // Part(b) - save output to file
    ofstream file_3("C:\\Users\\atika\\Desktop\\log_comparison_data.txt");
    if (file_3.is_open()) {
        for (int i = 0; i <= N_values.size(); i++)  {
            file_3 set
                    << log(N_values[i]) << "\t"
                    << log(all_data[0][i]) << "\n";
        }
        cout << "Output saved to file successfully!" << endl;
    }
    else
        cout << "Error with saving output to file." << endl;

}

// Function Definitions

void print_valarray(const valarray<long double>& A) {
    cout << "{ ";
    for (int i = 0; i < A.size(); i++){
        cout set << A[i] << ", ";
    }
    cout << " }" << endl;
}

string tabulated_format(const long double& x, const int& decimals, const int& width) {
    stringstream ss;
    ss << fixed << internal; // set the alignment of each number
    ss.precision(decimals); // set the number of decimal points on display for each number
    ss.fill(' '); // use space within single quotes to denote char instead of string
    ss.width(width); // set the width of the column for the table
    ss << x;

    return ss.str();
}

string centre_align(const string& str, const int& width) {
    stringstream ss;
    stringstream spaces;

    const int str_pad = width - str.size(); // set the size of the padding based on the desired width and string length
    for (int i = 0; i < str_pad / 2; ++i) {
        spaces << " "; // create padding
    }

    ss << spaces.str() << str << spaces.str(); // combine the spacing and output string
    if (str_pad % 2 != 0 && str_pad > 0) { // even out the padding
        ss << " ";
    }

    return ss.str();
}

long double known_function(const long double& x) {
    long double x_sqr = pow(x, 2.0L);
    return exp(-16.0L * x_sqr);
}

valarray<long double> known_function(const valarray<long double>& X) {
    valarray<long double> X_sqr = pow(X, 2.0L);
    return exp(-16.0L * X_sqr);
}

valarray<long double> known_function_2nd_derivatives(const valarray<long double>& X) {
    valarray<long double> X_sqr = pow(X, 2.0L);
    return (1024.0L * X_sqr - 32.0L) * exp(-16.0L * X_sqr);
}

valarray<long double> finite_differences(const valarray<long double>& X) {
    int N = X.size() - 1; // = 63
    long double delta = 2.0L / (long double)N; // = 0.031746...
    long double delta_sqr = delta * delta; // = 0.00010078...
    valarray<long double> results(N + 1);
    // when i = 0, and when i = N
    results[0] = (known_function(X[2]) - 2.0L * known_function(X[1]) + known_function(X[0])) / delta_sqr;
    results[N] = (known_function(X[N]) - 2.0L * known_function(X[N-1]) + known_function(X[N-2])) / delta_sqr;
    // when i = 1, 2, .., N - 1
    for (int i = 1; i < N; i++) {
        results[i] = (known_function(X[i + 1]) - 2.0L * known_function(X[i]) + known_function(X[i - 1])) / delta_sqr;
    }
    return results;
}

long double kahan_sum(const valarray<long double>& v) {
    long double sum = 0.0;
    long double c = 0.0;
    long double y;
    long double t;
    for(int i = 0; i < v.size(); ++i) {
        y = v[i] - c;
        t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
}

long double mean_error(const valarray<long double>& errors) {
    return kahan_sum(abs(errors)) / errors.size();
}

void run_comparison(const int& N) {
    valarray<long double> X(N + 1); // x_i
    valarray<long double> F(N + 1); // f(x_i)
    valarray<long double> analytical_2nd_derivatives(N + 1); // f''(x_i)
    valarray<long double> numerical_2nd_derivatives(N + 1); // f''_i
    valarray<long double> errors(N + 1); // e_i
    long double mean_err;
    long double n_sqr_mean_err;

    // Calculate the values and store them
    for (int i = 0; i <= N; i++) {
        X[i] = (long double)((2 * i) - N) / (long double)N;
    }
    F = known_function(X);
    analytical_2nd_derivatives = known_function_2nd_derivatives(X);
    numerical_2nd_derivatives = finite_differences(X);
    errors = analytical_2nd_derivatives - numerical_2nd_derivatives;
    mean_err = mean_error(errors);
    n_sqr_mean_err = (long double)(N * N) * mean_err;

    // print output
    cout set << "N = " << N << endl;
    cout set << "Mean Error = " << mean_err << endl;
    cout set << "N^2 * Mean Error = " << n_sqr_mean_err << endl;
    cout set << "delta^2 = " << 4.0L / (long double)(N * N) << endl;
    cout << endl;
}

valarray<valarray<long double>> run_comparison(const valarray<int>& N_values) {
    int number_of_comparisons = N_values.size();
    valarray<long double> v_mean_error(number_of_comparisons);
    valarray<long double> v_n_sqr_mean_error(number_of_comparisons);
    valarray<long double> v_delta_sqr(number_of_comparisons);

    for (int i = 0; i < number_of_comparisons; i++) {
        int N = N_values[i];

        valarray<long double> X(N + 1); // x_i
        valarray<long double> F(N + 1); // f(x_i)
        valarray<long double> analytical_2nd_derivatives(N + 1); // f''(x_i)
        valarray<long double> numerical_2nd_derivatives(N + 1); // f''_i
        valarray<long double> errors(N + 1); // e_i
        long double mean_err;
        long double n_sqr_mean_err;
        long double delta_sqr;

        // Calculate the values and store them
        for (int i = 0; i <= N; i++) {
            X[i] = (long double)((2 * i) - N) / (long double)N;
        }
        F = known_function(X);
        analytical_2nd_derivatives = known_function_2nd_derivatives(X);
        numerical_2nd_derivatives = finite_differences(X);
        errors = analytical_2nd_derivatives - numerical_2nd_derivatives;
        mean_err = mean_error(errors);
        n_sqr_mean_err = (long double)(N * N) * mean_err;
        delta_sqr = 4.0L / (long double)(N * N);

        // save output
        v_mean_error[i] = mean_err;
        v_n_sqr_mean_error[i] = n_sqr_mean_err;
        v_delta_sqr[i] = delta_sqr;

        // print output
        cout set << "N = " << N << endl;
        cout set << "Mean Error = " << mean_err << endl;
        cout set << "N^2 * Mean Error = " << n_sqr_mean_err << endl;
        cout set << "delta^2 = " << delta_sqr << endl;
        cout << endl;
    }

    valarray<valarray<long double>> all_comparison_data = {v_mean_error, v_n_sqr_mean_error, v_delta_sqr};
    return all_comparison_data;
}
