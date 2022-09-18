from setuptools import setup, Extension

modules = [Extension('myCFun', ['myCFun.cpp'], include_dirs=['mycfun'])]
 
setup(
    ext_modules= modules,
    name='myCFun',
    version = '1.0',
    description = 'my C fast fun',
    author = 'Massa7ca',
    python_requires='>=3',
    packages=['myCFun'],
)
