#ifndef USEFUL_GUARDS_COMPATIBILITY_H
#define USEFUL_GUARDS_COMPATIBILITY_H
#include <TargetConditionals.h>
#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#define IS_APPLE_IPHONE 1
#elif TARGET_OS_MAC || TARGET_CPU_ARM64
#define IS_APPLE_SILICON 1
#else
#define IS_APPLE_IPONE 0
#define IS_APPLE_SILICON 0
#endif
#endif // End USEFUL_GUARDS_COMPATIBILITY_H