from setuptools import setup


def read_contents(file_to_read):
    with open(file_to_read, 'r') as f:
        return f.read()


setup(
    name='uldaq',
    version='1.2.1',
    description='Universal Library Python API for Measurement Computing DAQ devices',
    long_description=read_contents('README.rst'),
    url='http://www.mccdaq.com',
    author='Measurement Computing',
    author_email="info@mccdaq.com",
    keywords=['uldaq', 'mcc', 'ul', 'daq', 'data', 'acquisition'],
    license='MIT',
    include_package_data=True,
    packages=['uldaq'],
    install_requires=[
        'enum34;python_version<"3.4"',
    ],
    classifiers=[
        "Development Status :: 5 - Production/Stable",
        "Intended Audience :: Developers",
        "Intended Audience :: Manufacturing",
        "Intended Audience :: Science/Research",
        "License :: OSI Approved :: MIT License",
        "Operating System :: POSIX",
        "Programming Language :: Python :: 2",
        "Programming Language :: Python :: 2.7",
        "Programming Language :: Python :: 3",
        "Programming Language :: Python :: 3.4",
        "Programming Language :: Python :: 3.5",
        "Programming Language :: Python :: 3.6",
        "Topic :: System :: Hardware :: Hardware Drivers"
    ],
)
