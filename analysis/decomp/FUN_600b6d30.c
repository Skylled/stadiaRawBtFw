// 600b6d30  FUN_600b6d30  size=540 bytes
// --- callers ---
//   600b5e00 FUN_600b5e00
// --- callees ---
//   600aa3cc FUN_600aa3cc
//   600f9db4 FUN_600f9db4
//   600f9df0 FUN_600f9df0
//   600bc2a0 FUN_600bc2a0
//   600b9408 FUN_600b9408
//   600a3424 FUN_600a3424
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600b720c FUN_600b720c
//   600f832a FUN_600f832a
//   600bc00c FUN_600bc00c
//   600aa340 FUN_600aa340
//   600f9906 FUN_600f9906
//   600f9462 FUN_600f9462
//   600f83a0 FUN_600f83a0
//   600f8f7a FUN_600f8f7a


void FUN_600b6d30(undefined2 *param_1,undefined2 param_2,undefined4 param_3)

{
  undefined1 auStack_2c [8];
  undefined1 local_24;
  undefined1 auStack_20 [8];
  undefined1 local_18;
  char local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined4 local_10;
  undefined2 local_a;
  
  local_a = *param_1;
  switch(param_2) {
  case 3:
    FUN_600bc00c(param_1);
    if (*(int *)(param_1 + 0xaa) != 0) {
      (**(code **)(*(int *)(param_1 + 0xaa) + 0x1c))(local_a,0);
    }
    break;
  case 6:
    if (*(int *)(*(int *)(param_1 + 0xaa) + 0x24) != 0) {
      (**(code **)(*(int *)(param_1 + 0xaa) + 0x24))(*(int *)(param_1 + 0x96) + 4);
    }
    break;
  case 0xe:
    local_11 = *(undefined1 *)(param_1 + 2);
    local_12 = *(undefined1 *)(param_1 + 3);
    *(undefined1 *)(param_1 + 2) = 5;
    *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xfc;
    local_10 = param_3;
    FUN_600aa340(param_1 + 0x9e,3,0x1e);
    local_13 = FUN_600f9df0(param_1,local_10);
    if (local_13 == '\x01') {
      (**(code **)(*(int *)(param_1 + 0xaa) + 0x14))(*param_1,local_10);
    }
    else if (local_13 == '\0') {
      FUN_600aa3cc(param_1 + 0x9e);
      *(undefined1 *)(param_1 + 2) = local_11;
      *(undefined1 *)(param_1 + 3) = local_12;
      FUN_600f9462(param_1,local_10);
    }
    else {
      FUN_600f9db4(param_1);
    }
    break;
  case 0x11:
    local_18 = 0;
    FUN_600a3424(0x80,*(int *)(param_1 + 0x96) + 4,auStack_20);
    *(undefined1 *)(param_1 + 2) = 8;
    FUN_600aa340(param_1 + 0x9e,3,10);
    (**(code **)(*(int *)(param_1 + 0xaa) + 0x1c))(*param_1,1);
    break;
  case 0x14:
    (**(code **)(*(int *)(param_1 + 0xaa) + 0x28))(*param_1,param_3);
    break;
  case 0x18:
    *(undefined1 *)(param_1 + 2) = 5;
    *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xfc;
    FUN_600bc2a0(param_1,param_3);
    FUN_600f8f7a(param_1,param_3);
    FUN_600aa340(param_1 + 0x9e,3,0x1e);
    break;
  case 0x1b:
    thunk_EXT_FUN_0000b5ba(auStack_2c,0,10);
    local_24 = 0;
    FUN_600a3424(0x80,*(int *)(param_1 + 0x96) + 4,auStack_2c);
    FUN_600f9906(param_1);
    *(undefined1 *)(param_1 + 2) = 7;
    FUN_600aa340(param_1 + 0x9e,3,10);
    break;
  case 0x1e:
    FUN_600b720c(param_1,param_3);
    FUN_600b9408(*(undefined4 *)(param_1 + 0x96),0,0);
    break;
  case 0x20:
    if (*(char *)(param_1 + 0x3f) == '\x03') {
      FUN_600f832a(param_1);
    }
    break;
  case 0x22:
    FUN_600f83a0(param_1);
  }
  return;
}


