// smart_buffer.h in Otus homework#7 project

#pragma once
#include "broadcasters.h"
#include <deque>
#include <algorithm>
#include <stdexcept>


template<class T>
class SmartBuffer : public NotificationBroadcaster
{
public:

  SmartBuffer() noexcept(false) {}

  /// Each element in the buffer has the list of recipients.
  /// When a recepient gets an element, it is added to this list.
  /// When all recipients have received this element, we can remove
  /// it from the buffer.
  struct Record
  {
    Record(T newValue) noexcept(false) :
      value{newValue} {}

    T value;
    std::set<std::shared_ptr<NotificationListener>> recipients;
  };

  /// Add new element to the buffer
  void putItem(const T& newItem)
  {
    data.emplace_back(newItem);
    notify();
  }

  /// Add new element to the buffer
  void putItem(T&& newItem)
  {
    data.emplace_back(std::move(newItem));
    notify();
  }  

  /// Each recipient starts looking from the first element in the queue.
  /// When an element is found that wasn't received yet by this recipient,
  /// the recipient gets the value of this element and updates pecipient list
  /// for this element.
  T getItem(const std::shared_ptr<NotificationListener>& recipient = nullptr)
  {
    if (data.empty() == true)
    {
      throw std::out_of_range{"Buffer is empty!"};
    }

    if (nullptr == recipient)
    {
      auto result {data.front().value};
      if (listeners.empty() == true)
      {
        data.pop_front();
      }
      return result;
    }

    auto iter {data.begin()};
    while(iter != data.end() &&
          (iter->recipients.insert(recipient)).second != true)
    {
      ++iter;
    }
    auto result {iter->value};
    if (iter->recipients == listeners)
    {
      data.erase(iter);
    }
    return result;
  }

  /// Get elements count in the queue
  size_t dataSize()
  {
    return data.size();
  }

  /// Clear data
  void clear()
  {
    data.clear();
  }

private:

  std::deque<Record> data;
};

