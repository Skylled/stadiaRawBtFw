// 600d27b4  FUN_600d27b4  size=260 bytes
// --- callers ---
//   60056fa4 FUN_60056fa4
// --- callees ---
//   600d16ae FUN_600d16ae
//   600d1692 FUN_600d1692
//   600d33b2 FUN_600d33b2


undefined4 FUN_600d27b4(int param_1,uint param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24 [2];
  
  FUN_600d1692(*(undefined4 *)(param_1 + 0x3c));
  puVar5 = *(uint **)(param_1 + 0xc);
  if (puVar5 != (uint *)0x0) {
    *(uint *)(param_1 + 0xc) = *puVar5 & 0xffffffe0;
  }
  FUN_600d16ae(*(undefined4 *)(param_1 + 0x3c));
  if (puVar5 == (uint *)0x0) {
    uVar3 = 1;
  }
  else {
    *(uint **)(param_2 + 0x18) = puVar5;
    for (puVar4 = puVar5; puVar4 != puVar5 + 0x10; puVar4 = puVar4 + 1) {
      *puVar4 = 0;
    }
    puVar5[0xc] = param_2;
    *puVar5 = 1;
    puVar5[5] = 1;
    uVar3 = *(undefined4 *)(param_2 + 4);
    puVar5[3] = 1;
    puVar5[4] = 1;
    puVar5[0xf] = 0x14;
    FUN_600d33b2(uVar3,4,&local_2c);
    if (*(char *)(param_2 + 0x14) == '\x03') {
      uVar7 = 0;
    }
    else {
      if (*(ushort *)(param_2 + 10) < 0x10) {
        uVar7 = (uint)*(ushort *)(param_2 + 10) << 0x1c;
      }
      else {
        uVar7 = 0xf0000000;
      }
      if (*(char *)(param_2 + 0x14) == '\0') {
        if (local_2c != 2) {
          uVar7 = uVar7 | 0x8000000;
        }
        uVar7 = uVar7 | 0x4000;
      }
    }
    bVar1 = *(byte *)(param_2 + 0x12);
    uVar2 = *(ushort *)(param_2 + 0xc);
    uVar6 = local_2c << 0xc;
    FUN_600d33b2(*(undefined4 *)(param_2 + 4),1,&local_30);
    puVar5[1] = local_30 | uVar6 | (uint)uVar2 << 0x10 | (uint)bVar1 << 8 | uVar7;
    if (local_2c == 2) {
      uVar7 = (uint)*(byte *)(param_2 + 0x15) << 0x1e;
      FUN_600d33b2(*(undefined4 *)(param_2 + 4),2,local_24);
      FUN_600d33b2(*(undefined4 *)(param_2 + 4),3,&local_28);
    }
    else {
      uVar7 = 0x40000000;
      FUN_600d33b2(*(undefined4 *)(param_2 + 4),5,local_24);
      FUN_600d33b2(*(undefined4 *)(param_2 + 4),6,&local_28);
    }
    uVar3 = 0;
    puVar5[2] = local_24[0] << 0x10 | local_28 << 0x17 | (uint)*(byte *)(param_2 + 0x27) |
                (uint)*(byte *)(param_2 + 0x28) << 8 | uVar7;
  }
  return uVar3;
}


