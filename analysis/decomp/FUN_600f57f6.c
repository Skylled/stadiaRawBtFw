// 600f57f6  FUN_600f57f6  size=210 bytes
// --- callers ---
//   600f4e88 FUN_600f4e88
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600f578e FUN_600f578e
//   600af9a0 FUN_600af9a0
//   600f55a4 FUN_600f55a4


undefined1 FUN_600f57f6(undefined4 param_1,short *param_2,char param_3)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined1 local_9;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_24 = 2;
  local_9 = 0;
  if (param_3 == '\0') {
    local_20 = 0x2801;
  }
  else {
    local_20 = 0x2800;
  }
  local_10 = FUN_600f55a4(param_1,&local_24,1);
  if ((local_10 != 0) && (iVar1 = FUN_600f578e(param_1,local_10 + 4,0x14), iVar1 != 0)) {
    if (*param_2 == 2) {
      **(undefined2 **)(local_10 + 4) = 2;
      *(short *)(*(int *)(local_10 + 4) + 4) = param_2[2];
    }
    else if (*param_2 == 4) {
      **(undefined2 **)(local_10 + 4) = 0x10;
      FUN_600af9a0(*(int *)(local_10 + 4) + 4,*(undefined4 *)(param_2 + 2));
    }
    else {
      **(undefined2 **)(local_10 + 4) = 0x10;
      thunk_EXT_FUN_0000b572(*(int *)(local_10 + 4) + 4,param_2 + 2,0x10);
    }
    local_9 = 1;
  }
  return local_9;
}


