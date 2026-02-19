from setuptools import find_packages
from setuptools import setup

setup(
    name='turtlesim_lc_interfaces',
    version='0.0.1',
    packages=find_packages(
        include=('turtlesim_lc_interfaces', 'turtlesim_lc_interfaces.*')),
)
