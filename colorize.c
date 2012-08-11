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
