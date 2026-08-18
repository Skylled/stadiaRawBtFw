// 600d29b8  FUN_600d29b8  size=132 bytes
// --- callers ---
//   60057c78 FUN_60057c78
//   600d2dba FUN_600d2dba
// --- callees ---
//   600d16ae FUN_600d16ae
//   600d2986 FUN_600d2986
//   600d1692 FUN_600d1692
//   600d2762 FUN_600d2762
//   600d2720 FUN_600d2720


undefined4 FUN_600d29b8(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  bool bVar3;
  uint *puVar4;
  uint *puVar5;
  
  puVar5 = *(uint **)(param_2 + 0x18);
  FUN_600d1692(*(undefined4 *)(param_1 + 0x3c));
  if ((-1 < (int)(puVar5[4] << 0x1f)) || (-1 < (int)(puVar5[3] << 0x1f))) {
    if ((*puVar5 & 1) == 0) {
      bVar3 = false;
      if (*(char *)(param_2 + 0x14) != '\x03') {
        FUN_600d2986(*(undefined4 *)(param_1 + 0x28));
        bVar3 = true;
      }
    }
    else {
      bVar3 = false;
    }
    puVar5[3] = 1;
    puVar5[4] = 1;
    puVar5[6] = puVar5[6] & 0xffffff00;
    if (bVar3) {
      FUN_600d2720(param_1);
    }
  }
  puVar4 = (uint *)puVar5[0xd];
  uVar1 = *(undefined4 *)(param_1 + 0x3c);
  puVar5[0xe] = 0;
  puVar5[0xd] = 0;
  FUN_600d16ae(uVar1);
  while (puVar4 != (uint *)0x0) {
    puVar5 = (uint *)*puVar4;
    uVar2 = FUN_600d2762(param_1,puVar4[9],puVar4[10]);
    if (puVar4[2] < uVar2) {
      uVar2 = 0;
    }
    else {
      uVar2 = puVar4[2] - uVar2;
    }
    puVar4[3] = uVar2;
    (*(code *)puVar4[4])(puVar4[5],puVar4,0xe);
    puVar4 = puVar5;
  }
  return 0;
}


