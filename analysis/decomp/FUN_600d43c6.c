// 600d43c6  FUN_600d43c6  size=70 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined4 FUN_600d43c6(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_28 [28];
  
  uVar2 = *(uint *)(param_1 + 4);
  if ((*(char *)(uVar2 + 0x1e) == '\0') &&
     (uVar2 = (uint)*(ushort *)(uVar2 + 0x1c), param_3 < uVar2)) {
    uVar1 = 3;
  }
  else {
    uVar3 = param_3;
    if (0x13 < param_3) {
      uVar3 = 0x14;
    }
    thunk_EXT_FUN_0000b572(auStack_28,param_2,uVar3,uVar2,param_2,param_3);
    uVar1 = *(undefined4 *)(param_1 + 0x38);
    auStack_28[uVar3] = 0;
    uVar1 = (**(code **)(param_1 + 0x34))(uVar1,auStack_28);
  }
  return uVar1;
}


