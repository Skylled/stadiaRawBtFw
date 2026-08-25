// 600f539c  FUN_600f539c  size=170 bytes
// --- callers ---
//   600f35ae FUN_600f35ae
// --- callees ---
//   600f56fe FUN_600f56fe
//   600f578e FUN_600f578e
//   600f55a4 FUN_600f55a4


undefined2 FUN_600f539c(undefined4 param_1,undefined2 param_2,undefined1 param_3,undefined4 param_4)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_24 = 2;
  local_20 = 0x2803;
  local_c = FUN_600f55a4(param_1,&local_24,1);
  if (local_c == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_600f578e(param_1,local_c + 4,4);
    if (iVar1 == 0) {
      FUN_600f56fe(param_1,local_c);
      uVar2 = 0;
    }
    else {
      local_10 = FUN_600f55a4(param_1,param_4,param_2);
      if (local_10 == 0) {
        FUN_600f56fe(param_1,local_c);
        uVar2 = 0;
      }
      else {
        **(undefined1 **)(local_c + 4) = param_3;
        *(undefined2 *)(*(int *)(local_c + 4) + 2) = *(undefined2 *)(local_10 + 0xc);
        *(undefined4 *)(local_10 + 4) = 0;
        uVar2 = *(undefined2 *)(local_10 + 0xc);
      }
    }
  }
  return uVar2;
}


