#pragma once

#include <stdexcept>
#include "serial.h"

class PHYSFSX_short_read : public std::runtime_error
{
public:
	PHYSFSX_short_read(PHYSFS_file *) :
		runtime_error("short read in PHYSFS file")
	{
	}
};

class PHYSFSX_short_write : public std::runtime_error
{
public:
	PHYSFSX_short_write(PHYSFS_file *) :
		runtime_error("short write in PHYSFS file")
	{
	}
};

template <typename T, typename E = PHYSFSX_short_read>
void PHYSFSX_serialize_read(PHYSFS_file *fp, T &t)
{
	const size_t maximum_size = serial::message_type<T>::maximum_size;
	uint8_t buf[maximum_size];
	if (PHYSFS_read(fp, buf, sizeof(buf[0]), maximum_size) != maximum_size)
		throw E(fp);
	serial::reader::bytebuffer_t b(buf);
	serial::process_buffer(b, t);
}

template <typename T, typename E = PHYSFSX_short_write>
void PHYSFSX_serialize_write(PHYSFS_file *fp, T &t)
{
	const size_t maximum_size = serial::message_type<T>::maximum_size;
	uint8_t buf[maximum_size];
	serial::writer::bytebuffer_t b(buf);
	serial::process_buffer(b, t);
	if (PHYSFS_write(fp, buf, sizeof(buf[0]), maximum_size) != maximum_size)
		throw E(fp);
}