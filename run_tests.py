#!/usr/bin/env python

import os
import subprocess

build_dir_name = "build"

p = subprocess.Popen(["make"], cwd=build_dir_name)
p.wait()

p = subprocess.Popen(["./dsa_test"], cwd=build_dir_name)
p.wait()
