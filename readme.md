# to compile project on mac make this:
* Export new path way

```sh
export PATH=/usr/local/bin:$PATH
```

* Open terminal window in proj folder and complile with flags

```sh
g++-5 -std=c++11 -fopenmp CFilename.c -o BinaryFilename
```

* And you can create new sublime build system. It help for you to miss second step in everynew build

```
Tools -> Build System -> Add new build system - > Paste code from /helpFiles/openmp.sublime-build
```