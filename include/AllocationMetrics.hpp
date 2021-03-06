// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from core.djinni

#ifndef DJINNI_GENERATED_ALLOCATIONMETRICS_HPP
#define DJINNI_GENERATED_ALLOCATIONMETRICS_HPP

#include <cstdint>
#include <string>
#include <unordered_map>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER)
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

class LIBCORE_EXPORT AllocationMetrics {
public:
    virtual ~AllocationMetrics() {}

    static std::unordered_map<std::string, int32_t> getObjectAllocations();
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_ALLOCATIONMETRICS_HPP
