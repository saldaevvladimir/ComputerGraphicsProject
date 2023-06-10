#include "EventSystem.h"


namespace Engine
{
    EventSystem::EventSystem()
    {

    }

    void EventSystem::Add(std::string name)
    {
        events[name] = {};
    }

    void EventSystem::Remove(std::string name)
    {
        events.erase(name);
    }

    void Handle(std::string name, std::function<void(std::vector<std::any>)> func)
    {
        if (events.find(name) != events.end())
            events[name].push_back(func);
    }

    void RemoveHandled(std::string name, std::function<void(std::vector<std::any>)> func)
    {
        if (events.find(name) != events.end())
        {
            for (auto iter = events[name].begin(); iter != events[name].end(); ++iter)
            {
                if (*iter == func)
                {
                    events[name].erase(iter);
                    break;
                }
            }
        }
    }

    void EventSystem::Trigger(std::string name, const std::vector<std::any>& args)
    {
        if (events.find(name) != events.end())
            for (auto& func : events[name])
                func(arg);
    }

    std::vector<std::function<void(std::vector<std::any>)>> GetHandled(std::string name)
    {
        if (events.find(name) != events.end())
            return events[name];

        return {};
    }

    std::vector<std::function<void(std::vector<std::any>)>> operator [] (std::string name)
    {
        return GetHandled(name);
    }
} 

