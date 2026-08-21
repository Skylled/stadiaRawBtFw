// 600ecea6  FUN_600ecea6  size=78 bytes
// --- callers ---
//   600ecef4 FUN_600ecef4
// --- callees ---
//   600e093e FUN_600e093e


undefined4 FUN_600ecea6(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 != (int *)0x0) {
    uVar4 = param_1[1] + param_3;
    if (!CARRY4(param_1[1],param_3)) {
      uVar3 = param_1[2];
      if (uVar4 <= uVar3) {
LAB_600ecede:
        if (param_2 != (int *)0x0) {
          *param_2 = *param_1 + param_1[1];
        }
        return 1;
      }
      if ((char)param_1[3] != '\0') {
        uVar2 = uVar3 * 2;
        if ((uVar3 <= uVar2) && (uVar4 < uVar2)) {
          uVar4 = uVar2;
        }
        iVar1 = FUN_600e093e(*param_1,uVar4);
        if (iVar1 != 0) {
          *param_1 = iVar1;
          param_1[2] = uVar4;
          goto LAB_600ecede;
        }
      }
    }
    *(undefined1 *)((int)param_1 + 0xd) = 1;
  }
  return 0;
}


