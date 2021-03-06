// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet.djinni

#include "NJSKeychainCpp.hpp"
#include "NJSObjectWrapper.hpp"
#include "NJSHexUtils.hpp"

using namespace v8;
using namespace node;
using namespace std;

NAN_METHOD(NJSKeychain::contains) {

    //Check if method called with right number of arguments
    if(info.Length() != 1)
    {
        return Nan::ThrowError("NJSKeychain::contains needs 1 arguments");
    }

    //Check if parameters have correct types
    Nan::Utf8String string_arg_0(info[0]->ToString(Nan::GetCurrentContext()).ToLocalChecked());
    auto arg_0 = std::string(*string_arg_0);

    //Unwrap current object and retrieve its Cpp Implementation
    auto cpp_impl = djinni::js::ObjectWrapper<ledger::core::api::Keychain>::Unwrap(info.This());
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSKeychain::contains : implementation of Keychain is not valid");
    }

    auto result = cpp_impl->contains(arg_0);

    //Wrap result in node object
    auto arg_1 = Nan::New<Boolean>(result);

    //Return result
    info.GetReturnValue().Set(arg_1);
}

NAN_METHOD(NJSKeychain::New) {
    //Only new allowed
    if(!info.IsConstructCall())
    {
        return Nan::ThrowError("NJSKeychain function can only be called as constructor (use New)");
    }
    info.GetReturnValue().Set(info.This());
}


Nan::Persistent<ObjectTemplate> NJSKeychain::Keychain_prototype;

Local<Object> NJSKeychain::wrap(const std::shared_ptr<ledger::core::api::Keychain> &object) {
    Nan::EscapableHandleScope scope;
    Local<ObjectTemplate> local_prototype = Nan::New(Keychain_prototype);

    Local<Object> obj;
    if(!local_prototype.IsEmpty())
    {
        obj = local_prototype->NewInstance(Nan::GetCurrentContext()).ToLocalChecked();
        djinni::js::ObjectWrapper<ledger::core::api::Keychain>::Wrap(object, obj);
    }
    else
    {
        Nan::ThrowError("NJSKeychain::wrap: object template not valid");
    }
    return scope.Escape(obj);
}

NAN_METHOD(NJSKeychain::isNull) {
    auto cpp_implementation = djinni::js::ObjectWrapper<ledger::core::api::Keychain>::Unwrap(info.This());
    auto isNull = !cpp_implementation ? true : false;
    return info.GetReturnValue().Set(Nan::New<Boolean>(isNull));
}

void NJSKeychain::Initialize(Local<Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> func_template = Nan::New<FunctionTemplate>(NJSKeychain::New);
    Local<ObjectTemplate> objectTemplate = func_template->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    func_template->SetClassName(Nan::New<String>("NJSKeychain").ToLocalChecked());

    //SetPrototypeMethod all methods
    Nan::SetPrototypeMethod(func_template,"contains", contains);
    Nan::SetPrototypeMethod(func_template,"isNull", isNull);
    //Set object prototype
    Keychain_prototype.Reset(objectTemplate);

    //Add template to target
    Nan::Set(target, Nan::New<String>("NJSKeychain").ToLocalChecked(), Nan::GetFunction(func_template).ToLocalChecked());
}
