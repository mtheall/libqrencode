libqrencode 3.3.1 - QR Code encoding library

GENERAL INFORMATION
===================
Libqrencode is a library for encoding data in a QR Code symbol, a kind of 2D
symbology that can be scanned by handy terminals such as a mobile phone with
CCD. The capacity of QR Code is up to 7000 digits or 4000 characters, and has
high robustness.

Libqrencode accepts a string or a list of data chunks then encodes in a QR Code
symbol as a bitmap array. While other QR Code applications generate an image
file, using libqrencode allows applications to render QR Code symbols from raw
bitmap data directly. This library also contains a command-line utility outputs
a QR Code symbol as a PNG image. It will help light-weight CGI programs.


SPECIFICATION
=============
Libqrencode supports QR Code model 2, described in JIS (Japanese Industrial
Standards) X0510:2004 or ISO/IEC 18004. Most of features in the specification
are implemented such as:
- Numeric, alphabet, Japanese kanji (Shift-JIS) or any 8 bit code can be
  embedded
- Optimized encoding of a string
- Structured-append of symbols
- Micro QR Code (experimental)

Currently the following features are not supported:
- ECI and FNC1 mode
- QR Code model 1 (deprecated)


INSTALL
=======

Requirements
------------

You need the following in order to build qrencode:

- [FeOS and FeOS SDK](https://github.com/fincs/FeOS "FeOS")

Compile & install
-----------------

    cd $FEOSSDK/userlib
    git clone git://github.com/mtheall/libqrencode.git
    cd /path/to/FeOS
    make libinstall

This compiles and installs the library and header file to the appropriate
directories. By default, $FEOSDEST/data/FeOS/lib.

You can also use "qrencode" shared lib as a standalone program. It will
create a QR code with each supplied argument concatenated with an embedded
newline '\n' character between each argument.


USAGE
=====
Basic usages of this library are written in the header file (qrencode.h).
You can generate a manual of the library by using Doxygen.

In your C/C++ source:

    #include <qrencode.h>

In your Makefile:

    CONF_USERLIBS := qrencode
    CONF_LIBS     := -lqrencode

WARNINGS
========
The library is distributed WITHOUT ANY WRRANTY.

Micro QR Code support is EXPERIMENTAL.

LICENSING INFORMATION
=====================
Copyright (C) 2006-2012 Kentaro Fukuchi

This library is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free
Software Foundation; either version 2.1 of the License, or any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this library; if not, write to the Free Software Foundation, Inc., 51
Franklin St, Fifth Floor, Boston, MA 02110-1301 USA


CONTACT
=======
Visit the homepage at:

http://fukuchi.org/works/qrencode/

for new releases. The git repository is available at:

https://github.com/fukuchi/libqrencode

Please mail any bug reports, suggestions, comments and questions to:

Kentaro Fukuchi <kentaro@fukuchi.org>

or submit issues to:

https://github.com/fukuchi/libqrencode/issues

Questions of license compliance are also welcome.

For FeOS-specific issues:

https://github.com/mtheall/libqrencode/issues


ACKNOWLEDGMENTS
===============
QR Code is registered trademarks of DENSO WAVE INCORPORATED in JAPAN and other
countries.

Reed-Solomon encoder is written by Phil Karn, KA9Q.
Copyright (C) 2002, 2003, 2004, 2006 Phil Karn, KA9Q

NANKI Haruo           - improved lower-case characteres encoding
Philippe Delcroix     - improved mask evaluation
Yusuke Mihara         - structured-append support
David Dahl            - DPI patch
Adam Shepherd         - bug fix patch of the mask evaluation
Josef Eisl (zapster)  - EPS support patch
Colin (moshen)        - ANSI support patch
Ralf Ertzinger        - ASCII support patch
Yutaka Niibe (gniibe) - various bug fix patches
Dan Strom (Repox)     - SVG support patch
Shigeyuki Hirai, Paul Janssens, wangsai, Gavan Fantom, Matthew Baker, Rob Ryan,
Fred Steinhaeuser
 - bug report / suggestion
