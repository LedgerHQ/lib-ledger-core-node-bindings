// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from idl.djinni

#include "NJSAlgorandOperationCpp.hpp"
#include "NJSObjectWrapper.hpp"
#include "NJSHexUtils.hpp"

using namespace v8;
using namespace node;
using namespace std;

NAN_METHOD(NJSAlgorandOperation::getTransaction) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSAlgorandOperation::getTransaction needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    auto cpp_impl = djinni::js::ObjectWrapper<ledger::core::api::AlgorandOperation>::Unwrap(info.This());
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSAlgorandOperation::getTransaction : implementation of AlgorandOperation is not valid");
    }

    auto result = cpp_impl->getTransaction();

    //Wrap result in node object
    auto arg_0 = NJSAlgorandTransaction::wrap(result);


    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSAlgorandOperation::getAlgorandOperationType) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSAlgorandOperation::getAlgorandOperationType needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    auto cpp_impl = djinni::js::ObjectWrapper<ledger::core::api::AlgorandOperation>::Unwrap(info.This());
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSAlgorandOperation::getAlgorandOperationType : implementation of AlgorandOperation is not valid");
    }

    auto result = cpp_impl->getAlgorandOperationType();

    //Wrap result in node object
    auto arg_0 = Nan::New<Integer>((int)result);

    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSAlgorandOperation::getRewards) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSAlgorandOperation::getRewards needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    auto cpp_impl = djinni::js::ObjectWrapper<ledger::core::api::AlgorandOperation>::Unwrap(info.This());
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSAlgorandOperation::getRewards : implementation of AlgorandOperation is not valid");
    }

    auto result = cpp_impl->getRewards();

    //Wrap result in node object
    auto arg_0 = Nan::New<String>(result).ToLocalChecked();

    //Return result
    info.GetReturnValue().Set(arg_0);
}

NAN_METHOD(NJSAlgorandOperation::New) {
    //Only new allowed
    if(!info.IsConstructCall())
    {
        return Nan::ThrowError("NJSAlgorandOperation function can only be called as constructor (use New)");
    }
    info.GetReturnValue().Set(info.This());
}


Nan::Persistent<ObjectTemplate> NJSAlgorandOperation::AlgorandOperation_prototype;

Local<Object> NJSAlgorandOperation::wrap(const std::shared_ptr<ledger::core::api::AlgorandOperation> &object) {
    Nan::EscapableHandleScope scope;
    Local<ObjectTemplate> local_prototype = Nan::New(AlgorandOperation_prototype);

    Local<Object> obj;
    if(!local_prototype.IsEmpty())
    {
        obj = local_prototype->NewInstance(Nan::GetCurrentContext()).ToLocalChecked();
        djinni::js::ObjectWrapper<ledger::core::api::AlgorandOperation>::Wrap(object, obj);
    }
    else
    {
        Nan::ThrowError("NJSAlgorandOperation::wrap: object template not valid");
    }
    return scope.Escape(obj);
}

NAN_METHOD(NJSAlgorandOperation::isNull) {
    auto cpp_implementation = djinni::js::ObjectWrapper<ledger::core::api::AlgorandOperation>::Unwrap(info.This());
    auto isNull = !cpp_implementation ? true : false;
    return info.GetReturnValue().Set(Nan::New<Boolean>(isNull));
}

void NJSAlgorandOperation::Initialize(Local<Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> func_template = Nan::New<FunctionTemplate>(NJSAlgorandOperation::New);
    Local<ObjectTemplate> objectTemplate = func_template->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    func_template->SetClassName(Nan::New<String>("NJSAlgorandOperation").ToLocalChecked());

    //SetPrototypeMethod all methods
    Nan::SetPrototypeMethod(func_template,"getTransaction", getTransaction);
    Nan::SetPrototypeMethod(func_template,"getAlgorandOperationType", getAlgorandOperationType);
    Nan::SetPrototypeMethod(func_template,"getRewards", getRewards);
    Nan::SetPrototypeMethod(func_template,"isNull", isNull);
    //Set object prototype
    AlgorandOperation_prototype.Reset(objectTemplate);

    //Add template to target
    Nan::Set(target, Nan::New<String>("NJSAlgorandOperation").ToLocalChecked(), Nan::GetFunction(func_template).ToLocalChecked());
}
