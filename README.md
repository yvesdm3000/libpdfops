# libpdfops
Library with very high-level operations to perform actions on PDF files.
Altough it is based on Poppler, not all operations using the poppler tools
are easy accessible as a library. This library provides access to these
high level operations directly without running commandline tools.

Most of the code is simply taken out of the sourcecode of the tools of Poppler.
Copyright remains on the authors of these tools. I claim no ownership of that
code.

# Library Supported operations

## UniteFiles

Unites one or more files into a single file.

## ExtractPages

Extracts one or more pages out of a PDF file into a new PDF File.

# Command Line tools

## unitepdf input1.pdf [...] inputX.pdf output.pdf

Unites all input files into a single output file

## extractpages [-f first] [-l last] input.pdf output%d.pdf

Extracts one or more pages from input.pdf into files with pattern output%d.pdf

