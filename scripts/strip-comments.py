#!/bin/env python3

import sys
import re

filename = sys.argv[1]

content = ''
with open(filename, 'rt') as f:
    for line in f.readlines():
        if not re.match(r'^\s*//.*$', line): content += line

with open(filename, 'wt') as f:
    f.write(content)
