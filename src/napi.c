#include <node_api.h>
#include <first_mode.h>
#include <utils.h>


napi_value first_mode_fn(napi_env env, napi_callback_info info) {
  napi_value napi_result;
  char *result = first_mode();
  napi_create_string_utf8(env, result, -1, &napi_result);
  return napi_result;
}

napi_value pwd_fn(napi_env env, napi_callback_info info) {
  napi_value napi_result;
  char *result = pwd();
  napi_create_string_utf8(env, result, -1, &napi_result);
  return napi_result;
}

napi_value ls_fn(napi_env env, napi_callback_info info) {
  napi_value napi_result;
  char *result = ls();
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
//  char *path="/home/new.fs";

  char PathName[4];
  size_t pathResult;
  napi_get_value_string_utf8(env, argv[0], &PathName, 4, &pathResult);
  napi_value napi_result;
  int result = openFileSystem(pathResult);
  napi_create_int32(env, result, &napi_result);
  return napi_result;
}

napi_value cd_fn(napi_env env, napi_callback_info info) {
  napi_value argv[1];
  char *path="test";
  napi_value napi_result;
  char *result = cd(path);
  napi_create_string_utf8(env, result, -1, &napi_result);
  return napi_result;
}



napi_value Init(napi_env env, napi_value exports) {
  napi_value first_mode;
  napi_create_function(env, NULL, 0, first_mode_fn, NULL, &first_mode);
  napi_set_named_property(env, exports, "first_mode", first_mode);

  napi_value pwd;
  napi_create_function(env, NULL, 0, pwd_fn, NULL, &pwd);
  napi_set_named_property(env, exports, "pwd", pwd);

  napi_value ls;
  napi_create_function(env, NULL, 0, ls_fn, NULL, &ls);
  napi_set_named_property(env, exports, "ls", ls);

  napi_value cd;
  napi_create_function(env, NULL, 0, cd_fn, NULL, &cd);
  napi_set_named_property(env, exports, "cd", cd);

  napi_value open_file_system;
  napi_create_function(env, NULL, 0, open_file_system_fn, NULL, &open_file_system);
  napi_set_named_property(env, exports, "open_file_system", open_file_system);

  napi_value close_file_system;
  napi_create_function(env, NULL, 0, close_file_system_fn, NULL, &close_file_system);
  napi_set_named_property(env, exports, "close_file_system", close_file_system);

  return exports;
}


NAPI_MODULE(native, Init)