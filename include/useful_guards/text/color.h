#ifndef USEFUL_GUARDS_TEXT_COLOR_H
#define USEFUL_GUARDS_TEXT_COLOR_H
#ifdef CYNTHIA_USE_VT100
static const char t_normal[] = { 0x1b, '[', '0', ';', '0', ';', '0', 'm', 0 };
static const char t_black[] = { 0x1b, '[', '0', ';', '3', '0', ';', '5', '9', 'm', 0 };
static const char t_red[] = { 0x1b, '[', '0', ';', '3', '1', ';', '5', '9', 'm', 0 };
static const char t_green[] = { 0x1b, '[', '0', ';', '3', '2', ';', '5', '9', 'm', 0 };
static const char t_yellow[] = { 0x1b, '[', '0', ';', '3', '3', ';', '5', '9', 'm', 0 };
static const char t_blue[] = { 0x1b, '[', '0', ';', '3', '4', ';', '5', '9', 'm', 0 };
static const char t_magenta[] = { 0x1b, '[', '0', ';', '3', '5', ';', '5', '9', 'm', 0 };
static const char t_cyan[] = { 0x1b, '[', '0', ';', '3', '6', ';', '5', '9', 'm', 0 };
static const char t_white[] = { 0x1b, '[', '0', ';', '3', '7', ';', '5', '9', 'm', 0 };
static const char t_bold[] = { 0x1b, '[', '1', 'm', 0 };
static const char t_underscore[] = { 0x1b, '[', '4', 'm', 0 };
#endif // End CYNTHIA_USE_VT100
#endif // End USEFUL_GUARDS_TEXT_COLOR_H