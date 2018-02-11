# Homework Assignment No. 1

First Homework Assignment of the CE-5201 Procesamiento y Análisis de Imágenes Digitales Course, on the First Semester of 2018.

## Getting Started

Clone this repository with git

```
$ git clone <URL>
```

### Prerequisites

This assignment was done on Ubuntu 16.04, using the default software repositories to install the g++ compiler, Cmake, and OpenCV.

Additionaly the [LTI-Lib-2](https://sourceforge.net/p/ltilib/wiki/Home/) library was intstalled.

After installing the LTI-Lib-2 library, a directory called bin was created on the user's home directory, and added to the PATH environmental variable, and the `lti-config` file was copied to the new `bin` directory.

```
mkdir -p ~/bin
echo "PATH=\"$PATH:~/bin\"" >> ~/.bashrc
cp linux/lti-config ~/bin
```
and the Makefile template found on the `examples/template` directory was used as a base to write the Makefile used in this repository.

```
mkdir -p ~/src/hw_1 && cp examples/template/Makefile ~/src/hw_1
```

though, some changes were made, to eliminate unused or platform specific variables, and maintain the root directory of this repository clean, even after compilation, as well as to make use of the system-wide installed library, as opposed to using a local copy.

the changes made are shown here, by running the `diff` command, these are the results


```
diff examples/template/Makefile ~/src/academics/dip/hw1/ltilib/Makefile
11,12c11,12
< LTIBASE:=../..
< LTICMD:=$(LTIBASE)/linux/lti-local-config
---
> LTIBASE:=/usr/local
> LTICMD:=$(shell echo $$HOME)/bin/lti-config
23,44c23
< # Run the prepare script, which links some source files
< FOOCHECK := $(shell if [ -e ./prepare.sh ]; then ./prepare.sh; fi)
< 
< # For new versions of gcc, <limits> already exists, but in older
< # versions a replacement is needed
< CXX_MAJOR:=$(shell echo `$(CXX) --version | sed -e 's/\..*//;'`)
< 
< ifeq "$(CXX_MAJOR)" "2"
<   VPATHADDON=:g++
<   CPUARCH = -march=i686 -ftemplate-depth-35
<   CPUARCHD = -march=i686 -ftemplate-depth-35
< else
<   ifeq "$(CXX_MAJOR)" "3"
<   VPATHADDON=
<   CPUARCH = -march=i686
<   CPUARCHD = -march=i686
<   else
<   VPATHADDON=
<   CPUARCH = -march=native
<   CPUARCHD = 
<   endif
< endif
---
> CPUARCH = -march=native
51,65c30
< OBJDIR  = ./
< 
< # Extra include directories and library directories for hardware specific stuff
< 
< EXTRAINCLUDEPATH =
< EXTRALIBPATH =
< EXTRALIBS    =
< 
< #EXTRAINCLUDEPATH = -I/usr/src/menable/include
< #EXTRALIBPATH = -L/usr/src/menable/lib
< #EXTRALIBS =  -lpulnixchanneltmc6700 -lmenable
< 
< 
< # PROFILE = -p
< PROFILE=
---
> OBJDIR  = obj
68c33
< CXXINCLUDE:=$(EXTRAINCLUDEPATH) $(patsubst %,-I%,$(subst :, ,$(VPATH)))
---
> CXXINCLUDE:=$(patsubst %,-I%,$(subst :, ,$(VPATH)))
72c37
< OBJFILES=$(patsubst %.cpp,$(OBJDIR)%.o,$(notdir $(CPPFILES)))
---
> OBJFILES=$(patsubst %.cpp,$(OBJDIR)/%.o,$(notdir $(CPPFILES)))
78,79c43,44
<   GCC:=$(CXX) $(CXXFLAGSREL) $(PROFILE)
<   LIBS:=$(shell $(LTICMD) --libs) $(EXTRALIBPATH) $(EXTRALIBS)
---
>   GCC:=$(CXX) $(CXXFLAGSREL)
>   LIBS:=$(shell $(LTICMD) --libs)
83,84c48,49
<   GCC:=$(CXX) $(CXXFLAGSDEB) $(PROFILE)
<   LIBS:=$(shell $(LTICMD) --libs debug) $(EXTRALIBPATH) $(EXTRALIBS)
---
>   GCC:=$(CXX) $(CXXFLAGSDEB)
>   LIBS:=$(shell $(LTICMD) --libs debug)
87c52
< LNALL = $(CXX) $(PROFILE) 
---
> LNALL = $(CXX)
90c55,56
< $(OBJDIR)%.o : %.cpp
---
> $(OBJDIR)/%.o : %.cpp
> 	@mkdir -p $(OBJDIR)
103c69,70
< 	@rm -f *.o
---
> 	@rm -f $(OBJDIR)/*.o
> 	@rm -rf $(OBJDIR)
109c76,77
< 	@rm -f ./core* $(PACKAGE) $(OBJDIR)*.o 
---
> 	@rm -f ./core* $(PACKAGE) $(OBJDIR)/*.o 
> 	@rm -rf $(OBJDIR)
124d91
< 
```

### Style Guide

`C++ Coding Standards: 101 Rules, Guidelines, and Best Practices`  by Herb Stutter, and Andrei Alexandrescu, was used as the coding style guide.

## Author

* **David Cordero Chavarría** - *Initial Work* - [dcorderoch](https://github.com/dcorderoch)

## Acknowledgements

* Pablo Alvarado, Jochen Wickel, original authors of the LTI-Lib-2 library, and examples.
