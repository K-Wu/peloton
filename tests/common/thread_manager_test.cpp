//===----------------------------------------------------------------------===//
//
//                         PelotonDB
//
// cache_test.cpp
//
// Identification: tests/common/cache_test.cpp
//
// Copyright (c) 201CACHE_SIZE, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "harness.h"
#include "backend/common/thread_manager.h"

namespace peloton {
namespace test {

//===--------------------------------------------------------------------===//
// Thread Manager Test
//===--------------------------------------------------------------------===//

class ThreadManagerTests : public PelotonTest {};

/* this is the old test
TEST_F(ThreadManagerTests, BasicTest) {
  auto& thread_manager = ThreadManager::GetInstance();
  std::shared_ptr<std::thread> t1(new std::thread);
  bool status = thread_manager.AttachThread(t1);
  EXPECT_EQ(status, true);
  status = thread_manager.AttachThread(t1);
  EXPECT_EQ(status, false);
  status = thread_manager.DetachThread(t1);
  EXPECT_EQ(status, true);
  status = thread_manager.DetachThread(t1);
  EXPECT_EQ(status, false);
}
*/

TEST_F(ThreadManagerTests, ThreadMananger) {

  auto& thread_manager1 = ThreadManager::GetInstance();
  auto& thread_manager2 = ThreadManager::GetInstance();

  bool status = (&thread_manager1 == &thread_manager2);
  EXPECT_EQ(status, true);
}

TEST_F(ThreadManagerTests, ThreadPool) {

  auto& thread_pool1 = ThreadPool::GetInstance();
  auto& thread_pool2 = ThreadPool::GetInstance();

  bool status = (&thread_pool1 == &thread_pool2);
  EXPECT_EQ(status, true);
}

}  // End test namespace
}  // End peloton namespace
