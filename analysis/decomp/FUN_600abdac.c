// 600abdac  FUN_600abdac  size=330 bytes
// --- callers ---
//   600f414a FUN_600f414a
//   600f4058 FUN_600f4058
// --- callees ---
//   600f3f50 FUN_600f3f50
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f39fc FUN_600f39fc
//   600ab778 FUN_600ab778


void FUN_600abdac(undefined2 *param_1)

{
  int iVar1;
  undefined1 auStack_284 [2];
  undefined2 local_282;
  undefined2 local_27e;
  undefined1 local_27b;
  undefined2 local_20 [2];
  undefined2 local_1c;
  undefined2 local_c;
  undefined2 local_a;
  
  thunk_EXT_FUN_0000b5ba(local_20,0,0x18);
  thunk_EXT_FUN_0000b5ba(auStack_284,0,0x262);
  switch(*(undefined1 *)(param_1 + 8)) {
  case 2:
    local_c = 1;
    local_a = 0xffff;
    local_20[0] = 2;
    local_1c = 0x1801;
    iVar1 = FUN_600f39fc(*param_1,2,local_20);
    if (iVar1 != 0) {
      FUN_600f3f50(param_1);
    }
    break;
  case 3:
    local_c = 1;
    local_a = param_1[7];
    local_20[0] = 2;
    local_1c = 0x2a05;
    iVar1 = FUN_600f39fc(*param_1,4,local_20);
    if (iVar1 != 0) {
      FUN_600f3f50(param_1);
    }
    break;
  case 4:
    local_c = param_1[6];
    local_a = param_1[7];
    iVar1 = FUN_600f39fc(*param_1,5,local_20);
    if (iVar1 != 0) {
      FUN_600f3f50(param_1);
    }
    break;
  case 5:
    local_282 = param_1[6];
    local_27e = 2;
    local_27b = 2;
    iVar1 = FUN_600ab778(*param_1,2,auStack_284);
    if (iVar1 != 0) {
      FUN_600f3f50(param_1);
    }
  }
  return;
}


