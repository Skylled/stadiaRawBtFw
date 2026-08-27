// 60047f70  FUN_60047f70  size=152 bytes
// --- callers ---
//   60047678 queue__60047678
// --- callees ---
//   6004bb1a FUN_6004bb1a
//   6004bb60 FUN_6004bb60


bool FUN_60047f70(int param_1)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  piVar1 = DAT_60048008;
  bVar7 = false;
  if (param_1 != 0) {
    if (*(uint *)(param_1 + 0x2c) < *(uint *)(*DAT_60048008 + 0x2c)) {
      if (-1 < *(int *)(param_1 + 0x18)) {
        *(int *)(param_1 + 0x18) = 0x20 - *(int *)(*DAT_60048008 + 0x2c);
      }
      iVar2 = DAT_6004800c;
      if (*(int *)(param_1 + 0x14) == *(uint *)(param_1 + 0x2c) * 0x14 + DAT_6004800c) {
        iVar4 = FUN_6004bb60(param_1 + 4);
        puVar3 = DAT_60048010;
        if ((iVar4 == 0) && (*(int *)(iVar2 + *(uint *)(param_1 + 0x2c) * 0x14) == 0)) {
          *DAT_60048010 = *DAT_60048010 & ~(1 << (*(uint *)(param_1 + 0x2c) & 0xff));
        }
        uVar5 = *puVar3;
        uVar6 = *(uint *)(*piVar1 + 0x2c);
        *(uint *)(param_1 + 0x2c) = uVar6;
        bVar7 = true;
        *puVar3 = 1 << (uVar6 & 0xff) | uVar5;
        FUN_6004bb1a(uVar6 * 0x14 + iVar2,param_1 + 4);
      }
      else {
        bVar7 = true;
        *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(*piVar1 + 0x2c);
      }
    }
    else {
      bVar7 = *(uint *)(param_1 + 0x50) < *(uint *)(*DAT_60048008 + 0x2c);
    }
  }
  return bVar7;
}


