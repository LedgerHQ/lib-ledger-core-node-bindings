// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from stellar_like_wallet.djinni

#ifndef DJINNI_GENERATED_NJSSTELLARLIKEMEMO_HPP
#define DJINNI_GENERATED_NJSSTELLARLIKEMEMO_HPP


#include "../include/StellarLikeMemoType.hpp"
#include "NJSBigIntCpp.hpp"
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include <nan.h>
#include <node.h>
#include "../include/StellarLikeMemo.hpp"

using namespace v8;
using namespace node;
using namespace std;
using namespace ledger::core::api;

class NJSStellarLikeMemo final {
public:

    static void Initialize(Local<Object> target);
    NJSStellarLikeMemo() = delete;

    static Local<Object> wrap(const std::shared_ptr<ledger::core::api::StellarLikeMemo> &object);
    static Nan::Persistent<ObjectTemplate> StellarLikeMemo_prototype;

private:
    static NAN_METHOD(getMemoType);

    /** Get the value of the memo as string. Fail if the memo is not with type MEMO_TEXT */
    static NAN_METHOD(getMemoText);

    /** Get the value of the memo as BigInt. Fail if the memo is not with type MEMO_ID */
    static NAN_METHOD(getMemoId);

    /** Get the value of the memo as byte array. Fail if the memo is not with type MEMO_HASH */
    static NAN_METHOD(getMemoHash);

    /** Get the value of the memo as byte array. Fail if the memo is not with type MEMO_RETURN */
    static NAN_METHOD(getMemoReturn);

    /**
     * Create a string version of the memo, no matter which underlying type it holds.
     * For MEMO_TEXT returns memo value.
     * For MEMO_ID, return a uint64 as string (base 10).
     * For MEMO_HASH, MEMO_RETURN, returns a hex encoded string.
     * For MEMO_NONE, returns an empty string
     */
    static NAN_METHOD(memoValuetoString);

    static NAN_METHOD(New);

    static NAN_METHOD(isNull);
};
#endif //DJINNI_GENERATED_NJSSTELLARLIKEMEMO_HPP
