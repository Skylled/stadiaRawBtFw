// 600d0a90  FUN_600d0a90  size=58 bytes
// --- callers ---
// --- callees ---
//   600d0bc8 FUN_600d0bc8
//   600d1178 FUN_600d1178


undefined4 FUN_600d0a90(undefined4 *param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uStack_1c;
  undefined4 *puStack_18;
  
  uStack_1c = param_2;
  puStack_18 = param_3;
  FUN_600d1178(*param_1,6,(int)&uStack_1c + 3,param_4,param_1);
  if (uStack_1c._3_1_ == '\0') {
    *param_4 = 1;
    bVar1 = *(byte *)(param_2 + 4);
    *param_3 = param_1 + 3;
    *(ushort *)(param_1 + 3) = (ushort)bVar1;
    uVar2 = FUN_600d0bc8(*param_1,0x16);
  }
  else {
    uVar2 = 5;
  }
  return uVar2;
}


