##NAME

colorize - color filter for text

##SYNOPSIS

colorize [OPTION]

##DESCRIPTION

Prepend standard input with the appropriate terminal codes to change
the color or font weight of standard output.

##OPTIONS

-[krgybmcw]
:	Set color according to the following table. The first color
	specified sets the foreground color. If specified more than
	once, the last color specified sets the background color.

		k	black
		r	red
		g	green
		y	yellow
		b	blue
		m	magenta
		c	cyan
		w	white

-t
:	Use bright or bold text.

##AUTHOR

Written by Carl D Hamann (laindir).

##BUGS

If the program does not exit normally, the terminal is not reset.

##COPYRIGHT

Copyright 2012 Carl D Hamann
Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.  This file is offered as-is,
without any warranty.
