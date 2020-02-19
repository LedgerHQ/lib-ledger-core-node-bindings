// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ripple_like_wallet.djinni

#include "NJSRippleLikeOperationCpp.hpp"
#include "NJSObjectWrapper.hpp"

using namespace v8;
using namespace node;
using namespace std;

NAN_METHOD(NJSRippleLikeOperation::getTransaction) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSRippleLikeOperation::getTransaction needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    auto cpp_impl = djinni::js::ObjectWrapper<ledger::core::api::RippleLikeOperation>::Unwrap(info.This());
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSRippleLikeOperation::getTransaction : implementation of RippleLikeOperation is not valid");
    }

    auto result = cpp_impl->getTransaction();

    //Wrap result in node object
    auto arg_0 = NJSRippleLikeTransaction::wrap(result);


    //Return result
    info.GetReturnValue().Set(arg_0);
}

NAN_METHOD(NJSRippleLikeOperation::New) {
    //Only new allowed
    if(!info.IsConstructCall())
    {
        return Nan::ThrowError("NJSRippleLikeOperation function can only be called as constructor (use New)");
    }
    info.GetReturnValue().Set(info.This());
}


Nan::Persistent<ObjectTemplate> NJSRippleLikeOperation::RippleLikeOperation_prototype;

Local<Object> NJSRippleLikeOperation::wrap(const std::shared_ptr<ledger::core::api::RippleLikeOperation> &object) {
    Nan::EscapableHandleScope scope;
    Local<ObjectTemplate> local_prototype = Nan::New(RippleLikeOperation_prototype);

    Local<Object> obj;
    if(!local_prototype.IsEmpty())
    {
        obj = local_prototype->NewInstance(Nan::GetCurrentContext()).ToLocalChecked();
        djinni::js::ObjectWrapper<ledger::core::api::RippleLikeOperation>::Wrap(object, obj);
    }
    else
    {
        Nan::ThrowError("NJSRippleLikeOperation::wrap: object template not valid");
    }
    return scope.Escape(obj);
}

NAN_METHOD(NJSRippleLikeOperation::isNull) {
    auto cpp_implementation = djinni::js::ObjectWrapper<ledger::core::api::RippleLikeOperation>::Unwrap(info.This());
    auto isNull = !cpp_implementation ? true : false;
    return info.GetReturnValue().Set(Nan::New<Boolean>(isNull));
}

void NJSRippleLikeOperation::Initialize(Local<Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> func_template = Nan::New<FunctionTemplate>(NJSRippleLikeOperation::New);
    Local<ObjectTemplate> objectTemplate = func_template->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    func_template->SetClassName(Nan::New<String>("NJSRippleLikeOperation").ToLocalChecked());

    //SetPrototypeMethod all methods
    Nan::SetPrototypeMethod(func_template,"getTransaction", getTransaction);
    Nan::SetPrototypeMethod(func_template,"isNull", isNull);
    //Set object prototype
    RippleLikeOperation_prototype.Reset(objectTemplate);

    //Add template to target
    target->Set(Nan::New<String>("NJSRippleLikeOperation").ToLocalChecked(), func_template->GetFunction(Nan::GetCurrentContext()).ToLocalChecked());
}
