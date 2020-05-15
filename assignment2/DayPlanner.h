#ifndef DAY_PLANNER_h
#define DAY_PLANNER_H

#include "Deque.h"
#include "Map.h"

class DayPlanner
{
private:
  ds::dn::Map<int, ds::dn::Deque<std::string>*> tasks;
public:
  DayPlanner() {}
  ~DayPlanner() {}

  void AddTask(int hour, std::string taskData) {
    if (hour >= 0 && hour <= 23) {
      if (!tasks.Contains(hour)) {
        tasks.Put(hour, new ds::dn::Deque<std::string>());
        tasks[hour]->InsertFirst(taskData);
      } else {
        tasks[hour]->InsertLast(taskData);
      }
    }
  }

  std::string NextTask() {
    
  }
};


#endif