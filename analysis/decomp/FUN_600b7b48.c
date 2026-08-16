// 600b7b48  FUN_600b7b48  size=324 bytes
// --- callers ---
//   600b7800 FUN_600b7800
// --- callees ---
//   600f9db4 FUN_600f9db4
//   600b731c FUN_600b731c
//   600d9250 FUN_600d9250
//   600f82c4 FUN_600f82c4
//   6006ddd8 FUN_6006ddd8


undefined4 FUN_600b7b48(undefined2 *param_1,ushort param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined4 uVar4;
  short local_c;
  byte local_9;
  
  if ((((param_2 & 1) == 0) || ((param_2 & 0xc) != 0xc)) || ((param_2 & 0x10) != 0)) {
    bVar1 = (byte)(param_2 >> 8) & 0x3f;
    bVar2 = bVar1 - *(char *)((int)param_1 + 0xb1) & 0x3f;
    if ((ushort)param_1[0x66] < (ushort)bVar2) {
      FUN_600f9db4(param_1);
      uVar4 = 0;
    }
    else {
      *(byte *)((int)param_1 + 0xb1) = bVar1;
      if (bVar2 != 0) {
        *(undefined1 *)(param_1 + 0x5a) = 0;
        local_c = 0;
        for (local_9 = 0; local_9 < bVar2; local_9 = local_9 + 1) {
          uVar3 = (ushort)DAT_600b7c8c & *(ushort *)(*(int *)(param_1 + 0x62) + 6);
          if ((uVar3 == 0) || (uVar3 == 0x8000)) {
            local_c = local_c + 1;
          }
          uVar4 = FUN_600d9250(param_1 + 0x62);
          FUN_6006ddd8(uVar4,DAT_600b7c90,0x3d0);
        }
        if (*(char *)(param_1 + 0x5d) == '\0') {
          FUN_600f82c4(param_1);
        }
        if (((*(int *)(param_1 + 0xaa) != 0) && (*(int *)(*(int *)(param_1 + 0xaa) + 0x30) != 0)) &&
           (local_c != 0)) {
          if ((param_1[0x66] == 0) && (param_1[0x9c] == 0)) {
            local_c = -1;
          }
          (**(code **)(*(int *)(param_1 + 0xaa) + 0x30))(*param_1,local_c);
        }
      }
      if (param_1[0x66] != 0) {
        FUN_600b731c(param_1);
      }
      uVar4 = 1;
    }
  }
  else {
    if (param_1[0x66] != 0) {
      FUN_600b731c(param_1);
    }
    uVar4 = 1;
  }
  return uVar4;
}


