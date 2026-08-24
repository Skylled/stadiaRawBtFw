// 600ef7f8  FUN_600ef7f8  size=168 bytes
// --- callers ---
//   600fdab8 FUN_600fdab8
//   600fd9c2 FUN_600fd9c2
//   600fd9f4 FUN_600fd9f4
//   600fd83a FUN_600fd83a
//   600fdcfc FUN_600fdcfc
// --- callees ---
//   600efcc6 FUN_600efcc6
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600ef7f8(int *param_1,undefined1 param_2,undefined4 param_3,undefined2 param_4,
                 undefined1 param_5,undefined2 param_6)

{
  undefined1 local_2c0 [2];
  undefined2 local_2be;
  undefined1 local_2bc;
  undefined1 auStack_2bb [6];
  undefined1 local_2b5;
  undefined2 local_2b4;
  
  if (*param_1 != 0) {
    thunk_EXT_FUN_0000b5ba(local_2c0,0,0x2b0);
    local_2bc = *(undefined1 *)((int)param_1 + 5);
    local_2b5 = param_5;
    local_2b4 = param_6;
    local_2c0[0] = param_2;
    local_2be = param_4;
    FUN_600efcc6(auStack_2bb,param_3);
    (*(code *)*param_1)(2,local_2c0);
  }
  return;
}


