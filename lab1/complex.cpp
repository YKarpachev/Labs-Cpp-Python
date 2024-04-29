#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>

int main() {
  std::complex<double> z1(1, 1), z2(3, -1), z3(-1, 1);

  std::complex<double> sum = z1 + z2;
  std::complex<double> difference = z1 - z2;
  std::complex<double> product = z1 * z2;
  std::complex<double> division = z1 / z2;
  std::complex<double> fourth_power = std::pow(z3, 4);
  std::complex<double> cubic_root = std::pow(z3, 1.0 / 3.0);

  if (std::abs(fourth_power.imag()) < 1e-10) {
    fourth_power = std::complex<double>(fourth_power.real(), 0);
  }

  std::cout << "Сумма z1 и z2: " << sum << std::endl;
  std::cout << "Разность z1 и z2: " << difference << std::endl;
  std::cout << "Произведение z1 и z2: " << product << std::endl;
  std::cout << "Частное z1 и z2: " << division << std::endl;
  std::cout << "Четвертая степень z3: " << fourth_power << std::endl;
  std::cout << std::fixed << std::setprecision(7);
  std::cout << "Корень третьей степени z3: " << cubic_root << std::endl;
  return 0;
}
