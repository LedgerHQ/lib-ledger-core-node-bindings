// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http_client.djinni

#include "NJSHttpRequestCpp.hpp"
#include "NJSObjectWrapper.hpp"

using namespace v8;
using namespace node;
using namespace std;

NAN_METHOD(NJSHttpRequest::getMethod) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSHttpRequest::getMethod needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    auto cpp_impl = djinni::js::ObjectWrapper<HttpRequest>::Unwrap(info.This());
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSHttpRequest::getMethod : implementation of HttpRequest is not valid");
    }

    auto result = cpp_impl->getMethod();

    //Wrap result in node object
    auto arg_0 = Nan::New<Integer>((int)result);

    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSHttpRequest::getHeaders) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSHttpRequest::getHeaders needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    auto cpp_impl = djinni::js::ObjectWrapper<HttpRequest>::Unwrap(info.This());
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSHttpRequest::getHeaders : implementation of HttpRequest is not valid");
    }

    auto result = cpp_impl->getHeaders();

    //Wrap result in node object
    Local<Map> arg_0 = Map::New((Nan::GetCurrentContext())->GetIsolate());
    for(auto const& arg_0_elem : result)
    {
        auto arg_0_first = Nan::New<String>(arg_0_elem.first).ToLocalChecked();
        auto arg_0_second = Nan::New<String>(arg_0_elem.second).ToLocalChecked();
        arg_0->Set(Nan::GetCurrentContext(), arg_0_first, arg_0_second);
    }


    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSHttpRequest::getBody) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSHttpRequest::getBody needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    auto cpp_impl = djinni::js::ObjectWrapper<HttpRequest>::Unwrap(info.This());
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSHttpRequest::getBody : implementation of HttpRequest is not valid");
    }

    auto result = cpp_impl->getBody();

    //Wrap result in node object
    Local<Array> arg_0 = Nan::New<Array>();
    for(size_t arg_0_id = 0; arg_0_id < result.size(); arg_0_id++)
    {
        auto arg_0_elem = Nan::New<Uint32>(result[arg_0_id]);
        arg_0->Set((int)arg_0_id,arg_0_elem);
    }


    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSHttpRequest::getUrl) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSHttpRequest::getUrl needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    auto cpp_impl = djinni::js::ObjectWrapper<HttpRequest>::Unwrap(info.This());
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSHttpRequest::getUrl : implementation of HttpRequest is not valid");
    }

    auto result = cpp_impl->getUrl();

    //Wrap result in node object
    auto arg_0 = Nan::New<String>(result).ToLocalChecked();

    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSHttpRequest::complete) {

    //Check if method called with right number of arguments
    if(info.Length() != 2)
    {
        return Nan::ThrowError("NJSHttpRequest::complete needs 2 arguments");
    }

    //Check if parameters have correct types
    std::shared_ptr<HttpUrlConnection> arg_0 = nullptr;
    if(!info[0]->IsNull())
    {
        Local<Object> njs_opt_arg_0 = info[0]->ToObject(Nan::GetCurrentContext()).ToLocalChecked();
        auto opt_arg_0 = djinni::js::ObjectWrapper<HttpUrlConnection>::Unwrap(njs_opt_arg_0);

        arg_0 = opt_arg_0;
    }

    auto arg_1 = std::experimental::optional<Error>();
    if(!info[1]->IsNull() && !info[1]->IsUndefined())
    {

        auto field_opt_arg_1_1 = Nan::Get(info[1]->ToObject(), Nan::New<String>("code").ToLocalChecked()).ToLocalChecked();
        auto opt_arg_1_1 = (ledger::core::api::ErrorCode)Nan::To<int>(field_opt_arg_1_1).FromJust();

        auto field_opt_arg_1_2 = Nan::Get(info[1]->ToObject(), Nan::New<String>("message").ToLocalChecked()).ToLocalChecked();
        String::Utf8Value string_opt_arg_1_2(field_opt_arg_1_2->ToString());
        auto opt_arg_1_2 = std::string(*string_opt_arg_1_2);
        Error opt_arg_1(opt_arg_1_1, opt_arg_1_2);

        arg_1.emplace(opt_arg_1);
    }


    //Unwrap current object and retrieve its Cpp Implementation
    auto cpp_impl = djinni::js::ObjectWrapper<HttpRequest>::Unwrap(info.This());
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSHttpRequest::complete : implementation of HttpRequest is not valid");
    }
    cpp_impl->complete(arg_0,arg_1);
}

NAN_METHOD(NJSHttpRequest::New) {
    //Only new allowed
    if(!info.IsConstructCall())
    {
        return Nan::ThrowError("NJSHttpRequest function can only be called as constructor (use New)");
    }
    info.GetReturnValue().Set(info.This());
}


Nan::Persistent<ObjectTemplate> NJSHttpRequest::HttpRequest_prototype;

Local<Object> NJSHttpRequest::wrap(const std::shared_ptr<ledger::core::api::HttpRequest> &object) {
    Nan::EscapableHandleScope scope;
    Local<ObjectTemplate> local_prototype = Nan::New(HttpRequest_prototype);

    Local<Object> obj;
    if(!local_prototype.IsEmpty())
    {
        obj = local_prototype->NewInstance();
        djinni::js::ObjectWrapper<ledger::core::api::HttpRequest>::Wrap(object, obj);
    }
    else
    {
        Nan::ThrowError("NJSHttpRequest::wrap: object template not valid");
    }
    return scope.Escape(obj);
}

NAN_METHOD(NJSHttpRequest::isNull) {
    auto cpp_implementation = djinni::js::ObjectWrapper<HttpRequest>::Unwrap(info.This());
    auto isNull = !cpp_implementation ? true : false;
    return info.GetReturnValue().Set(Nan::New<Boolean>(isNull));
}

void NJSHttpRequest::Initialize(Local<Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> func_template = Nan::New<FunctionTemplate>(NJSHttpRequest::New);
    Local<ObjectTemplate> objectTemplate = func_template->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    func_template->SetClassName(Nan::New<String>("NJSHttpRequest").ToLocalChecked());

    //SetPrototypeMethod all methods
    Nan::SetPrototypeMethod(func_template,"getMethod", getMethod);
    Nan::SetPrototypeMethod(func_template,"getHeaders", getHeaders);
    Nan::SetPrototypeMethod(func_template,"getBody", getBody);
    Nan::SetPrototypeMethod(func_template,"getUrl", getUrl);
    Nan::SetPrototypeMethod(func_template,"complete", complete);
    //Set object prototype
    HttpRequest_prototype.Reset(objectTemplate);
    Nan::SetPrototypeMethod(func_template,"isNull", isNull);

    //Add template to target
    target->Set(Nan::New<String>("NJSHttpRequest").ToLocalChecked(), func_template->GetFunction());
}
