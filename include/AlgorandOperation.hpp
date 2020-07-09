// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from idl.djinni

#ifndef DJINNI_GENERATED_ALGORANDOPERATION_HPP
#define DJINNI_GENERATED_ALGORANDOPERATION_HPP

#include <memory>
#include <string>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER)
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

class AlgorandTransaction;
enum class AlgorandOperationType;

class LIBCORE_EXPORT AlgorandOperation {
public:
    virtual ~AlgorandOperation() {}

    virtual std::shared_ptr<AlgorandTransaction> getTransaction() const = 0;

    virtual AlgorandOperationType getAlgorandOperationType() const = 0;

    virtual std::string getRewards() const = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_ALGORANDOPERATION_HPP
