#pragma once

enum class gameDataType : int
{
	OPTIONAL_DATA,
	REQUIRED_DATA,

	DATA_EXISTS,
	DATA_DOES_NOT_EXIST,
	DATA_IS_NOT_SPECIFIED
};