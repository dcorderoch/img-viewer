#----------------------------------------------------------------
# project ....: LTI Digital Image/Signal Processing Library
# file .......: Template Makefile for Examples
# authors ....: Pablo Alvarado, Jochen Wickel
# organization: LTI, RWTH Aachen
# creation ...: 09.02.2003
# revisions ..: $Id: Makefile.in,v 1.3 2012-01-03 03:23:09 alvarado Exp $
#----------------------------------------------------------------

#Base Directory
LTIBASE:=/usr/local
LTICMD:=$(shell echo $$HOME)/bin/lti-config

#Example name
PACKAGE:=$(shell basename $$PWD)

# If you want to generate a debug version, uncomment the next line
BUILDRELEASE=yes

# Compiler to be used
CXX:=g++

CPUARCH = -march=native

# Directories with source file code (.h and .cpp)
VPATH:=$(VPATHADDON)

# Destination directories for the debug and release versions of the code

OBJDIR  = obj

# compiler flags
CXXINCLUDE:=$(patsubst %,-I%,$(subst :, ,$(VPATH)))

LINKDIR:=-L$(LTIBASE)/lib
CPPFILES=$(wildcard ./*.cpp)
OBJFILES=$(patsubst %.cpp,$(OBJDIR)/%.o,$(notdir $(CPPFILES)))

# set the compiler/linker flags depending on the debug/release flag
ifeq "$(BUILDRELEASE)" "yes"
  LTICXXFLAGS:=$(shell $(LTICMD) --cxxflags)
  CXXFLAGSREL:=-c -O3 $(CPUARCH) -Wall -ansi $(LTICXXFLAGS) $(CXXINCLUDE)
  GCC:=$(CXX) $(CXXFLAGSREL)
  LIBS:=$(shell $(LTICMD) --libs)
else
  LTICXXFLAGS:=$(shell $(LTICMD) --cxxflags debug)
  CXXFLAGSDEB:=-c -g $(CPUARCH) -Wall -ansi $(LTICXXFLAGS) $(CXXINCLUDE)
  GCC:=$(CXX) $(CXXFLAGSDEB)
  LIBS:=$(shell $(LTICMD) --libs debug)
endif

LNALL = $(CXX)

# implicit rules 
$(OBJDIR)/%.o : %.cpp
	@mkdir -p $(OBJDIR)
	@echo "Compiling $<..."
	@$(GCC) $< -o $@

all: $(PACKAGE) 

# example
$(PACKAGE): $(OBJFILES)
	@echo "Linking $(PACKAGE)..."
	@$(LNALL) -o $(PACKAGE) $(OBJFILES) $(LIBS)

clean:
	@echo "Removing *.o files..."
	@rm -f $(OBJDIR)/*.o
	@rm -rf $(OBJDIR)
	@echo "Ready."

clean-all:
	@echo "Removing files..."
	@echo "  removing obj, core and binary files..."  
	@rm -f ./core* $(PACKAGE) $(OBJDIR)/*.o 
	@rm -rf $(OBJDIR)
	@echo "  removing emacs backup files..."  
	@find $$PWD \( -name '*\~' -or -name '\#*' \) -exec rm -f {} \;
	@echo "  removing other automatic created backup files..."  
	@find $$PWD \( -name '\.\#*' -or -name '\#*' \) -exec rm -f {} \;
	@rm -fv nohup.out
	@if [ -e ./prepare.sh ]; then ./prepare.sh --clean ; fi
	@echo "Ready."

debug:
	@echo "Package: $(PACKAGE)"
	@echo "LTICXXFLAGS: $(LTICXXFLAGS)"
	@echo "CXXFLAGSDEB: $(CXXFLAGSDEB)"
	@echo "GCC: $(GCC)"
	@echo "LIBS: $(LIBS)"
