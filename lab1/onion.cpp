#include <cstring> // For memcpy
#include <iostream>

using namespace std;

class vectorx {
private:
  int dim;
  int *v;
  int number;

public:
  static int count;
  vectorx();
  vectorx(int dim);
  vectorx(int d, int *arr);
  vectorx(const vectorx &vect);
  ~vectorx();
  vectorx operator-(int con) const;
  vectorx &operator=(const vectorx &vect);
  vectorx operator+(const vectorx &vect) const;
  friend vectorx operator*(int con, const vectorx &vect);
  vectorx operator*(int con) const;
  int operator*(const vectorx &vect) const;
  void print();
  int operator[](int i) const;
  friend vectorx operator-(const vectorx &v1, const vectorx &v2);
};

int vectorx::count = 0;

vectorx::vectorx() : dim(0), v(new int[0]), number(count++) {
  cout << "Constructor vector() made vector #" << number << endl;
}

vectorx::vectorx(int d) : dim(d), v(new int[d]), number(count++) {
  cout << "Constructor vector(int d) made vector #" << number << endl;
  memset(v, 0, dim * sizeof(int));
}

vectorx::vectorx(int d, int *arr) : dim(d), v(new int[d]), number(count++) {
  memcpy(v, arr, d * sizeof(int));
}

vectorx::vectorx(const vectorx &vect)
    : dim(vect.dim), v(new int[vect.dim]), number(count++) {
  memcpy(v, vect.v, dim * sizeof(int));
}

vectorx::~vectorx() {
  cout << "Destruction of vector #" << number << endl;
  delete[] v;
}

vectorx vectorx::operator-(int con) const {
  vectorx tmp(dim);
  for (int i = 0; i < dim; i++) {
    tmp.v[i] = v[i] - con;
  }
  return tmp;
}

vectorx &vectorx::operator=(const vectorx &vect) {
  if (this == &vect)
    return *this; // Handle self-assignment
  delete[] v;     // Free existing resource
  dim = vect.dim;
  v = new int[dim];
  memcpy(v, vect.v, dim * sizeof(int));
  return *this;
}

vectorx vectorx::operator+(const vectorx &vect) const {
  vectorx tmp(dim);
  for (int i = 0; i < dim; i++) {
    tmp.v[i] = v[i] + vect.v[i];
  }
  return tmp;
}

vectorx operator*(int con, const vectorx &vect) {
  vectorx tmp(vect.dim);
  for (int i = 0; i < vect.dim; i++) {
    tmp.v[i] = con * vect.v[i];
  }
  return tmp;
}

vectorx vectorx::operator*(int con) const {
  vectorx tmp(this->dim);
  for (int i = 0; i < this->dim; i++) {
    tmp.v[i] = this->v[i] * con;
  }
  return tmp;
}

vectorx operator-(const vectorx &v1, const vectorx &v2) {
  // Ensure both vectors have the same dimension
  if (v1.dim != v2.dim) {
    // Handle the error or return an empty vector
    std::cerr << "Error: Vectors have different dimensions." << std::endl;
    return vectorx();
  }

  vectorx result(v1.dim);
  for (int i = 0; i < v1.dim; i++) {
    result.v[i] = v1.v[i] - v2.v[i];
  }
  return result;
}

int vectorx::operator*(const vectorx &vect) const {
  int sum = 0;
  for (int i = 0; i < dim; i++) {
    sum += v[i] * vect.v[i];
  }
  return sum;
}

void vectorx::print() {
  cout << "Printing vector #" << number << endl;
  cout << "<";
  for (int i = 0; i < dim; i++) {
    if (i < dim - 1)
      cout << v[i] << ", ";
    else
      cout << v[i];
  }
  cout << ">" << endl;
}

int vectorx::operator[](int i) const {
  if (i >= 0 && i < dim) {
    return v[i];
  }
  cout << "Index out of bounds." << endl;
  return -1;
}

int main() {

  int d = 5;
  int arr[5] = {32, 32, 12, 42, 42};
  vectorx vect1(d, arr);
  vectorx vect2(d, arr);
  vectorx vect_res1;
  int vect_res2;
  vectorx vect_res3;
  vectorx vect_res4;
  vectorx vect_res5;

  vect_res1 = vect1 + vect2;
  vect_res2 = vect1 * vect2;
  vect_res3 = vect1 * 4;
  vect_res4 = vect1 - vect2;
  vect_res5 = vect1 - 7;

  vect_res1.print();
  cout << vect_res2 << endl;
  vect_res3.print();
  vect_res4.print();
  vect_res5.print();

  return 0;
}
