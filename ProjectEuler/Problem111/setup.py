from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

#ext_modules = [Extension('mostDigit', ['mostDigit.pyx'])]   #assign new.pyx module in setup.py.
ext_modules = [Extension('solve', ['solve.pyx'])]   #assign new.pyx module in setup.py.
setup(
      name        = 'solve app',
      cmdclass    = {'build_ext':build_ext},
      ext_modules = ext_modules
      )
