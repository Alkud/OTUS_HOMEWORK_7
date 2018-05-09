// broadcasters.h in Otus homework#7 project

#pragma once

#include <set>
#include <string>
#include <memory>
#include "listeners.h"


/// Base class for a brodcaster, sending messages,
/// containing instructions for listeners
class MessageBroadcaster
{
public:  
  virtual ~MessageBroadcaster()
  {
    clearMessageListenersList();
  }

  /// Add a new listeners
  virtual void
  addMessageListener(std::shared_ptr<MessageListener> newListener)
  {
    if (newListener != nullptr)
    {
      listeners.insert(newListener);
    }
  }

  /// Remove a listener
  virtual void
  removeMessageListener(std::shared_ptr<MessageListener> listener)
  {
    if (listener != nullptr)
    {
      listeners.erase(listener);
    }
  }

  /// Send instruction to all registered listeners
  virtual void sendMessage(std::string message)
  {
    for (const auto& listener : listeners)
    {
      listener->reactMessage(this, message);
    }
  }

  /// Remove all listenenrs from the list
  virtual void clearMessageListenersList()
  {
    listeners.clear();
  }

protected:
  std::set<std::shared_ptr<MessageListener>> listeners;
};



/// Base class for a brodcaster, acting as a trigger,
/// forcing listeners to take an action
class NotificationBroadcaster
{
public:
  virtual ~NotificationBroadcaster()
  {
    clearNotificationListenersList();
  }

  /// Add a listener to the list
  virtual void
  addNotificationListener(std::shared_ptr<NotificationListener> newListener)
  {
    if (newListener != nullptr)
    {
      listeners.insert(newListener);
    }
  }

  /// Remove a listener from the list
  virtual void
  removeNotificationListener(std::shared_ptr<NotificationListener> listener)
  {
    if (listener != nullptr)
    {
      listeners.erase(listener);
    }
  }

  /// Send notification to all listeners in the list
  virtual void notify()
  {
    for (const auto& listener : listeners)
    {
      listener->reactNotification(this);
    }
  }

  /// Remove alll listenenrs from the list
  virtual void clearNotificationListenersList()
  {
    listeners.clear();
  }

protected:
  std::set<std::shared_ptr<NotificationListener>> listeners;
};
