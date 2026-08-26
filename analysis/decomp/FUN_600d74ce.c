// 600d74ce  FUN_600d74ce  size=30 bytes
// --- callers ---
//   600db5a8 FUN_600db5a8
// --- callees ---
//   600d74b0 FUN_600d74b0
//   60066284 keys__60066284


undefined4 FUN_600d74ce(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  uStack_14 = param_2;
  local_10 = param_3;
  uStack_c = param_4;
  iVar1 = FUN_600d74b0();
  if (iVar1 == 0x43) {
    local_10 = 0;
  }
  else {
    keys__60066284(&uStack_14,iVar1);
  }
  return local_10;
}


