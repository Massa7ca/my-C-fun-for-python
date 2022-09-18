#include <Python.h>
#include <random>

using namespace std;

void PyInit_myCFun(void) { }

class My_random
{
public:
	My_random(const long long min, const long long max) {
		rd = new random_device;
		eng = new mt19937_64((*rd)());
		distr = new uniform_int_distribution<long long>(min, max);
	}

	long long get_value() {
		return (*distr)(*eng);
	}

	~My_random() {
		delete eng;
		delete distr;
		delete rd;
		eng = nullptr;
		distr = nullptr;
		rd = nullptr;
	}

private:
	random_device *rd;
	mt19937_64* eng;
	uniform_int_distribution<long long>* distr;
};

void BA(vector<bool>& BaytArr, unsigned long long int l, unsigned long long int p) {
    for (unsigned long long int i = l; i < BaytArr.size(); i += p) {
        BaytArr[i] = false;
    }
}

PyObject* PrimeFasters(unsigned long long int lim) {
    PyObject *res;
    res = PyList_New(0);
    if (lim < 7) {
        if (lim < 2) {
            return res;
        } else if (lim < 3) {
            PyList_Append(res, Py_BuildValue("L", 2));
            return res;
        } else if (lim < 5) {
            PyList_Append(res, Py_BuildValue("L", 2));
            PyList_Append(res, Py_BuildValue("L", 3));
            return res;
        }
        PyList_Append(res, Py_BuildValue("L", 2));
        PyList_Append(res, Py_BuildValue("L", 3));
        PyList_Append(res, Py_BuildValue("L", 5));
        return res;
    }
    unsigned long long int n = (lim - 1) / 30;
    unsigned long long int m = n + 1;
    vector<bool> prime1(m, 1);
    vector<bool> prime7(m, 1);
    vector<bool> prime11(m, 1);
    vector<bool> prime13(m, 1);
    vector<bool> prime17(m, 1);
    vector<bool> prime19(m, 1);
    vector<bool> prime23(m, 1);
    vector<bool> prime29(m, 1);
    prime1[0] = false;

    unsigned long long int p;
    unsigned long long int l;
    for (unsigned long long int i = 0; i != m; i++) {
        if (prime1[i]) {
            p = 30 * i + 1;
            l = i * (p + 1);
            BA(prime1, l, p);
            l += i * 6;
            BA(prime7, l, p);
            l += i * 4;
            BA(prime11, l, p);
            l += i * 2;
            BA(prime13, l, p);
            l += i * 4;
            BA(prime17, l, p);
            l += i * 2;
            BA(prime19, l, p);
            l += i * 4;
            BA(prime23, l, p);
            l += i * 6;
            BA(prime29, l, p);
        }

        if (prime7[i]) {
            p = 30 * i + 7;
            l = i * (p + 7) + 1;
            BA(prime19, l, p);
            l += i * 4 + 1;
            BA(prime17, l, p);
            l += i * 2 + 1;
            BA(prime1, l, p);
            l += i * 4;
            BA(prime29, l, p);
            l += i * 2 + 1;
            BA(prime13, l, p);
            l += i * 4 + 1;
            BA(prime11, l, p);
            l += i * 6 + 1;
            BA(prime23, l, p);
            l += i * 2 + 1;
            BA(prime7, l, p);
        }

        if (prime11[i]) {
            p = 30 * i + 11;
            l = i * (p + 11) + 4;
            BA(prime1, l, p);
            l += i * 2;
            BA(prime23, l, p);
            l += i * 4 + 2;
            BA(prime7, l, p);
            l += i * 2;
            BA(prime29, l, p);
            l += i * 4 + 2;
            BA(prime13, l, p);
            l += i * 6 + 2;
            BA(prime19, l, p);
            l += i * 2 + 1;
            BA(prime11, l, p);
            l += i * 6 + 2;
            BA(prime17, l, p);
        }

        if (prime13[i]) {
            p = 30 * i + 13;
            l = i * (p + 13) + 5;
            BA(prime19, l, p);
            l += i * 4 + 2;
            BA(prime11, l, p);
            l += i * 2 + 1;
            BA(prime7, l, p);
            l += i * 4 + 1;
            BA(prime29, l, p);
            l += i * 6 + 3;
            BA(prime17, l, p);
            l += i * 2 + 1;
            BA(prime13, l, p);
            l += i * 6 + 3;
            BA(prime1, l, p);
            l += i * 4 + 1;
            BA(prime23, l, p);
        }

        if (prime17[i]) {
            p = 30 * i + 17;
            l = i * (p + 17) + 9;
            BA(prime19, l, p);
            l += i * 2 + 1;
            BA(prime23, l, p);
            l += i * 4 + 3;
            BA(prime1, l, p);
            l += i * 6 + 3;
            BA(prime13, l, p);
            l += i * 2 + 1;
            BA(prime17, l, p);
            l += i * 6 + 3;
            BA(prime29, l, p);
            l += i * 4 + 3;
            BA(prime7, l, p);
            l += i * 2 + 1;
            BA(prime11, l, p);
        }

        if (prime19[i]) {
            p = 30 * i + 19;
            l = i * (p + 19) + 12;
            BA(prime1, l, p);
            l += i * 4 + 2;
            BA(prime17, l, p);
            l += i * 6 + 4;
            BA(prime11, l, p);
            l += i * 2 + 1;
            BA(prime19, l, p);
            l += i * 6 + 4;
            BA(prime13, l, p);
            l += i * 4 + 2;
            BA(prime29, l, p);
            l += i * 2 + 2;
            BA(prime7, l, p);
            l += i * 4 + 2;
            BA(prime23, l, p);
        }

        if (prime23[i]) {
            p = 30 * i + 23;
            l = i * (p + 23) + 17;
            BA(prime19, l, p);
            l += i * 6 + 5;
            BA(prime7, l, p);
            l += i * 2 + 1;
            BA(prime23, l, p);
            l += i * 6 + 5;
            BA(prime11, l, p);
            l += i * 4 + 3;
            BA(prime13, l, p);
            l += i * 2 + 1;
            BA(prime29, l, p);
            l += i * 4 + 4;
            BA(prime1, l, p);
            l += i * 2 + 1;
            BA(prime17, l, p);
        }

        if (prime29[i]) {
            p = 30 * i + 29;
            l = i * (p + 29) + 28;
            BA(prime1, l, p);
            l += i * 2 + 1;
            BA(prime29, l, p);
            l += i * 6 + 6;
            BA(prime23, l, p);
            l += i * 4 + 4;
            BA(prime19, l, p);
            l += i * 2 + 2;
            BA(prime17, l, p);
            l += i * 4 + 4;
            BA(prime13, l, p);
            l += i * 2 + 2;
            BA(prime11, l, p);
            l += i * 4 + 4;
            BA(prime7, l, p);
        }
    }

    unsigned long long int ti = 0;
    PyList_Append(res, Py_BuildValue("L", 2));
    PyList_Append(res, Py_BuildValue("L", 3));
    PyList_Append(res, Py_BuildValue("L", 5));

    for (unsigned long long int i = 0; i != n; i++) {
        if (prime1[i]) {
            PyList_Append(res, Py_BuildValue("L", ti + 1));
        }
        if (prime7[i]) {
            PyList_Append(res, Py_BuildValue("L", ti + 7));
        }
        if (prime11[i]) {
            PyList_Append(res, Py_BuildValue("L", ti + 11));
        }
        if (prime13[i]) {
            PyList_Append(res, Py_BuildValue("L", ti + 13));
        }
        if (prime17[i]) {
            PyList_Append(res, Py_BuildValue("L", ti + 17));
        }
        if (prime19[i]) {
            PyList_Append(res, Py_BuildValue("L", ti + 19));
        }
        if (prime23[i]) {
            PyList_Append(res, Py_BuildValue("L", ti + 23));
        }
        if (prime29[i]) {
            PyList_Append(res, Py_BuildValue("L", ti + 29));
        }
        ti += 30;
    }
    
    if (prime1[n] && (30 * n + 1) <= lim) {
        PyList_Append(res, Py_BuildValue("L", 30 * n + 1));
    }
    if (prime7[n] && (30 * n + 7) <= lim) {
        PyList_Append(res, Py_BuildValue("L", 30 * n + 7));
    }
    if (prime11[n] && (30 * n + 11) <= lim) {
        PyList_Append(res, Py_BuildValue("L", 30 * n + 11));
    }
    if (prime13[n] && (30 * n + 13) <= lim) {
        PyList_Append(res, Py_BuildValue("L", 30 * n + 13));
    }
    if (prime17[n] && (30 * n + 17) <= lim) {
        PyList_Append(res, Py_BuildValue("L", 30 * n + 17));
    }
    if (prime19[n] && (30 * n + 19) <= lim) {
        PyList_Append(res, Py_BuildValue("L", 30 * n + 19));
    }
    if (prime23[n] && (30 * n + 23) <= lim) {
        PyList_Append(res, Py_BuildValue("L", 30 * n + 23));
    }
    if (prime29[n] && (30 * n + 29) <= lim) {
        PyList_Append(res, Py_BuildValue("L", 30 * n + 29));
    }
    return res;
}

PyObject* min_max_list(PyObject* list, unsigned short cmp) {
	PyObject* max, * val;
	bool result;
	int t = PyList_Size(list);
	max = PyList_GET_ITEM(list, 0);
	for (unsigned long long i = 1; i != t; i++) {
		val = PyList_GET_ITEM(list, i);
		result = PyObject_RichCompareBool(max, val, cmp);
		if (result) {
			max = val;
		}
	}
	return max;
}

extern "C" {
	_declspec(dllexport)
	PyObject* max_list(PyObject* list) {
		return min_max_list(list, 0);
	}

    _declspec(dllexport)
    PyObject* min_list(PyObject* list) {
        return min_max_list(list, 4);
    }

	_declspec(dllexport)
    PyObject* get_prime(unsigned long long n) {
		return PrimeFasters(n);
	}
	
	_declspec(dllexport)
	PyObject* get_random_list(const unsigned int size, const long long min, const long long max) {
		My_random ran(min, max);
		PyObject* py_val, *py_list;
		py_list = PyList_New(size);
		for (unsigned long long i = 0; i != size; i++) {
			py_val = Py_BuildValue("L", ran.get_value());
			PyList_SetItem(py_list, i, py_val);
		}
		return py_list;

	}
}