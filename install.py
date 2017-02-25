#!/usr/bin/env python

import os
import subprocess

# Create build folder
build_dir_name = "build"
if not os.path.exists(build_dir_name):
    os.makedirs(build_dir_name)

# Run CMake in build folder
p = subprocess.Popen(["cmake", ".."], cwd=build_dir_name)
p.wait()
