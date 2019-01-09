#pragma once
#include <any>
namespace ASGE
{

	class ValueBase
	{
	public:

		virtual ~ValueBase() = default;
		virtual std::any allocate() const = 0;
		virtual void set(std::any object) = 0;
		virtual std::any get() = 0;
	};

	template<typename T>
	class Value : public ValueBase
	{
	public:
		Value() = default;
		~Value() override = default;
		std::any allocate() const override { return T(); }
		std::any get() override { return &data; }
		void set(std::any object) override { data = std::any_cast<T>(object); }

	protected:
		T data;
	};

}