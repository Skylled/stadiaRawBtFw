// 60069b20  adapter__60069b20  size=210 bytes
// src: adapter.cc
// --- callers ---
// --- callees ---
//   600d3b3a FUN_600d3b3a
//   60050c18 FUN_60050c18
//   600cc984 FUN_600cc984
//   601016f0 FUN_601016f0
//   600d3618 FUN_600d3618
//   6010165c FUN_6010165c
//   600d37ac FUN_600d37ac
//   6006ad00 gatt_server__6006ad00
//   600d8892 FUN_600d8892
//   600d8994 FUN_600d8994
//   60101ba2 FUN_60101ba2
//   600cc8f8 FUN_600cc8f8


/* src: adapter.cc */

void adapter__60069b20(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  byte *pbVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int local_a8;
  int local_a4;
  int iStack_a0;
  
  iVar5 = FUN_600d8994(param_1 + 0x110);
  puVar4 = DAT_60069c04;
  pbVar3 = DAT_60069c00;
  if (iVar5 == 0) {
    FUN_6010165c(0x28,DAT_60069bf8,0x393,DAT_60069bfc,DAT_60069bf4);
  }
  else {
    bVar1 = *DAT_60069c00;
    DataMemoryBarrier(0x1b);
    if (((bVar1 & 1) == 0) && (iVar5 = FUN_600cc8f8(DAT_60069c00), iVar5 != 0)) {
      *puVar4 = bVar1 & 1;
      FUN_600cc984(pbVar3);
    }
    uVar6 = FUN_600d3618();
    uVar2 = DAT_60069bf8;
    if (*puVar4 + 500 <= uVar6) {
      *puVar4 = uVar6;
      FUN_600d3b3a(&local_a8);
      FUN_600d37ac(&local_a8,DAT_60069c08);
      FUN_600d8892(&local_a8,*(undefined2 *)(param_1 + 0x1abc));
      FUN_600d37ac(&local_a8,DAT_60069c0c);
      uVar7 = FUN_60050c18(*(undefined2 *)(param_1 + 0x1abe),0,iStack_a0 + local_a8,
                           local_a4 - iStack_a0);
      FUN_60101ba2(&local_a8,uVar7);
      FUN_601016f0(10,uVar2,0x397,&local_a8);
    }
    gatt_server__6006ad00
              (param_1 + 0x13c,*(undefined2 *)(param_1 + 0x1abc),param_1 + 0x1ac0,
               *(undefined2 *)(param_1 + 0x1abe));
    *(undefined2 *)(param_1 + 0x1abc) = 0;
    *(undefined2 *)(param_1 + 0x1abe) = 0;
  }
  return;
}


