// 600ce744  FUN_600ce744  size=60 bytes
// --- callers ---
// --- callees ---
//   600cf266 FUN_600cf266


undefined4 FUN_600ce744(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 *puStack_8;
  
  local_10 = param_1;
  uStack_c = param_2;
  puStack_8 = param_3;
  iVar1 = FUN_600cf266(*(undefined4 *)*param_3,param_3[1],&local_10);
  if (iVar1 == 4) {
    uVar2 = 0xfffffffb;
  }
  else if (iVar1 == 0x515) {
    uVar2 = 0xfffffffe;
  }
  else if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


