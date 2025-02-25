/*
 * Copyright 2022 Google LLC

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at

 *      http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/
/* A sample target program under test,
 * the sand program will be injected into its shell command */

#include <stdlib.h>
#include <string>
#include <iostream>

extern "C" int LLVMFuzzerTestOneInput(char* data, size_t size) {
  std::string str(data, size);
  std::cout << "INPUT" << str << std::endl;
  system(str.c_str());
  return 0;
}
