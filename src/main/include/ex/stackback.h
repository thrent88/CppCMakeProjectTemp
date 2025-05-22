#ifndef EX_STACKBACK_H
#define EX_STACKBACK_H  

#include <cpptrace/from_current.hpp>
#include <cpptrace/formatting.hpp>

#define PrintCurrentStack() \
    cpptrace::formatter{}   \
    .header("Stack trace:") \
    .addresses(cpptrace::formatter::address_mode::object)   \
    .print(cpptrace::from_current_exception())


#endif // EX_STACKBACK_H