// 600f35ae  FUN_600f35ae  size=114 bytes
// --- callers ---
//   600aac04 FUN_600aac04
//   600c6d24 FUN_600c6d24
//   600abf08 FUN_600abf08
// --- callees ---
//   600af3f4 FUN_600af3f4
//   600f539c FUN_600f539c


undefined4 FUN_600f35ae(undefined2 param_1,undefined4 param_2,ushort param_3,byte param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600af3f4(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if ((((param_4 & 0x40) == 0) || ((param_3 & 0x180) != 0)) &&
          (((param_3 & 0x180) == 0 || ((param_4 & 0x40) != 0)))) {
    uVar2 = FUN_600f539c(iVar1 + 0x38,param_3,param_4,param_2);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


