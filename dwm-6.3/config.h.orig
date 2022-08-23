/* See LICENSE file for copyright and license details. */
#define XF86XK_MonBrightnessUp    0x1008FF02  /* Monitor/panel brightness */
#define XF86XK_MonBrightnessDown  0x1008FF03  /* Monitor/panel brightness */
#define XF86XK_AudioLowerVolume	  0x1008FF11   /* Volume control down        */
#define XF86XK_AudioMute          0x1008FF12   /* Mute sound from the system */
#define XF86XK_AudioRaiseVolume   0x1008FF13   /* Volume control up          */
#define XF86XK_AudioPlay          0x1008FF14   /* Start playing of audio >   */
#define XF86XK_AudioPrev          0x1008FF16   /* Previous track             */
#define XF86XK_AudioNext          0x1008FF17   /* Next track                 */
#define XF86XK_TouchpadToggle     0x1008FFA9   /* Toggle between touchpad/trackstick */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 322;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "SourceCodePro:size=12:style=Medium", "NotoColorEmoji:size=12"};
static const char dmenufont[]       = { "SourceCodePro:size=12:style=Medium"};
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_orange[]        = "#ff2f00";
//static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_orange,  col_orange  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class          instance    title       tags mask     isfloating   monitor */
	{ "Pavucontrol",  NULL,       NULL,       0,            1,           -1 },
	{ "Galculator",   NULL,       NULL,       0,            1,           -1 },
	{ "qBittorrent",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "librewolf",    NULL,       NULL,       1 << 1,       0,           -1 },
	{ "discord",      NULL,       NULL,       1 << 2,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* custom */

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_orange, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };
/* keys */
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_r,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_p,	   zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,						XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_f,      fullscreen,     {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

// take a screenshot with the mod + print button and save it in ~/Pictures/screenshots
	{ MODKEY,			XK_Print,	spawn,		   SHCMD("scrot 'screenshot_%Y%m%d_%H%M%S.png' -e 'mkdir -p ~/Pictures/screenshots && mv $f ~/Pictures/screenshots && xclip -selection clipboard -t image/png -i ~/Pictures/screenshots/`ls -1 -t ~/Pictures/screenshots | head -1`' ") },
// take a screenshot with the print button
	{ 0,				XK_Print,	spawn,		   SHCMD("scrot -o /tmp/image.png && xclip -selection clipboard -t image/png -i /tmp/image.png &") },
// take a selection screenshot with the mod + shift + s button
	{ MODKEY|ShiftMask,	XK_s,       spawn,         SHCMD("scrot -s -f -o /tmp/image.png && xclip -selection clipboard -t image/png -i /tmp/image.png &") },
// spawn librewolf  on MOD + W
    { MODKEY,           XK_w,						spawn,         SHCMD("librewolf &") },
// spawn  emoji selection in dmenu
    { MODKEY|ShiftMask, XK_d,						spawn,         SHCMD("emoji &") },
// spawn ranger
	{ MODKEY,           XK_n,						spawn,         SHCMD("st -e ranger &") },
// spawn pcmanfm
	{ MODKEY|ShiftMask,	XK_n,						spawn,         SHCMD("pcmanfm &") },
//spawn pulseaudio volume control
	{ MODKEY|ShiftMask, XK_m,						spawn,         SHCMD("pavucontrol &") },
//spawn galculator
	{ MODKEY|ShiftMask, XK_g,						spawn,         SHCMD("galculator &") },
//Volume Function Keys (controls)
	{ 0,				XF86XK_AudioMute,			spawn,         SHCMD("pamixer -t &") },
	{ 0,				XF86XK_AudioLowerVolume,    spawn,         SHCMD("pamixer -d 5 &") },
	{ 0,				XF86XK_AudioRaiseVolume,    spawn,         SHCMD("pamixer -i 5 &") },


	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

