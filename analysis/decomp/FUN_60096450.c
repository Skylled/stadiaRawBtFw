// 60096450  FUN_60096450  size=208 bytes
// --- callers ---
//   6009623c FUN_6009623c
// --- callees ---
//   6006dbac FUN_6006dbac
//   6006e154 FUN_6006e154
//   6006e160 FUN_6006e160
//   600d932a FUN_600d932a
//   6006e2d0 FUN_6006e2d0
//   600962dc FUN_600962dc


void FUN_60096450(int *param_1)

{
  uint uVar1;
  undefined2 *puVar2;
  int iVar3;
  int local_c;
  
  uVar1 = FUN_6006e154();
  if (uVar1 < (uint)param_1[4]) {
    local_c = param_1[4];
  }
  else {
    local_c = param_1[4];
  }
  local_c = uVar1 - local_c;
  FUN_600d932a(param_1,(int)((longlong)DAT_60096520 * (longlong)(local_c * 1000) >> 0x26) -
                       (local_c * 1000 >> 0x1f));
  param_1[4] = uVar1;
  while ((*param_1 != 0 && (*(int *)(*param_1 + 0xc) < 1))) {
    iVar3 = *param_1;
    FUN_6006e2d0(param_1,iVar3);
    if (*(int *)(iVar3 + 8) == 0) {
      if (*(short *)(iVar3 + 0x14) != 0) {
        puVar2 = (undefined2 *)FUN_6006dbac(8,DAT_60096524,0x59);
        if (puVar2 != (undefined2 *)0x0) {
          *puVar2 = *(undefined2 *)(iVar3 + 0x14);
          puVar2[3] = 0;
          FUN_600962dc(puVar2);
        }
      }
    }
    else {
      (**(code **)(iVar3 + 8))(iVar3);
    }
  }
  if (*param_1 == 0) {
    FUN_6006e160((char)param_1[5]);
  }
  return;
}


