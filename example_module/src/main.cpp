#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <Eigen/Core>
#include <Eigen/LU>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

int
add(int i, int j)
{
  return i + j;
}

// N.B. this would equally work with Eigen-types that are not predefined. For
// example replacing all occurrences of "Eigen::MatrixXd" with "MatD", with the
// following definition:
//
//  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic,
//  Eigen::RowMajor> MatD;

// ----------------
// regular C++ code
// ----------------

Eigen::MatrixXd
inv(const Eigen::MatrixXd& xs)
{
  return xs.inverse();
}

double
det(const Eigen::MatrixXd& xs)
{
  return xs.determinant();
}

namespace py = pybind11;

PYBIND11_MODULE(example_module, m)
{
  m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: example_module

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

  m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

  m.def(
    "subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

  m.def("inv", &inv);

  m.def("det", &det);

#ifdef VERSION_INFO
  m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
  m.attr("__version__") = "dev";
#endif
}
