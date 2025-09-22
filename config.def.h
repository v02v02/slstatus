/* See LICENSE file for copyright and license details. */

/* v02v02's build of slstatus.
 * 
 * Notes:
 * - You must have the packages "ttf-nerd-fonts-symbols" and "woff2-font-awesome" in order for the glyphs to render.
 *
 * Current output:
 * (From left to right)
 * - A pipe symbol that delineates slstatus from the dwm title bar.
 * - A wifi glyph that changes depending on if users have a connection to the internet or not.
 * - A megaphone glyph that changes depending on how high the volume is.
 * - A calendar glyph, to the right of the calendar glyph is the day of the month.
 * - The time of day, in 12 hour format.
 *
 *
 * Tweaks made:
 * - Created a separate directory called "scripts" within the repo. [/]
 *   (This contains all of the custom scripts I've wrote that slstatus can execute for additional output.)
 *
 * - Changed the value of "unknown_str[]" to make it empty. [config.def.h]
 *   (This is to not have "N/A" outputted to slstatus for the custom scripts that don't usually output anything.)
 *   (e.g. sls-network)
 *
 *
 * Patches applied:
 * - None currently
 *
 */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cat                 read arbitrary file             path
 * cpu_freq            cpu frequency in MHz            NULL
 * cpu_perc            cpu usage in percent            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/)
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * up                  interface is running            interface name (eth0)
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 *                                                     NULL on OpenBSD/FreeBSD
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 */
static const struct arg args[] = {
	/* function format          argument */
        { run_command, "%s",           "echo '| '"},
	{ run_command, "%s",           "sls-screencast"},
        { run_command, "%s",           "sls-network"},
        { run_command, " %s ",         "sls-sound"},
	{ datetime,    "   %s",        "%d" },
	{ datetime,    " %s",          "%l:%M %p" },
};
