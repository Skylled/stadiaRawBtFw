// 600e05bc  FUN_600e05bc  size=144 bytes
// --- callers ---
//   60086508 FUN_60086508
//   60091ddc FUN_60091ddc
//   6008fa18 tasn_dec__6008fa18
// --- callees ---
//   600e093e FUN_600e093e
//   6013d208 thunk_EXT_FUN_0000ac5e
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600e092c FUN_600e092c
//   6004cb28 FUN_6004cb28
//   600e04f4 FUN_600e04f4


void FUN_600e05bc(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int local_c [3];
  
  local_c[0] = param_2;
  local_c[1] = param_3;
  local_c[2] = param_4;
  iVar1 = FUN_600e092c(0x51);
  if (iVar1 != 0) {
    uVar7 = 0x50;
    uVar4 = 0;
    for (iVar5 = 0; param_1 != iVar5; iVar5 = iVar5 + 1) {
      iVar8 = local_c[iVar5];
      uVar6 = uVar4;
      if (iVar8 != 0) {
        iVar2 = FUN_6004cb28(iVar8);
        uVar6 = iVar2 + uVar4;
        iVar3 = iVar1;
        if (uVar7 < uVar6) {
          if (0xffffffea < uVar7) {
LAB_600e0610:
            thunk_EXT_FUN_0000ac5e(iVar1);
            return;
          }
          uVar7 = uVar6 + 0x14;
          iVar3 = FUN_600e093e(iVar1,uVar6 + 0x15);
          if (iVar3 == 0) goto LAB_600e0610;
        }
        iVar1 = iVar3;
        if (iVar2 != 0) {
          thunk_EXT_FUN_0000b572(iVar3 + uVar4,iVar8);
        }
      }
      uVar4 = uVar6;
    }
    *(undefined1 *)(iVar1 + uVar4) = 0;
    FUN_600e04f4(iVar1);
  }
  return;
}


