import ctypes
import time
import random
import os

file_path = os.path.dirname(__file__)

for suffix in ['so', 'dll', 'pyd']:
    dllfn = file_path + "\\lib\\myCFun.cp310-win_amd64." + suffix
    if not os.path.isfile(dllfn):
        continue
    lib = ctypes.PyDLL(dllfn)
    break

lib.max_list.restype = ctypes.py_object
lib.max_list.argtypes = [ctypes.py_object]

lib.min_list.restype = ctypes.py_object
lib.min_list.argtypes = [ctypes.py_object]

lib.get_prime.restype = ctypes.py_object
lib.get_prime.argtypes = [ctypes.c_longlong]

lib.get_random_list.restype = ctypes.py_object
lib.get_random_list.argtypes = [ctypes.c_uint, ctypes.c_longlong, ctypes.c_longlong]


def max_list(list):
    return lib.max_list(list)

def min_list(list):
    return lib.min_list(list)

def random_int_list(size, min_int = 0, max_int = 2**16):
    return lib.get_random_list(size, min_int, max_int)

def prines_number(n):
    return lib.get_prime(n)

if __name__ == '__main__':
    import unittest
    import sympy
    
    class Test(unittest.TestCase):
        def test_random_int_list(self):
            min_int, max_int, size = -10, 10, 10000
            list = random_int_list(size, min_int, max_int)
            self.assertEqual(len(list), size)
            self.assertTrue(max(list) == max_int)
            self.assertTrue(min(list) == min_int)
            
        def test_max_list(self):
            list = random_int_list(100000, -2**62, 2**62)
            self.assertEqual(max(list), max_list(list))

        def test_min_list(self):
            list = random_int_list(100000, -2**62, 2**62)
            self.assertEqual(min(list), min_list(list))

        def test_get_random_int_list(self):
            primes = prines_number(1000)
            for prime in primes:
                self.assertTrue(sympy.isprime(prime))
                
    unittest.main()

