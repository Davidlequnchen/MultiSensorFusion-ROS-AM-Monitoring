===========  =======================================================================
Info         Contains files used to generate documentation for the uldaq Python API.
Author       Measurement Computing
===========  =======================================================================

Documentation
=============
Documentation is available at https://www.mccdaq.com/PDFs/Manuals/UL-Linux/python/

Generating Documentation
========================
Follow these steps to generate the documentation for the uldaq Python API.

1. Install sphinx and sphinx_rtd_theme.

    $ pip install sphinx sphinx_rtd_theme

2. Run sphinx in the uldaq docs directory to generate the documentation.

    $ make html

The resulting documentation can be found in the docs/_build/html directory.
