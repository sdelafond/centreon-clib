/*
** Copyright 2011-2013 Centreon
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
**
** For more information : contact@centreon.com
*/

#include <iostream>
#include "com/centreon/exceptions/basic.hh"
#include "com/centreon/timestamp.hh"

using namespace com::centreon;

/**
 *  Check the timestamp to milliseconds.
 *
 *  @return 0 on success.
 */
int main() {
  try {
    timestamp t1(1, 42);
    if (t1.to_mseconds() != 1000)
      throw (basic_error() << "to_msecond failed");

    timestamp t2(-1, 0);
    if (t2.to_mseconds() != -1000)
      throw (basic_error() << "to_msecond failed");

    timestamp t3(0, -42);
    if (t3.to_mseconds() != -1)
      throw (basic_error() << "to_msecond failed");

    timestamp t4(-1, -42);
    if (t4.to_mseconds() != -1001)
      throw (basic_error() << "to_msecond failed");

    timestamp t5(1, -42);
    if (t5.to_mseconds() != 999)
      throw (basic_error() << "to_msecond failed");
  }
  catch (std::exception const& e) {
    std::cerr << "error: " << e.what() << std::endl;
    return (1);
  }
  return (0);
}
