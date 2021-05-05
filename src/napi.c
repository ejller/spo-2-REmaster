#include <node_api.h>
#include <first_mode.h>
#include <utils.h>


napi_value first_mode_fn(napi_env env, napi_callback_info info) {
  napi_value napi_result;
  char *result = first_mode();
  napi_create_string_utf8(env, result, -1, &napi_result);
  return napi_result;
}


napi_value close_file_system_fn(napi_env env, napi_callback_info info) {
  napi_value napi_result;
  int result = closeFileSystem();
  napi_create_int32(env, result, &napi_result);
  return napi_result;
}

napi_value open_file_system_fn(napi_env env, napi_callback_info info) {
  napi_value argv[1];
  char *path="/home/spo/test.fs";
  napi_value napi_result;
  int result = openFileSystem(path);
  napi_create_int32(env, result, &napi_result);
  return napi_result;
}

napi_value MyFunction2(napi_env env, napi_callback_info info) {
  size_t argc = 1;
  int number = 0;
  napi_value argv[1];
  napi_get_cb_info(env, info, &argc, argv, NULL, NULL);

  napi_get_value_int32(env, argv[0], &number);

  napi_value myNumber;
  number = number * 3;
//  napi_create_int32(env, number, &myNumber);

  return myNumber;
}

napi_value Init(napi_env env, napi_value exports) {
  napi_value first_mode;
  napi_create_function(env, NULL, 0, first_mode_fn, NULL, &first_mode);
  napi_set_named_property(env, exports, "first_mode", first_mode);


  napi_value open_file_system;
  napi_create_function(env, NULL, 0, open_file_system_fn, NULL, &open_file_system);
  napi_set_named_property(env, exports, "open_file_system", open_file_system);

  napi_value close_file_system;
  napi_create_function(env, NULL, 0, close_file_system_fn, NULL, &close_file_system);
  napi_set_named_property(env, exports, "close_file_system", close_file_system);

  napi_value fn2;
  napi_create_function(env, NULL, 0, MyFunction2, NULL, &fn2);
  napi_set_named_property(env, exports, "my_function2", fn2);

  return exports;
}


NAPI_MODULE(native, Init)