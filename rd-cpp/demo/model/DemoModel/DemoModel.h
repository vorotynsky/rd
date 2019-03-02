#ifndef DemoModel_H
#define DemoModel_H

#include "Buffer.h"
#include "Identities.h"
#include "MessageBroker.h"
#include "Protocol.h"
#include "RdId.h"
#include "RdList.h"
#include "RdMap.h"
#include "RdProperty.h"
#include "RdSet.h"
#include "RdSignal.h"
#include "RName.h"
#include "ISerializable.h"
#include "Polymorphic.h"
#include "NullableSerializer.h"
#include "ArraySerializer.h"
#include "SerializationCtx.h"
#include "Serializers.h"
#include "ISerializersOwner.h"
#include "IUnknownInstance.h"
#include "RdExtBase.h"
#include "RdCall.h"
#include "RdEndpoint.h"
#include "RdTask.h"
#include "gen_util.h"

#include <iostream>
#include <cstring>
#include <cstdint>
#include <vector>
#include <type_traits>
#include <utility>

#include "optional.hpp"

#include "MyScalar.h"


#pragma warning( push )
#pragma warning( disable:4250 )
class DemoModel : public rd::RdExtBase
{
    
    //companion
    
    public:
    struct DemoModelSerializersOwner : public rd::ISerializersOwner {
        void registerSerializersCore(rd::Serializers const& serializers);
    };
    
    static DemoModelSerializersOwner serializersOwner;
    
    
    public:
    void connect(rd::Lifetime lifetime, rd::IProtocol const * protocol);
    
    
    //custom serializers
    private:
    
    //fields
    protected:
    rd::RdProperty<bool, rd::Polymorphic<bool>> boolean_property_;
    rd::RdProperty<MyScalar, rd::Polymorphic<MyScalar>> scalar_;
    rd::RdList<int32_t, rd::Polymorphic<int32_t>> list_;
    rd::RdSet<int32_t, rd::Polymorphic<int32_t>> set_;
    rd::RdMap<int64_t, std::wstring, rd::Polymorphic<int64_t>, rd::Polymorphic<std::wstring>> mapLongToString_;
    rd::RdCall<wchar_t, std::wstring, rd::Polymorphic<wchar_t>, rd::Polymorphic<std::wstring>> call_;
    rd::RdEndpoint<std::wstring, int32_t, rd::Polymorphic<std::wstring>, rd::Polymorphic<int32_t>> callback_;
    
    
    //initializer
    private:
    void initialize();
    
    //primary ctor
    public:
    explicit DemoModel(rd::RdProperty<bool, rd::Polymorphic<bool>> boolean_property_, rd::RdProperty<MyScalar, rd::Polymorphic<MyScalar>> scalar_, rd::RdList<int32_t, rd::Polymorphic<int32_t>> list_, rd::RdSet<int32_t, rd::Polymorphic<int32_t>> set_, rd::RdMap<int64_t, std::wstring, rd::Polymorphic<int64_t>, rd::Polymorphic<std::wstring>> mapLongToString_, rd::RdCall<wchar_t, std::wstring, rd::Polymorphic<wchar_t>, rd::Polymorphic<std::wstring>> call_, rd::RdEndpoint<std::wstring, int32_t, rd::Polymorphic<std::wstring>, rd::Polymorphic<int32_t>> callback_);
    
    
    //default ctors and dtors
    
    DemoModel() {
        initialize();
    };
    
    DemoModel(DemoModel &&) = delete;
    
    DemoModel& operator=(DemoModel &&) = delete;
    
    virtual ~DemoModel() = default;
    
    //reader
    
    //writer
    
    //virtual init
    void init(rd::Lifetime lifetime) const override;
    
    //identify
    void identify(const rd::IIdentities &identities, rd::RdId const &id) const override;
    
    //getters
    rd::RdProperty<bool, rd::Polymorphic<bool>> const & get_boolean_property() const;
    rd::RdProperty<MyScalar, rd::Polymorphic<MyScalar>> const & get_scalar() const;
    rd::RdList<int32_t, rd::Polymorphic<int32_t>> const & get_list() const;
    rd::RdSet<int32_t, rd::Polymorphic<int32_t>> const & get_set() const;
    rd::RdMap<int64_t, std::wstring, rd::Polymorphic<int64_t>, rd::Polymorphic<std::wstring>> const & get_mapLongToString() const;
    rd::RdCall<wchar_t, std::wstring, rd::Polymorphic<wchar_t>, rd::Polymorphic<std::wstring>> const & get_call() const;
    rd::RdEndpoint<std::wstring, int32_t, rd::Polymorphic<std::wstring>, rd::Polymorphic<int32_t>> const & get_callback() const;
    
    //intern
    
    //equals trait
    private:
    bool equals(rd::IPolymorphicSerializable const& object) const;
    
    //equality operators
    public:
    friend bool operator==(const DemoModel &lhs, const DemoModel &rhs);
    friend bool operator!=(const DemoModel &lhs, const DemoModel &rhs);
    
    //hash code trait
    
    //type name trait
};

#pragma warning( pop )


//hash code trait

#endif // DemoModel_H
