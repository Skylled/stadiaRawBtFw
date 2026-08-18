// 600d09c4  FUN_600d09c4  size=138 bytes
// --- callers ---
// --- callees ---
//   600d1178 FUN_600d1178


undefined4 FUN_600d09c4(undefined4 *param_1,byte *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  byte bVar2;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined4 *puStack_20;
  
  uStack_28 = param_1;
  local_24 = param_2;
  puStack_20 = param_3;
  FUN_600d1178(*param_1,6,(int)&uStack_28 + 3);
  if (1 < uStack_28._3_1_) {
    return 5;
  }
  bVar2 = *param_2 & 0x1f;
  if ((*param_2 & 0x1f) == 0) {
    uVar1 = FUN_600d1178(*param_1,4,param_1 + 3);
    *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) & 3;
  }
  else {
    if (bVar2 != 1) {
      if (bVar2 == 2) {
        local_24 = (byte *)CONCAT31(local_24._1_3_,(char)*(undefined2 *)(param_2 + 4));
        local_24 = (byte *)((uint)local_24 & 0xffff);
        uVar1 = FUN_600d1178(*param_1,5,&local_24);
        *(ushort *)(param_1 + 3) = local_24._2_2_ & 3;
        *param_4 = 2;
      }
      else {
        uVar1 = 5;
      }
      goto LAB_600d0a08;
    }
    uVar1 = 0;
    *(undefined2 *)(param_1 + 3) = 0;
  }
  *param_4 = 2;
LAB_600d0a08:
  *param_3 = param_1 + 3;
  return uVar1;
}


