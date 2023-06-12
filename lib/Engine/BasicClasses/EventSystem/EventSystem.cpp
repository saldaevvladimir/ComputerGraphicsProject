#include "EventSystem.h"



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

void EventSystem::Handle(std::string name, std::function<void(std::vector<std::any>)> func)
{
    if (events.find(name) != events.end())
        events[name].push_back(func);
}

void EventSystem::RemoveHandled(std::string name, std::function<void(std::vector<std::any>)> func)
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
            func(args);
}

std::vector<std::function<void(std::vector<std::any>)>> EventSystem::GetHandled(std::string name)
{
    if (events.find(name) != events.end())
        return events[name];

    return {};
}

std::vector<std::function<void(std::vector<std::any>)>> EventSystem::operator [] (std::string name)
{
    return GetHandled(name);
}

bool EventSystem::CompareFunctions(const std::function<void(std::vector<std::any>)>& f1, const std::function<void(std::vector<std::any>)>& f2) 
{
    return (f1.target_type() == f2.target_type() && 
        f1.template target<void(std::vector<std::any>)>() == f2.template target<void(std::vector<std::any>)>());    
}

bool operator == (const std::function<void(std::vector<std::any>)>& func1, const std::function<void(std::vector<std::any>)>& func2)
{
    return EventSystem::CompareFunctions(func1, func2);
}

void EventSystem::operator = (EventSystem es)
{
    this->events = es.events;
}



