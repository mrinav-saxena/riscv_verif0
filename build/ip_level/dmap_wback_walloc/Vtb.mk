# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f Vtb.mk

default: Vtb

### Constants...
# Perl executable (from $PERL, defaults to 'perl' if not set)
PERL = perl
# Python3 executable (from $PYTHON3, defaults to 'python3' if not set)
PYTHON3 = python3
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = C:/msys64/mingw64/share/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?= 
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?= 

### Switches...
# C++ code coverage  0/1 (from --prof-c)
VM_PROFC = 0
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = mingw32

### Vars...
# Design prefix (from --prefix)
VM_PREFIX = Vtb
# Module prefix (from --prefix)
VM_MODPREFIX = Vtb
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
	-IC:/msys64/mingw64/include -DWIN32 -D_WIN32 -D__MINGW64__ \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \
	-lz \
	-LC:/msys64/mingw64/lib -lz \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \
	sim_main \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \
	../../.. \
	../../../tb\ip_level\dmap_wback_walloc \


### Default rules...
# Include list of all generated classes
include Vtb_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

### Executable rules... (from --exe)
VPATH += $(VM_USER_DIR)

sim_main.o: C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/ip_level/dmap_wback_walloc/sim_main.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<

### Link rules... (from --exe)
Vtb: $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) $(VM_PREFIX)__ALL.a $(VM_HIER_LIBS)
	$(LINK) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@


# Verilated -*- Makefile -*-
