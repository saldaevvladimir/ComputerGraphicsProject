#pragma once 
#include <exception>
#include <string>
#include <iostream>


class EngineException : public std::exception
{
public:
    EngineException() noexcept;
	EngineException(const std::string& message = "...") noexcept;
	virtual const char* what() const throw();
	virtual ~EngineException() noexcept;

private:
	std::string m_message = "...";
};



class RayException : public EngineException
{
public:

};

class IdentifierException : public EngineException
{
public:

};

class EntityException : public EngineException
{
public:

};

class EntitiesListException : public EngineException
{
public:

};

class GameException : public EngineException
{
public:

};

