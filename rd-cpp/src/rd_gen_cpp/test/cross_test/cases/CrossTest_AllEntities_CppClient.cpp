#define NOMINMAX

#include "CrossTestClientBase.h"
#include "CrossTest_AllEntities.h"

#include "DemoModel/DemoModel.Generated.h"
#include "ExtModel/ExtModel.Generated.h"
#include "DemoModel/Derived.Generated.h"
#include "DemoModel/ConstUtil.Generated.h"
#include "DemoModel/MyEnum.Generated.h"
#include "DemoModel/Flags.Generated.h"
#include "DemoModel/ComplicatedPair.Generated.h"

#include "lifetime/Lifetime.h"
#include "wire/SocketWire.h"
#include "scheduler/SimpleScheduler.h"
#include "wire/WireUtil.h"

#include <cstdint>
#include <string>
#include <future>

using namespace rd;
using namespace demo;

namespace rd
{
namespace cross
{
class CrossTestClientAllEntities : public CrossTestClientBase
{
protected:
	int run() override
	{
		DemoModel model;

		scheduler.queue([&]() mutable {
			model.connect(model_lifetime, protocol.get());
			ExtModel const& extModel = ExtModel::getOrCreateExtensionOf(model);

			CrossTestAllEntities::fireAll(model, extModel);
		});

		terminate();
		return 0;
	}
};
}	 // namespace cross
}	 // namespace rd

int main(int argc, char** argv)
{
	rd::cross::CrossTestClientAllEntities test;
	return test.main(argc, argv, "CrossTestClientAllEntities");
}

static_assert(DemoModel::const_toplevel, "const_toplevel value is wrong");
static_assert(ConstUtil::const_enum == MyEnum::default_, "const _enum value is wrong");
//	static_assert(MyScalar::const_string == L"const_string_value", "const_string value is wrong");
//  std::char_traits::compare is not constexpr until C++17 at least in Clang
static_assert(Base::const_base == 'B', "const_base value is wrong");
