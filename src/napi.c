#include <node_api.h>


napi_value MyFunction1(napi_env env, napi_callback_info info) {
  size_t argc = 1;
  int number = 0;
  napi_value argv[1];
  napi_get_cb_info(env, info, &argc, argv, NULL, NULL);

  napi_get_value_int32(env, argv[0], &number);

  napi_value myNumber;
  number = number * 2;
  napi_create_int32(env, number, &myNumber);

  return myNumber;
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
  napi_value fn1;
  napi_create_function(env, NULL, 0, MyFunction1, NULL, &fn1);
  napi_set_named_property(env, exports, "my_function1", fn1);

  napi_value fn2;
  napi_create_function(env, NULL, 0, MyFunction2, NULL, &fn2);
  napi_set_named_property(env, exports, "my_function2", fn2);

  return exports;
}


NAPI_MODULE(native, Init)