// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from stellar_like_wallet.djinni

#ifndef DJINNI_GENERATED_NJSSTELLARLIKETRANSACTION_HPP
#define DJINNI_GENERATED_NJSSTELLARLIKETRANSACTION_HPP


#include "NJSAddressCpp.hpp"
#include "NJSAmountCpp.hpp"
#include "NJSBigIntCpp.hpp"
#include "NJSStellarLikeMemoCpp.hpp"
#include <cstdint>
#include <memory>
#include <vector>

#include <nan.h>
#include <node.h>
#include "../include/StellarLikeTransaction.hpp"

using namespace v8;
using namespace node;
using namespace std;
using namespace ledger::core::api;

class NJSStellarLikeTransaction final {
public:

    static void Initialize(Local<Object> target);
    NJSStellarLikeTransaction() = delete;

    static Local<Object> wrap(const std::shared_ptr<ledger::core::api::StellarLikeTransaction> &object);
    static Nan::Persistent<ObjectTemplate> StellarLikeTransaction_prototype;

private:
    static NAN_METHOD(toRawTransaction);

    /** Returns the payload which should be signed by the user in order to send the transaction. */
    static NAN_METHOD(toSignatureBase);

    /** Add a new signature to the transaction envelope */
    static NAN_METHOD(putSignature);

    /** Returns the author of the transaction */
    static NAN_METHOD(getSourceAccount);

    /** Returns the sequence of the source account used for this transaction */
    static NAN_METHOD(getSourceAccountSequence);

    /** Returns the fee paid for this transaction to be validated */
    static NAN_METHOD(getFee);

    /** Returns the transaction memo */
    static NAN_METHOD(getMemo);

    static NAN_METHOD(New);

    static NAN_METHOD(isNull);
};
#endif //DJINNI_GENERATED_NJSSTELLARLIKETRANSACTION_HPP