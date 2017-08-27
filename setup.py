from distutils.core import setup, Extension

native_module = Extension('native',
                          sources=['native.c'])

setup(name='native',
      version='1.0',
      description='This is a native package',
      ext_modules=[native_module])
