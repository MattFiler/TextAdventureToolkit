/** 
 * @file
 * @brief Namespace @ref ASGE::FILEIO, Struct @ref ASGE::FILEIO::IOBuffer, Struct @ref ASGE::FILEIO::File
 */

#pragma once
#include <memory>
#include <string>
#include <vector>

struct PHYSFS_File;
namespace ASGE
{
    /**
    * @namespace ASGE::FILEIO
    * @brief input and output resource management
    */
	namespace FILEIO
	{
		//

		/**
		* @brief buffer for raw data.
		* 
		* A IOBuffer is a simple structure that stores data
		* as bytes along with the number of bytes in use. This can
		* be used whenever raw data is being written or read from
		* files stored locally.
		*/
		struct IOBuffer
		{
			IOBuffer() = default;
			~IOBuffer() = default;
			IOBuffer(const IOBuffer& rhs);
			IOBuffer& operator=(const IOBuffer& rhs);

			std::unique_ptr<char[]> data = nullptr;     /**< The data buffer.
														     The bytes that represent the data being stored are keptPhysFS
					                                         in this unique pointer. It will auto deallocate upon
					                                         destruction, so do not directly link to the data. */

			size_t length = 0;                          /**< Length of buffer.
					                                         The length of the buffer. This needs to be manually set
					                                         when appropriate and updated if the data is recreated. */

			char* as_char() noexcept;                   /**< Buffer as char array.
								                             Returns the buffer as char array. */

			unsigned char* as_unsigned_char() noexcept; /**< Buffer as unsigned char array.
								                             Returns the buffer as an unsigned char array. */

			void* as_void() noexcept;
			void clear() noexcept;
			void append(const char* data, size_t bytes);

			template <typename T>
			void append(T);
		};

		/**
		* @brief a file stored locally
		* 
		* A file can be used to open a resource. It supports reading
		* and writing and provides an abstraction between the low-level
		* IO libraries. Reading from a file will generate an IOBuffer
		* object, which can be used to load resources such as fonts.
		*/
		struct File
		{
		public:
			enum class IOMode
			{
				READ,
				APPEND,
				WRITE
			};

		public:
			File() = default;
			virtual ~File();

			/**
			* Attempts to open a local file.
			* The low-level library will attempt to open the file
			* using the specified IOMode.
			* @param filename The name of the file to open.
			* @param mode The IO mode required.
			* @return True if successful.
			*/
			bool open(const std::string& filename, IOMode mode = IOMode::READ);

			/**
			* Closes the file (if open).
			* Clears the handle pointing to the file/resource if open.
			* @return True if successful.
			*/
			bool close() noexcept;

			/**
			 * Seeks to a new position.
			 * Increments the read position of the file by a user specified
			 * number of bytes.
			 * @param bytes The distance to seek (in bytes).
	         * @return True if successful.
			*/
			bool seek(std::size_t bytes) noexcept;

			/**
 			 * Writes an IOBuffer into the file.
 			 * Using an IOBuffer, it's contents will be directly appended.
			 * @param buffer The data to be written.
			 * @return The number of bytes written.
			*/
			std::size_t write(IOBuffer& buffer) noexcept;

			/**
			 * Reads the contents of the file.
			 * Stores the entire contents of the open file into a buffer.
			 * The buffer stores both the data and its length.
	         * @return The data buffer.
	         * @see IOBuffer
			*/
			IOBuffer read();

		private:
			PHYSFS_File* handle = nullptr; /**< The low-level handle to the file. */
		};
	}
}