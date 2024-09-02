#include "rendering_engine/eventManager.h"

void EventManager::AddListener(EventType eventType, EventHandler handler)
{
    listeners[eventType].push_back(handler);
}

void EventManager::RemoveListener(EventType eventType, EventHandler handler)
{
    auto &handlers = listeners[eventType];
    handlers.erase(std::remove_if(handlers.begin(), handlers.end(),
                                  [&handler](const EventHandler &eh)
                                  {
                                      return eh.target_type() == handler.target_type() &&
                                             *eh.target<void(Event *)>() == *handler.target<void(Event *)>();
                                  }),
                   handlers.end());
}

void EventManager::On(EventType eventType, EventHandler handler)
{
    AddListener(eventType, handler);
}

void EventManager::Off(EventType eventType, EventHandler handler)
{
    RemoveListener(eventType, handler);
}

void EventManager::DispatchEvent(EventType eventType, Event *event)
{
    auto &handlers = listeners[eventType];
    for (auto &handler : handlers)
    {
        handler(event);
    }
}

void EventManager::RemoveAllListener(EventType eventType)
{
    auto it = listeners.find(eventType);

    // 如果找到对应的事件类型
    if (it != listeners.end())
    {
        // 获取到该事件类型的监听器集合
        auto &handlers = it->second;

        // 清空该监听器集合中的所有监听器
        handlers.clear();
    }
}
