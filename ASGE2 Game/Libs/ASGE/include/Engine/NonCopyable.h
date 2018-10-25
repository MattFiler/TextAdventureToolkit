/** 
 * @file
 * @brief Class @ref ASGE::NonCopyable
 */

#pragma once
namespace ASGE {
	/**
	*  @brief a class that can not be copied.
	*  
	*  Classes that inherit this can not be copied. This is used
	*  to ensure that data isn't lost, spliced or multi-managed
	*  by more than instance.
	*/
	class NonCopyable
	{
	protected:
		NonCopyable() = default;
		~NonCopyable() = default;

		NonCopyable(NonCopyable const &) = delete;
		void operator=(NonCopyable const &x) = delete;
	};
}