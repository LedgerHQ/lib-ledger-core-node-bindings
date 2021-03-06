// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet.djinni

#ifndef DJINNI_GENERATED_COSMOSLIKEREWARD_HPP
#define DJINNI_GENERATED_COSMOSLIKEREWARD_HPP

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

class Amount;

/**Class representing a Cosmos reward */
class LIBCORE_EXPORT CosmosLikeReward {
public:
    virtual ~CosmosLikeReward() {}

    virtual std::string getDelegatorAddress() const = 0;

    virtual std::string getValidatorAddress() const = 0;

    virtual std::shared_ptr<Amount> getRewardAmount() const = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_COSMOSLIKEREWARD_HPP
