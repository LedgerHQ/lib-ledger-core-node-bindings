// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ripple_like_wallet.djinni

#ifndef DJINNI_GENERATED_RIPPLELIKEACCOUNT_HPP
#define DJINNI_GENERATED_RIPPLELIKEACCOUNT_HPP

#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER)
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

class AmountCallback;
class BoolCallback;
class RippleLikeTransaction;
class RippleLikeTransactionBuilder;
class StringCallback;

/**Class representing a Ripple account */
class LIBCORE_EXPORT RippleLikeAccount {
public:
    virtual ~RippleLikeAccount() {}

    virtual void broadcastRawTransaction(const std::vector<uint8_t> & transaction, const std::shared_ptr<StringCallback> & callback) = 0;

    virtual void broadcastTransaction(const std::shared_ptr<RippleLikeTransaction> & transaction, const std::shared_ptr<StringCallback> & callback) = 0;

    virtual std::shared_ptr<RippleLikeTransactionBuilder> buildTransaction() = 0;

    /**
     * Get fees from network
     * Note: it would have been better to have this method on RippleLikeWallet
     * but since RippleLikeWallet is not used anywhere, it's better to keep all
     * specific methods under the same specific class so it will be easy to segratate
     * when the right time comes !
     */
    virtual void getFees(const std::shared_ptr<AmountCallback> & callback) = 0;

    /**
     * Get base reserve (dust to leave on an XRP account) from network
     * Note: same note as above
     */
    virtual void getBaseReserve(const std::shared_ptr<AmountCallback> & callback) = 0;

    /**
     * Check whether an account has been activated or not
     * Here activation, means that the XRP account received a first transaction with a minimum amount
     * greater or equal to XRP base reserve
     * @param: address to check
     * @return: true if valid address and has been activated, false otherwise
     */
    virtual void isAddressActivated(const std::string & address, const std::shared_ptr<BoolCallback> & isActivated) = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_RIPPLELIKEACCOUNT_HPP
