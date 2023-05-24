#include "EngineException.h"
#include <string>


EngineException::EngineException() noexcept {};

EngineException::EngineException(const std::string& message) noexcept
{
	m_message = message;
}

const char* EngineException::what() const throw()
{
	return m_message.c_str();
}

EngineException::~EngineException() noexcept {};



