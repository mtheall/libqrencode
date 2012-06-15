#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------

ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>devkitPro")
endif

ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

ifeq ($(strip $(FEOSSDK)),)
$(error "Please set FEOSSDK in your environment. export FEOSSDK=<path to>FeOS/sdk")
endif

FEOSMK = $(FEOSSDK)/mk

#---------------------------------------------------------------------------------
# TARGET is the name of the output
# BUILD is the directory where object files & intermediate files will be placed
# SOURCES is a list of directories containing source code
# DATA is a list of directories containing data files
# INCLUDES is a list of directories containing header files
#---------------------------------------------------------------------------------
TARGET        := qrencode
BUILD         := build
SOURCES       := source
DATA          := data
INCLUDES      := include source

CONF_CXXFLAGS := -Wall
CONF_DEFINES  := -DQR_API=FEOS_EXPORT \
                 -D__STATIC=static \
                 -DMAJOR_VERSION=3 \
                 -DMINOR_VERSION=3 \
                 -DMICRO_VERSION=1 \
                 -D"VERSION=\"3.3.1\""

include $(FEOSMK)/dynlib.mk

install: all
	@cp $(TARGET).fx2 $(FEOSDEST)/data/FeOS/lib/$(TARGET).fx2 || exit 1

