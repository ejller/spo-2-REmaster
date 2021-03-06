#include <node_api.h>
#include <first_mode.h>
#include <utils.h>

#define INPUT_SIZE 256

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
  napi_status status;
  size_t argc = 1;
  napi_value argv[1];
  napi_get_cb_info(env, info, &argc, argv, NULL, NULL);
  char path[INPUT_SIZE];
  size_t pathResult;
  napi_get_value_string_utf8(env, argv[0], path, INPUT_SIZE, &pathResult);
  napi_value napi_result;
  int result = openFileSystem(path);
  napi_create_int32(env, result, &napi_result);
  return napi_result;
}

napi_value cd_fn(napi_env env, napi_callback_info info) {
  napi_status status;
  size_t argc = 1;
  napi_value argv[1];
  napi_get_cb_info(env, info, &argc, argv, NULL, NULL);
  char path[INPUT_SIZE];
  size_t pathResult;
  napi_get_value_string_utf8(env, argv[0], path, INPUT_SIZE, &pathResult);
  napi_value napi_result;
  char *result = cd(path);
  napi_create_string_utf8(env, result, -1, &napi_result);
  return napi_result;
}

napi_value cp_fn(napi_env env, napi_callback_info info) {
  napi_status status;
  size_t argc = 2;
  napi_value argv[2];
  napi_get_cb_info(env, info, &argc, argv, NULL, NULL);
  char path1[INPUT_SIZE];
  char path2[INPUT_SIZE];
  size_t path1Result;
  size_t path2Result;
  napi_get_value_string_utf8(env, argv[0], path1, INPUT_SIZE, &path1Result);
  napi_get_value_string_utf8(env, argv[1], path2, INPUT_SIZE, &path2Result);
  napi_value napi_result;
  char *result = cp(path1, path2);
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

  napi_value cp;
  napi_create_function(env, NULL, 0, cp_fn, NULL, &cp);
  napi_set_named_property(env, exports, "cp", cp);

  napi_value open_file_system;
  napi_create_function(env, NULL, 0, open_file_system_fn, NULL, &open_file_system);
  napi_set_named_property(env, exports, "open_file_system", open_file_system);

  napi_value close_file_system;
  napi_create_function(env, NULL, 0, close_file_system_fn, NULL, &close_file_system);
  napi_set_named_property(env, exports, "close_file_system", close_file_system);

  return exports;
}


NAPI_MODULE(native, Init)