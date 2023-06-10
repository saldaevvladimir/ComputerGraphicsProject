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

	static EngineException IncorrectArgumentType(std::string exceptedType, std::string givenType);

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
	static EngineException IncorrectPropertyKey(const std::string& key);
};

class EntitiesListException : public EngineException
{
public:
	static EngineException IdentifierDoesNotExist(const std::string& identifier);
};

class GameException : public EngineException
{
public:

};

class GameObjectException : public EngineException
{
public:
	static EngineException DoesNotHaveProperty(const std::string& propertyKey);
};

class HyperEllipsoidException : public EngineException
{
public:
	static EngineException IncorrectDimensions(int pointDim, int rayDim, int semiAxesDim);
};

class CanvasException : public EngineException
{
public:
	static EngineException IncorrectSizes(int height, int width);
};
