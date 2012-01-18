// The Firmament project
// Copyright (c) 2011-2012 Malte Schwarzkopf <malte.schwarzkopf@cl.cam.ac.uk>
//
// Common resource functionality and data structures.
// TODO(malte): Refactor this to become more shallow and introduce a separate
//              interface class.

#ifndef FIRMAMENT_BASE_RESOURCE_H
#define FIRMAMENT_BASE_RESOURCE_H

#include "base/common.h"
#include "base/task.h"
#include "base/ensemble.h"

namespace firmament {

// Forward-declaration to break cyclic dependency.
class Ensemble;

class Resource {
 public:
  Resource(const string& name, uint32_t task_capacity);
  bool RunTask(Task *task);
  bool JoinEnsemble(Ensemble *ensemble);
  void TaskExited();

  double next_available() { return next_available_; }
  void set_next_available(double next_available) {
    next_available_ = next_available;
  }

  const string& name() { return name_; }
  bool busy() const { return busy_; }
  void set_busy(bool b) { busy_ = b; }
 private:
  string name_;
  uint64_t task_capacity_;
  Ensemble *current_ensemble_;
  Task *current_task_;
  double next_available_;
  bool busy_;
};

}  // namespace firmament

#endif  // FIRMAMENT_BASE_RESOURCE_H
