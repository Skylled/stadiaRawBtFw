// 600a96d8  FUN_600a96d8  size=730 bytes
// --- callers ---
//   600a9b04 FUN_600a9b04
// --- callees ---
//   600994b8 FUN_600994b8
//   600a30f0 FUN_600a30f0
//   600ff888 FUN_600ff888
//   600a67ec FUN_600a67ec
//   600f0e6e FUN_600f0e6e
//   600a2f3c FUN_600a2f3c
//   600b9358 FUN_600b9358
//   600b89b8 FUN_600b89b8
//   600a6d70 FUN_600a6d70
//   600a59d0 FUN_600a59d0
//   60099bb8 FUN_60099bb8
//   6009a154 FUN_6009a154
//   600a6b20 FUN_600a6b20
//   600f17a4 FUN_600f17a4
//   600a3cd0 FUN_600a3cd0
//   60099dd0 FUN_60099dd0


void FUN_600a96d8(ushort param_1,char param_2,undefined1 *param_3,undefined4 param_4,
                 undefined1 param_5)

{
  uint uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *local_20;
  char local_1b;
  ushort local_1a;
  undefined1 auStack_18 [5];
  undefined1 local_13;
  short local_12;
  
  local_1b = param_2;
  local_1a = param_1;
  switch(param_1) {
  case 0x804:
  case 0x806:
    if ((param_2 != '\0') && (param_3 != (undefined1 *)0x0)) {
      local_12 = (ushort)(byte)param_3[2] * 0x100 + (ushort)(byte)param_3[1];
    }
  case 0x801:
  case 0x803:
  case 0x805:
    FUN_600a3cd0(param_2);
    return;
  }
  if (param_2 == '\0') {
    if ((param_1 & 0xfc00) != 0xfc00) {
      return;
    }
    FUN_600f17a4(&local_1b,param_1,1,param_4);
    return;
  }
  uVar1 = (uint)param_1;
  if (uVar1 == 0x419) {
    FUN_600a30f0(0,0,0,param_2);
    FUN_600a59d0(0,0,local_1b);
    return;
  }
  if (uVar1 < 0x41a) {
    if (uVar1 == 0x405) {
      if (param_3 == (undefined1 *)0x0) {
        return;
      }
      puVar2 = &local_13;
      for (iVar3 = 0; local_20 = param_3 + 1, iVar3 < 6; iVar3 = iVar3 + 1) {
        *puVar2 = *local_20;
        puVar2 = puVar2 + -1;
        param_3 = local_20;
      }
      FUN_600a6d70(auStack_18,0xffff,param_2,0);
      FUN_600b89b8(local_1b,0xffff,auStack_18);
      return;
    }
    if (uVar1 < 0x406) {
      if (uVar1 == 0xd) {
        FUN_6009a154(param_2,0,0);
        return;
      }
      if ((0xc < uVar1) && (uVar1 - 0x401 < 2)) {
        FUN_600a2f3c(param_2,3);
        return;
      }
    }
    else {
      if (uVar1 == 0x413) {
        FUN_600a6b20(0xffff,param_2,0);
        return;
      }
      if (uVar1 == 0x415) {
        if (param_3 == (undefined1 *)0x0) {
          return;
        }
        local_12 = (ushort)(byte)param_3[2] * 0x100 + (ushort)(byte)param_3[1];
        FUN_600994b8(local_12,param_2);
        return;
      }
      if (uVar1 == 0x411) {
        FUN_600a67ec(0xffff,param_2);
        return;
      }
    }
  }
  else if (uVar1 < 0xc74) {
    if (0xc6d < uVar1) {
LAB_600a996c:
      FUN_600ff888(param_1,param_2,param_5);
      return;
    }
    if (uVar1 == 0x80b) {
      if (param_3 == (undefined1 *)0x0) {
        FUN_60099dd0(param_2,0,0xff);
      }
      else {
        puVar2 = &local_13;
        for (iVar3 = 0; local_20 = param_3 + 1, iVar3 < 6; iVar3 = iVar3 + 1) {
          *puVar2 = *local_20;
          puVar2 = puVar2 + -1;
          param_3 = local_20;
        }
        FUN_60099dd0(param_2,auStack_18,0xff);
      }
      FUN_600b9358(0,0xff,0xc);
      return;
    }
    if (uVar1 == 0xc3f) {
      return;
    }
    if (uVar1 == 0x41c) {
      if (param_3 == (undefined1 *)0x0) {
        local_12 = -1;
      }
      else {
        local_12 = (ushort)(byte)param_3[2] * 0x100 + (ushort)(byte)param_3[1];
      }
      FUN_60099bb8(param_2,local_12);
      return;
    }
  }
  else {
    if (uVar1 == 0x200d) {
      FUN_600f0e6e(param_2);
      return;
    }
    if (uVar1 == 0x2014) {
      return;
    }
    if (uVar1 == 0x140c) goto LAB_600a996c;
  }
  if ((param_1 & 0xfc00) == 0xfc00) {
    FUN_600f17a4(&local_1b,param_1,1,param_4);
  }
  return;
}


