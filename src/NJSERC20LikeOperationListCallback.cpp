// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

#include "NJSERC20LikeOperationListCallback.hpp"
#include "NJSObjectWrapper.hpp"
#include "NJSHexUtils.hpp"

using namespace v8;
using namespace node;
using namespace std;

void NJSERC20LikeOperationListCallback::onCallback(const std::experimental::optional<std::vector<std::shared_ptr<::ledger::core::api::ERC20LikeOperation>>> & result, const std::experimental::optional<::ledger::core::api::Error> & error)
{
    Nan::HandleScope scope;
    //Wrap parameters
    Local<Value> arg_0;
    if(result)
    {
        auto arg_0_optional = (result).value();
        Local<Array> arg_0_tmp = Nan::New<Array>();
        for(size_t arg_0_tmp_id = 0; arg_0_tmp_id < arg_0_optional.size(); arg_0_tmp_id++)
        {
            auto arg_0_tmp_elem = NJSERC20LikeOperation::wrap(arg_0_optional[arg_0_tmp_id]);

            Nan::Set(arg_0_tmp, (int)arg_0_tmp_id,arg_0_tmp_elem);
        }

        arg_0 = arg_0_tmp;
    }

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

NAN_METHOD(NJSERC20LikeOperationListCallback::New) {
    //Only new allowed
    if(!info.IsConstructCall())
    {
        return Nan::ThrowError("NJSERC20LikeOperationListCallback function can only be called as constructor (use New)");
    }

    auto resolver = v8::Promise::Resolver::New(Nan::GetCurrentContext()).ToLocalChecked();
    auto node_instance = std::make_shared<NJSERC20LikeOperationListCallback>(resolver);
    djinni::js::ObjectWrapper<NJSERC20LikeOperationListCallback>::Wrap(node_instance, info.This());
    info.GetReturnValue().Set(info.This());
}


Nan::Persistent<ObjectTemplate> NJSERC20LikeOperationListCallback::ERC20LikeOperationListCallback_prototype;

Local<Object> NJSERC20LikeOperationListCallback::wrap(const std::shared_ptr<ledger::core::api::ERC20LikeOperationListCallback> &object) {
    Nan::EscapableHandleScope scope;
    Local<ObjectTemplate> local_prototype = Nan::New(ERC20LikeOperationListCallback_prototype);

    Local<Object> obj;
    if(!local_prototype.IsEmpty())
    {
        obj = local_prototype->NewInstance(Nan::GetCurrentContext()).ToLocalChecked();
        djinni::js::ObjectWrapper<ledger::core::api::ERC20LikeOperationListCallback>::Wrap(object, obj);
    }
    else
    {
        Nan::ThrowError("NJSERC20LikeOperationListCallback::wrap: object template not valid");
    }
    return scope.Escape(obj);
}

void NJSERC20LikeOperationListCallback::Initialize(Local<Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> func_template = Nan::New<FunctionTemplate>(NJSERC20LikeOperationListCallback::New);
    Local<ObjectTemplate> objectTemplate = func_template->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    func_template->SetClassName(Nan::New<String>("NJSERC20LikeOperationListCallback").ToLocalChecked());
    Nan::SetPrototypeMethod(func_template,"New", New);
    //Set object prototype
    ERC20LikeOperationListCallback_prototype.Reset(objectTemplate);

    //Add template to target
    Nan::Set(target, Nan::New<String>("NJSERC20LikeOperationListCallback").ToLocalChecked(), Nan::GetFunction(func_template).ToLocalChecked());
}
