// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from database.djinni

#include "NJSDatabaseConnection.hpp"
#include "NJSObjectWrapper.hpp"

using namespace v8;
using namespace node;
using namespace std;

std::shared_ptr<DatabaseStatement> NJSDatabaseConnection::prepareStatement(const std::string & query, bool repeatable)
{
    Nan::HandleScope scope;
    //Wrap parameters
    auto arg_0 = Nan::New<String>(query).ToLocalChecked();
    auto arg_1 = Nan::New<Boolean>(repeatable);
    Handle<Value> args[2] = {arg_0,arg_1};
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSDatabaseConnection::prepareStatement fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("prepareStatement").ToLocalChecked()).ToLocalChecked();
    auto result_prepareStatement = Nan::CallAsFunction(calling_funtion->ToObject(),local_njs_impl,2,args);
    if(result_prepareStatement.IsEmpty())
    {
        Nan::ThrowError("NJSDatabaseConnection::prepareStatement call failed");
    }
    auto checkedResult_prepareStatement = result_prepareStatement.ToLocalChecked();
    Local<Object> njs_fResult_prepareStatement = checkedResult_prepareStatement->ToObject(Nan::GetCurrentContext()).ToLocalChecked();
    auto fResult_prepareStatement = djinni::js::ObjectWrapper<ledger::core::api::DatabaseStatement>::Unwrap(njs_fResult_prepareStatement);

    return fResult_prepareStatement;
}

void NJSDatabaseConnection::begin()
{
    Nan::HandleScope scope;
    //Wrap parameters
    Handle<Value> args[1];
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSDatabaseConnection::begin fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("begin").ToLocalChecked()).ToLocalChecked();
    auto result_begin = Nan::CallAsFunction(calling_funtion->ToObject(),local_njs_impl,0,args);
    if(result_begin.IsEmpty())
    {
        Nan::ThrowError("NJSDatabaseConnection::begin call failed");
    }
}

void NJSDatabaseConnection::rollback()
{
    Nan::HandleScope scope;
    //Wrap parameters
    Handle<Value> args[1];
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSDatabaseConnection::rollback fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("rollback").ToLocalChecked()).ToLocalChecked();
    auto result_rollback = Nan::CallAsFunction(calling_funtion->ToObject(),local_njs_impl,0,args);
    if(result_rollback.IsEmpty())
    {
        Nan::ThrowError("NJSDatabaseConnection::rollback call failed");
    }
}

void NJSDatabaseConnection::commit()
{
    Nan::HandleScope scope;
    //Wrap parameters
    Handle<Value> args[1];
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSDatabaseConnection::commit fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("commit").ToLocalChecked()).ToLocalChecked();
    auto result_commit = Nan::CallAsFunction(calling_funtion->ToObject(),local_njs_impl,0,args);
    if(result_commit.IsEmpty())
    {
        Nan::ThrowError("NJSDatabaseConnection::commit call failed");
    }
}

void NJSDatabaseConnection::close()
{
    Nan::HandleScope scope;
    //Wrap parameters
    Handle<Value> args[1];
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSDatabaseConnection::close fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("close").ToLocalChecked()).ToLocalChecked();
    auto result_close = Nan::CallAsFunction(calling_funtion->ToObject(),local_njs_impl,0,args);
    if(result_close.IsEmpty())
    {
        Nan::ThrowError("NJSDatabaseConnection::close call failed");
    }
}

std::shared_ptr<DatabaseBlob> NJSDatabaseConnection::newBlob()
{
    Nan::HandleScope scope;
    //Wrap parameters
    Handle<Value> args[1];
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSDatabaseConnection::newBlob fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("newBlob").ToLocalChecked()).ToLocalChecked();
    auto result_newBlob = Nan::CallAsFunction(calling_funtion->ToObject(),local_njs_impl,0,args);
    if(result_newBlob.IsEmpty())
    {
        Nan::ThrowError("NJSDatabaseConnection::newBlob call failed");
    }
    auto checkedResult_newBlob = result_newBlob.ToLocalChecked();
    Local<Object> njs_fResult_newBlob = checkedResult_newBlob->ToObject(Nan::GetCurrentContext()).ToLocalChecked();
    auto fResult_newBlob = djinni::js::ObjectWrapper<ledger::core::api::DatabaseBlob>::Unwrap(njs_fResult_newBlob);

    return fResult_newBlob;
}

NAN_METHOD(NJSDatabaseConnection::New) {
    //Only new allowed
    if(!info.IsConstructCall())
    {
        return Nan::ThrowError("NJSDatabaseConnection function can only be called as constructor (use New)");
    }

    if(!info[0]->IsObject())
    {
        return Nan::ThrowError("NJSDatabaseConnection::New requires an implementation from node");
    }
    auto node_instance = std::make_shared<NJSDatabaseConnection>(info[0]->ToObject());
    djinni::js::ObjectWrapper<NJSDatabaseConnection>::Wrap(node_instance, info.This());
    info.GetReturnValue().Set(info.This());
}


Nan::Persistent<ObjectTemplate> NJSDatabaseConnection::DatabaseConnection_prototype;

Local<Object> NJSDatabaseConnection::wrap(const std::shared_ptr<ledger::core::api::DatabaseConnection> &object) {
    Nan::EscapableHandleScope scope;
    Local<ObjectTemplate> local_prototype = Nan::New(DatabaseConnection_prototype);

    Local<Object> obj;
    if(!local_prototype.IsEmpty())
    {
        obj = local_prototype->NewInstance();
        djinni::js::ObjectWrapper<ledger::core::api::DatabaseConnection>::Wrap(object, obj);
    }
    else
    {
        Nan::ThrowError("NJSDatabaseConnection::wrap: object template not valid");
    }
    return scope.Escape(obj);
}

void NJSDatabaseConnection::Initialize(Local<Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> func_template = Nan::New<FunctionTemplate>(NJSDatabaseConnection::New);
    Local<ObjectTemplate> objectTemplate = func_template->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    func_template->SetClassName(Nan::New<String>("NJSDatabaseConnection").ToLocalChecked());
    Nan::SetPrototypeMethod(func_template,"New", New);
    //Set object prototype
    DatabaseConnection_prototype.Reset(objectTemplate);

    //Add template to target
    target->Set(Nan::New<String>("NJSDatabaseConnection").ToLocalChecked(), func_template->GetFunction());
}
