/*

Copyright 2011 Carl D Hamann

This file is part of colorize.

colorize is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

colorize is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with colorize.  If not, see <http://www.gnu.org/licenses/>.

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char** argv)
{
	int opt, color;
	int fg = 0;
	int bg = 0;
	int weight = 0;
	int i = 2;
	char fmt[] = "\x1b[0m\x00\x00\x00\x00\x00\x00\x00";
	char opts[] = "krgybmcwt";
	char buf[1024];

	while((opt = getopt(argc, argv, opts)) != -1)
	{
		color = 8;
		while(opts[color] != opt && color-- >= 0);

		if(color >= 0)
		{
			if(color == 8)
			{
				weight = 1;
			}
			else if(fg == 0)
			{
				fg = 0x30 + color;
			}
			else
			{
				bg = 0x30 + color;
			}
		}
	}

	if(weight > 0)
	{
		fmt[i++] = '1';
		fmt[i] = 'm';
	}
	else
	{
		fmt[i++] = '2';
		fmt[i++] = '2';
		fmt[i] = 'm';
	}

	if(fg > 0)
	{
		fmt[i++] = ';';
		fmt[i++] = '3';
		fmt[i++] = fg;
		fmt[i] = 'm';

		if(bg > 0)
		{
			fmt[i++] = ';';
			fmt[i++] = '4';
			fmt[i++] = bg;
			fmt[i] = 'm';
		}
	}

	fputs(fmt, stdout);
	while(fgets(buf, 1024, stdin) != NULL)
	{
		fputs(buf, stdout);
	}
	fputs("\x1b[0m", stdout);

	exit(0);
}
