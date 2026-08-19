// 600e0d54  FUN_600e0d54  size=38 bytes
// --- callers ---
//   6005a1b0 device_info__6005a1b0
// --- callees ---
//   60091c10 obj__60091c10


undefined4 FUN_600e0d54(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = obj__60091c10(param_2);
  if (iVar1 != 0) {
    uVar2 = func_0x600e0d0a(param_1,iVar1,param_3,param_4);
    return uVar2;
  }
  return 0xffffffff;
}


