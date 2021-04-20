// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

#include "NJSERC20LikeOperationCallback.hpp"
#include "NJSObjectWrapper.hpp"
#include "NJSHexUtils.hpp"

using namespace v8;
using namespace node;
using namespace std;

void NJSERC20LikeOperationCallback::onCallback(const std::shared_ptr<::ledger::core::api::ERC20LikeOperation> & result, const std::experimental::optional<::ledger::core::api::Error> & error)
{
    Nan::HandleScope scope;
    //Wrap parameters
    auto arg_0 = NJSERC20LikeOperation::wrap(result);


    Local<Value> arg_1;
    if(error)
    {
        auto arg_1_optional = (error).value();
        auto arg_1_tmp = Nan::New<Object>();
        auto arg_1_tmp_1 = Nan::New<Integer>((int)arg_1_optional.code);
        Nan::DefineOwnProperty(arg_1_tmp, Nan::New<String>("code").ToLocalChecked(), arg_1_tmp_1);
        auto arg_1_tmp_2 = Nan::New<String>(arg_1_optional.message).ToLocalChecked();
        Nan::DefineOwnProperty(arg_1_tmp, Nan::New<String>("message").ToLocalChecked(), arg_1_tmp_2);

        arg_1 = arg_1_tmp;
    }

    auto local_resolver = Nan::New<Promise::Resolver>(pers_resolver);
    if(error)
    {
        auto rejected = local_resolver->Reject(Nan::GetCurrentContext(), arg_1);
        rejected.FromJust();
    }
    else
    {
        auto resolve = local_resolver->Resolve(Nan::GetCurrentContext(), arg_0);
        resolve.FromJust();
    }
}

NAN_METHOD(NJSERC20LikeOperationCallback::New) {
    //Only new allowed
    if(!info.IsConstructCall())
    {
        return Nan::ThrowError("NJSERC20LikeOperationCallback function can only be called as constructor (use New)");
    }

    auto resolver = v8::Promise::Resolver::New(Nan::GetCurrentContext()).ToLocalChecked();
    auto node_instance = std::make_shared<NJSERC20LikeOperationCallback>(resolver);
    djinni::js::ObjectWrapper<NJSERC20LikeOperationCallback>::Wrap(node_instance, info.This());
    info.GetReturnValue().Set(info.This());
}


Nan::Persistent<ObjectTemplate> NJSERC20LikeOperationCallback::ERC20LikeOperationCallback_prototype;

Local<Object> NJSERC20LikeOperationCallback::wrap(const std::shared_ptr<ledger::core::api::ERC20LikeOperationCallback> &object) {
    Nan::EscapableHandleScope scope;
    Local<ObjectTemplate> local_prototype = Nan::New(ERC20LikeOperationCallback_prototype);

    Local<Object> obj;
    if(!local_prototype.IsEmpty())
    {
        obj = local_prototype->NewInstance(Nan::GetCurrentContext()).ToLocalChecked();
        djinni::js::ObjectWrapper<ledger::core::api::ERC20LikeOperationCallback>::Wrap(object, obj);
    }
    else
    {
        Nan::ThrowError("NJSERC20LikeOperationCallback::wrap: object template not valid");
    }
    return scope.Escape(obj);
}

void NJSERC20LikeOperationCallback::Initialize(Local<Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> func_template = Nan::New<FunctionTemplate>(NJSERC20LikeOperationCallback::New);
    Local<ObjectTemplate> objectTemplate = func_template->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    func_template->SetClassName(Nan::New<String>("NJSERC20LikeOperationCallback").ToLocalChecked());
    Nan::SetPrototypeMethod(func_template,"New", New);
    //Set object prototype
    ERC20LikeOperationCallback_prototype.Reset(objectTemplate);

    //Add template to target
    Nan::Set(target, Nan::New<String>("NJSERC20LikeOperationCallback").ToLocalChecked(), Nan::GetFunction(func_template).ToLocalChecked());
}
