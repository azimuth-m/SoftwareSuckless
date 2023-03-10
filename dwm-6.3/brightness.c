#include <stdio.h>
#include "brightness.h"

FILE *fp = NULL;
extern const unsigned int max_brightness;
extern unsigned int cur_brightness;
extern const char *max_b_path;
extern const char *b_path;

static void
load_brightness( unsigned int brightness_var, const char *path_to_file)
{
        fp = fopen(path_to_file, "rt");
        if (fp == NULL)
                return;
        fscanf(fp, "%u", &brightness_var);
        fclose(fp);
}

static void
store_brightness( unsigned int brightness_var, const char *path_to_file)
{
        fp = fopen(path_to_file, "wt");
        if (fp == NULL)
                return;
        fprintf(fp, "%u\n", brightness_var);
        fclose(fp);
}

void
dec_brightness()
{
	load_brightness(cur_brightness, b_path);
	cur_brightness -= 250;
	if (cur_brightness >= max_brightness) {
		cur_brightness += 250;
		return;
	} else if (cur_brightness < 250) {
		cur_brightness = 0;
	}
	store_brightness(cur_brightness, b_path);
}

void
inc_brightness()
{
	load_brightness(cur_brightness, b_path);
	cur_brightness += 250;
	if (cur_brightness > max_brightness) {
		cur_brightness -= 250;
		return;
	} else if (cur_brightness == 4750) {
		cur_brightness = max_brightness;
	}
	store_brightness(cur_brightness, b_path);
}
