#ifndef TUIPLUSPLUS_HPP_INCLUDE_HEADER
#define TUIPLUSPLUS_HPP_INCLUDE_HEADER

#ifdef _WIN32
#define TPP_HELPERS_OPERATING_SYSTEM "Windows"
#endif

#ifdef _WIN64
#define TPP_HELPERS_OPERATING_SYSTEM "Windows"
#endif

#ifdef __linux__
#define TPP_HELPERS_OPERATING_SYSTEM "Linux"
#endif

#ifdef __APPLE__
#define TPP_HELPERS_OPERATING_SYSTEM "MacOS"
#endif

#ifndef TPP_HELPERS_OPERATING_SYSTEM
#define TPP_HELPERS_OPERATING_SYSTEM "Unknown"
#endif

#define TPP_VERSION         "1.0"
#define TPP_BUILD           "rel"
#define TPP_FULL_VERSION    "libtui++ v" TPP_VERSION "-" TPP_BUILD " on " TPP_HELPERS_OPERATING_SYSTEM

#endif
