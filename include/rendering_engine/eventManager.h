#pragma once

#include <functional>
#include <vector>
#include <algorithm>

enum class EventType
{
    MouseEvent,
    KeyEvent
};

class Event
{
public:
    Event(EventType eventType) : type(eventType) {}
    virtual ~Event() = default;

    EventType type;
};

class MouseEvent : public Event
{
public:
    int x, y;
    MouseEvent(int x, int y) : x(x), y(y), Event(EventType::MouseEvent) {}
};

class KeyEvent : public Event
{
public:
    int keyCode;
    KeyEvent(int keyCode) : keyCode(keyCode), Event(EventType::KeyEvent) {}
};

using EventHandler = std::function<void(Event *)>;

class EventManager
{
private:
    /* data */
public:
    EventManager(/* args */){};
    virtual ~EventManager() = default;

    void AddListener(EventType eventType, EventHandler handler);
    void RemoveListener(EventType eventType, EventHandler handler);
    void On(EventType eventType, EventHandler handler);
    void Off(EventType eventType, EventHandler handler);
    void DispatchEvent(EventType eventType, Event *event);
    void RemoveAllListener(EventType eventType);

private:
    std::unordered_map<EventType, std::vector<EventHandler>> listeners;
};